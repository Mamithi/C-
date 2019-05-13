#include <iostream>
#include <stdlib.h>
#include <zconf.h>

#include <assert.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_mutex.h"

#include "vlc/vlc.h"

#define WIDTH 640
#define HEIGHT 480

#define VIDEOWIDTH 640
#define VIDEOHEIGHT 480

using namespace std;

struct context {
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_mutex *mutex;
    int n;
};

// Vlc prepares to render a video frame
static void *lock(void *data, void **p_pixels) {
    struct context *c = (context *) data;

    int pitch;
    SDL_LockMutex(c->mutex);
    SDL_LockTexture(c->texture, NULL, p_pixels, &pitch);

    return NULL;
}

// VLC just rendered a video frame
static void unlock(void *data, void *id, void *const *p_pixels) {
    struct context *c = (context *) data;

    uint16_t *pixels = (uint16_t *) *p_pixels;

    int x, y;
    for (y = 10; y < 40; y++) {
        for (x = 10; x < 40; x++) {
            if (x < 13 || y < 13 || x > 36 || y > 36) {
                pixels[y * VIDEOWIDTH + x] = 0xffff;
            } else {
                pixels[y * VIDEOWIDTH + x] = 0x02ff;
            }
        }
    }
    SDL_UnlockTexture(c->texture);
    SDL_UnlockMutex(c->mutex);
}

// VLC wants to display a video frame
static void display(void *data, void *id) {
    struct context *c = (context *) data;

    SDL_Rect rect;
    rect.w = VIDEOWIDTH;
    rect.h = VIDEOHEIGHT;
    rect.x = (int) ((1. + .5 * sin(0.03 * c->n)) * (WIDTH - VIDEOWIDTH) / 2);
    rect.y = (int) ((1. + .5 * cos(0.03 * c->n)) * (HEIGHT - VIDEOHEIGHT) / 2);

    SDL_SetRenderDrawColor(c->renderer, 0, 80, 0, 255);
    SDL_RenderClear(c->renderer);
    SDL_RenderCopy(c->renderer, c->texture, NULL, &rect);
    SDL_RenderPresent(c->renderer);
}

static void quit(int c) {
    SDL_Quit();
    exit(c);
}


int main(int argc, char **argv) {


    libvlc_instance_t *libvlc;
    libvlc_media_t *m;
    libvlc_media_player_t *mp;
    char const *vlc_argv[] = {
            "--no-audio",
            "--no-xlib",

            // Apply a video filter
            "--video-filter", "sepia",
            "--sepia-intensity=1"
    };

    int vlc_argc = sizeof(vlc_argv) / sizeof(*vlc_argv);

    SDL_Event event;
    int done = 0, action = 0, pause = 0, n = 0;

    struct context context;

    if (argc < 2) {
        cout << "Usage: " << argv[0] << "<filename>" << endl;
    }

    // Initialise libsdl
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Could not initialize SDL: " << SDL_GetError() << endl;
        return EXIT_FAILURE;
    }

    // Create SDL graphics objects
    SDL_Window *window = SDL_CreateWindow(
            "Sweet Caroline",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            WIDTH, HEIGHT,
            SDL_WINDOW_SHOWN | SDL_WINDOW_MINIMIZED);
    if (!window) {
        cerr << "Couldn't create window" << SDL_GetError() << endl;
        quit(3);
    }

    context.renderer = SDL_CreateRenderer(window, -1, 0);
    if (!context.renderer) {
        cerr << "Couldn't create renderer" << SDL_GetError() << endl;
        quit(4);
    }

    context.texture = SDL_CreateTexture(
            context.renderer,
            SDL_PIXELFORMAT_BGR565, SDL_TEXTUREACCESS_STREAMING,
            VIDEOWIDTH, VIDEOHEIGHT);

    if(!context.texture) {
        cerr << "Couldnt create texture" << SDL_GetError() << endl;
        quit(5);
    }

    context.mutex = SDL_CreateMutex();

    cout <<"VLC_PLUGIN_PATH" << getenv("VLC_PLUGIN_PATH") << endl;


    // Load the VLC engine
    libvlc = libvlc_new(0, NULL);
//    libvlc = libvlc_new(vlc_argc, vlc_argv);

    if (libvlc == NULL) {
        cout << "There was an error initializing VLC" << endl;
        exit(1);
    } else {
        cout << "VLC initialized successfully" << endl;
    }


//    media = libvlc_media_new_location(my_instance, "/home/geo/Desktop/song.mp3");
    m = libvlc_media_new_path(libvlc, "../songs/song1.mkv");
//    m = libvlc_media_new_path(libvlc, "./songs/song1.mkv");
//    m = libvlc_media_new_path(libvlc, argv[1]);

    // Create a player
    mp = libvlc_media_player_new_from_media(m);

    libvlc_media_release(m);

    libvlc_video_set_callbacks(mp, lock, unlock, display, &context);
    libvlc_video_set_format(mp, "RV16", VIDEOWIDTH, VIDEOHEIGHT, VIDEOWIDTH * 2);



    // Start playing
    libvlc_media_player_play(mp);

    while (!done) {
        action = 0;


        // Keys: enter (fullscreen), space (pause). escape (quit)
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    done = 1;
                    break;
                case SDL_KEYDOWN:
                    action = event.key.keysym.sym;
                    break;
            }
        }

        switch(action) {
            case SDLK_ESCAPE:
            case SDLK_q:
                done = 1;
                break;
            case ' ':
                cout << "Pause toggle" << endl;
                pause = !pause;
                break;
        }

        if(!pause) {
            context.n++;
        }

        SDL_Delay(1000/1);
    }

    // Stop stream and clean up libVLC
    libvlc_media_player_stop(mp);
    libvlc_media_player_release(mp);
    libvlc_release(libvlc);

    // Close window and clean up libSDL
    SDL_DestroyMutex(context.mutex);
    SDL_DestroyRenderer(context.renderer);

    quit(0);


    return 0;
}