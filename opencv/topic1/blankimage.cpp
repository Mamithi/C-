#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat image(600, 800, CV_8UC3, Scalar(100, 250, 30));

    String windowName = "Window with Blank Image";

    namedWindow(windowName);

    imshow(windowName, image);

    waitKey(0);

    destroyWindow(windowName);

    return 0;
}