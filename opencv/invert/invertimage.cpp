#include <iostream>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char** argv) {
    Mat image = imread("../sample.jpg");

    Mat invertedImage;
    bitwise_not(image, invertedImage);

    String windowName = "Original Image";
    String windowNameInverted = "Inverted Image";

    namedWindow(windowName);
    namedWindow(windowNameInverted);

    imshow(windowName, image);
    imshow(windowNameInverted, invertedImage);

    waitKey(0);

    destroyAllWindows();

    return 0;
}