#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat image = imread("../sample.jpg");

    if(image.empty()) {
        cout << "Could not find or open the image" << endl;
        cin.get();
        return -1; 
    }

    Mat imageBlurred3x3;
    GaussianBlur(image, imageBlurred3x3, Size(3, 3), 0);

    Mat imageBlurred5x5;
    GaussianBlur(image, imageBlurred5x5, Size(5, 5), 0);

    String windowName = "Original Image";
    String windowNameBlurred3x3 = "Image Blurred with a 3x3 Gaussian Kernel";
    String windowNameBlurred5x5 = "Image Blurred with a 5x5 Gaussian Kernel";

    namedWindow(windowName);
    namedWindow(windowNameBlurred3x3);
    namedWindow(windowNameBlurred5x5);

    imshow(windowName, image);
    imshow(windowNameBlurred3x3, imageBlurred3x3);
    imshow(windowNameBlurred5x5, imageBlurred5x5);

    waitKey(0);

    destroyAllWindows();

    return 0;
}