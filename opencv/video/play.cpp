#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    VideoCapture cap("./sample.mp4"); // Open the video file for reading

    if(cap.isOpened() == false){
        cout << "Cannot open the video file" << endl;
        cin.get();
        return -1;
    }

    // cap.set(CAP_PROP_POS_MSEC, 300);

    // get teh frames rate of the video
    double fps = cap.get(CAP_PROP_FPS);
    cout << "Frames per second : " << fps << endl;

    String windowName = "My First Video";

    namedWindow(windowName, WINDOW_NORMAL); // Create window

    while(true) {
        Mat frame;
        bool bSuccess  = cap.read(frame); // Rea a new frame from video

        // Breaking the while loop at the end of teh video
        if(bSuccess == false) {
            cout << "Found the end of the video" << endl;
            break;
        }

        imshow(windowName, frame);

        if(waitKey(10) == 27) {
            cout << "Esc key is pressed by user. Stopping the video" << endl;
            break;
        }
    }

    return 0;

}