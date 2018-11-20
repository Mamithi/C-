#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    VideoCapture cap("../video/sample.mp4");

    if(cap.isOpened() == false) {
        cout << "Could not open the video" << endl;
        cin.get();
        return -1;
    }

    // Define window names for above images
    String windowNameOriginalImage = "Original Image";
    String windowNameContrastHigh2 = "Contrsast increased by 2";
    String windowNameContrastHigh4 = "Contrsast increased by 4";
    String windowNameContrastLow0_5 = "Contrsast decreased by 0.5";
    String windowNameContrastLow0_25 = "Contrsast decreased by 0.25";

    // create and open windows for above images
    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh2, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_5, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_25, WINDOW_NORMAL);

    while(true) {
        Mat frame;

        bool bSuccess = cap.read(frame);

        if(bSuccess == false) {
            cout << "Found the end of the video" << endl;
            break;
        }

        Mat frameContrastHigh2;
        frame.convertTo(frameContrastHigh2, -1, 2, 0);

        Mat frameContrastHigh4;
        frame.convertTo(frameContrastHigh4, -1, 4, 0);

        Mat frameContrastLow0_5;
        frame.convertTo(frameContrastLow0_5, -1, 0.5, 0);

        Mat frameContrastLow0_25;
        frame.convertTo(frameContrastLow0_25, -1, 0.25, 0);

        imshow(windowNameOriginalImage, frame);
        imshow(windowNameContrastHigh2, frameContrastHigh2);
        imshow(windowNameContrastHigh4, frameContrastHigh4);
        imshow(windowNameContrastLow0_5, frameContrastLow0_5);
        imshow(windowNameContrastLow0_25, frameContrastLow0_25);

        if(waitKey(10) == 27) {
            cout << "Esc key pressed by the user. Stopping the video" << endl;
            break;
        }
    }
    return 0;
}
