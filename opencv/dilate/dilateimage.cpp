#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

int main(int argc, char** argv) {
    Mat image = imread("../sample.jpg");

    Mat imageDilated;
    dilate(image, imageDilated, getStructuringElement(MORPH_RECT, Size(5, 5)));

    String windowName = "Original Image";
    String windowNameDilated = "Dilated Image";

    namedWindow(windowName);
    namedWindow(windowNameDilated);

    imshow(windowName, image);
    imshow(windowNameDilated, imageDilated);

    waitKey(0);

    destroyAllWindows();

    return 0;
}