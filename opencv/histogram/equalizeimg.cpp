#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat image = imread("../images.jpeg");

    if(image.empty()) {
        cout << "Cannot open or find the image" << endl;
        cin.get();
        return -1;
    }

    // Change teh color image to grayscale image
    cvtColor(image, image, COLOR_BGR2GRAY);

    //equalize the histogram
    Mat histEqualizedImage;
    equalizeHist(image, histEqualizedImage);

    // Define names of windows
    String windowNameOriginal = "Original Image";
    String windowNameHistogramEqualized = "Histogram Equalized Image";

    // Create windows with the above names'
    namedWindow(windowNameOriginal, WINDOW_NORMAL);
    namedWindow(windowNameHistogramEqualized, WINDOW_NORMAL);

    // SHow the images inside created windows
    imshow(windowNameOriginal, image);
    imshow(windowNameHistogramEqualized, histEqualizedImage);

    waitKey(0);

    destroyAllWindows();

    return 0;
}