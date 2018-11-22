#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    VideoCapture cap("../video/sample.mp4");

    if(cap.isOpened() == false) {
        cout << "Cannot open video file" << endl;
        cin.get();
        return -1;
    }

    String windowName = "Original video";
    String windowNameEroded = "Video eroded with 3x3 kernel";

    namedWindow(windowName);
    namedWindow(windowNameEroded);

    while(true) {
        Mat frame;
        bool bSuccess = cap.read(frame);

        if(bSuccess == false) {
            cout << "Found the end of the video" << endl;
            break;
        }

        Mat frameEroded;
        erode(frame, frameEroded, getStructuringElement(MORPH_RECT, Size(3, 3)));

        imshow(windowName, frame);
        imshow(windowNameEroded, frameEroded);

        if(waitKey(10) == 27) {
            cout << "Esc key pressed by the user. Stopping the video" << endl;
            break;
        }
    }

    return 0;
}