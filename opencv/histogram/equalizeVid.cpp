#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    VideoCapture cap("../video/sample.mp4");

    if(cap.isOpened() == false) {
        cout << "Cannot open the video" << endl;
        cin.get();
        return -1;
    }

    String windowNameOriginal = "original Video";
    String windowNameHistogramEqualized = "Histogram Equalized Video";

    namedWindow(windowNameOriginal, WINDOW_NORMAL);
    namedWindow(windowNameHistogramEqualized, WINDOW_NORMAL);

    while(true) {
        Mat frame;
        bool bSuccess = cap.read(frame);

        if(bSuccess == false) {
            cout << "Found end of the video" << endl;
            break;
        }

        Mat histEqualizedImage;
        cvtColor(frame, histEqualizedImage, COLOR_BGR2YCrCb);

        vector<Mat> vecChannels;
        split(histEqualizedImage, vecChannels);

        equalizeHist(vecChannels[0], vecChannels[0]);

        merge(vecChannels, histEqualizedImage);

        cvtColor(histEqualizedImage, histEqualizedImage, COLOR_BGR2YCrCb);

        imshow(windowNameOriginal, frame);
        imshow(windowNameHistogramEqualized, histEqualizedImage);

        if(waitKey(10) == 27) {
            cout << "Esc key pressed by user. Stopping the video" << endl;
            break;
        }
    }

    destroyAllWindows();
    return 0;
}