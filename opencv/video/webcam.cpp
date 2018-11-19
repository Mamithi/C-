#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    // Open the default video camera
    VideoCapture cap(0);

    // if not successful, exit the program
    if(cap.isOpened() == false) {
        cout << "Cannot open the video camera" << endl;
        cin.get();
        return -1;
    }

    double dWidth = cap.get(CAP_PROP_FRAME_WIDTH); // get the width of frames of teh video
    double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); // get the height of frames of teh video

    cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;

    string windowName = "My Camera Feed";

    namedWindow(windowName, WINDOW_NORMAL);

    while(true) {
        Mat frame;
        bool bSuccess = cap.read(frame);

        if(bSuccess == false) {
            cout << "Video camera is disconnected" << endl;
            cin.get();
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
