#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    VideoCapture cap("../video/sample.mp4");

    if(cap.isOpened() == false) {
        cout << "Cannot open the video file" << endl;
        cin.get();
        return -1;
    }

    String windowName = "Original video";
    String windowNameBlurred3x3 = "Video blurred with 3x3 gaussian kernel";

    namedWindow(windowName);
    namedWindow(windowNameBlurred3x3);

    while(true) {
        Mat frame;
        bool bSuccess = cap.read(frame);

        if(bSuccess == false) {
            cout << "Found the end of the video" << endl;
            break;
        }

        Mat frameBlurred;
        GaussianBlur(frame, frameBlurred, Size(3, 3), 0);

        imshow(windowName, frame);
        imshow(windowNameBlurred3x3, frameBlurred);

        if(waitKey(10) == 27) {
            cout << "Esc key pressed by user. Stopping video" << endl;
            break;
        }

    }

    return 0;
}