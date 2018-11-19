#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    // Open the default video camera
    VideoCapture cap(0);

    if(cap.isOpened() == false) {
        cout << "Cannot open the video camera" << endl;
        cin.get();
        return -1;
    }

    int frameWidth = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH)); // get the width of frames of the video
    int frameHeight = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT)); // get the height of frames of the video

    Size frameSize(frameWidth, frameHeight);
    int framesPerSecond = 10;

    // Create and intialize the VideoWriter Object
    VideoWriter oVideoWriter("./myvideo.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'),
                                framesPerSecond, frameSize, true);

    
    // if the videowriter object is not intialized successfully, exit the program
    if(oVideoWriter.isOpened() == false) {
        cout << "Cannot save the video to a file" << endl;
        cin.get();
        return -1;
    }

    String windowName = "My Camera Feed";
    namedWindow(windowName);
    while(true) {
        Mat frame;
        bool isSuccess = cap.read(frame);

        // Breaking teh while loop if frames cannot be read from the camera
        if(isSuccess == false) {
            cout << "Video camera is disconnected" << endl;
            cin.get();
            break;
        }

        /*
        Make changes to the frame as necessary
        e.g.
            1. Change brightness/contrasy of the image
            2. Smooth/bluur image
            3. Crop the image
            4. Rotate the image
            5. Draw shapes on the image
        */

       // Write teh video frame to the file
       oVideoWriter.write(frame);

       // show the frame in the created window
       imshow(windowName, frame);

       // Wait for 10ms until any key is pressed
       // If 'Esc' key is pressed, break the while loop
       // If any other key is pressed, continue the loop
       // If ay key is not pressed within 10ms continue the loop

       if(waitKey(10) == 27) {
           cout << "Esc key is pressed by the user. STopping the video" << endl;
           break;
       }       
    }

     oVideoWriter.release();

     return 0;

}
