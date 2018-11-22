#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat image = imread("../sample.jpg");

    if(image.empty()) {
        cout << "Could not open or find the image" << endl;
        cin.get();
        return -1;
    }

    Mat imageEroded3x3;
    erode(image, imageEroded3x3, getStructuringElement(MORPH_RECT, Size(3, 3)));

    Mat imageEroded5x5;
    erode(image, imageEroded5x5, getStructuringElement(MORPH_RECT, Size(5, 5)));

    String windowName = "Original Image";
    String windowNameEroded3x3 = "Image eroded using 3x3 kernel";
    String windowNameEroded5x5 = "Image eroded using 5x5 kernel";

    namedWindow(windowName);
    namedWindow(windowNameEroded3x3);
    namedWindow(windowNameEroded5x5);

    imshow(windowName, image);
    imshow(windowNameEroded3x3, imageEroded3x3);
    imshow(windowNameEroded5x5, imageEroded5x5);

    waitKey(0);

    destroyAllWindows();

    return 0;

}