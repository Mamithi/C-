#include<iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    VideoCapture cap("../video/myvideo.avi");

    if(cap.isOpened() == false) {
        cout << "Cannot open the video file" << endl;
        cin.get();
        return -1;
    }

    //Defining window names
    String windowNameOriginalVideo = "Original Video";
    String windowNameBrightnessHigh50 = "Brightness increased by 50";
    String windowNameBrightnessHigh100 = "Brightness increased by 100";
    String windowNameBrightnessLow50 = "Brightness decreased by 50";
    String windowNameBrightnessLow100 = "Brightness decreased by 100";

    // Create and open windows for above window names
    namedWindow(windowNameOriginalVideo, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessHigh50, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessHigh100, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow50, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow100, WINDOW_NORMAL);

    while(true) {
        Mat frame;

        bool bSuccess = cap.read(frame);

        if(bSuccess == false) {
            cout << "Found the end of the video" << endl;
            break;
        }

        Mat frameBrightnessHigh50;
        frame.convertTo(frameBrightnessHigh50, -1, 1, 50);

        Mat frameBrightnessHigh100;
        frame.convertTo(frameBrightnessHigh100, -1, 1, 100);

        Mat frameBrightnessLow50;
        frame.convertTo(frameBrightnessLow50, -1, 1, -50);

        Mat frameBrightnessLow100;
        frame.convertTo(frameBrightnessLow100, -1, 1, -100);

        // Show above frames inside the created windows
        imshow(windowNameOriginalVideo, frame);
        imshow(windowNameBrightnessHigh50, frameBrightnessHigh50);
        imshow(windowNameBrightnessHigh100, frameBrightnessHigh100);
        imshow(windowNameBrightnessLow50, frameBrightnessLow50);
        imshow(windowNameBrightnessLow100, frameBrightnessLow100);


        if(waitKey(10) == 27) {
            cout << "Esc key is pressed by user. STopping the video" << endl;
            break;
        }
    }

    return 0;
}