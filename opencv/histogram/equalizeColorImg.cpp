#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat image = imread("../images.jpg");

    if(image.empty()) {
        cout << "Could not open or find the image" << endl;
        cin.get();
        return -1;
    }

    // Convert the image  from BGR to YCrCb color space
    Mat histEqualizedImage;
    cvtColor(image, histEqualizedImage, COLOR_BGR2YCrCb);

    // SPlit the image into 3 channels; Y, Cr and Cb channels respectively and store ir in a std::vector
    vector<Mat> vecChannels;
    split(histEqualizedImage, vecChannels);

    // Equalize the histogram of only the Y channl
    equalizeHist(vecChannels[0], vecChannels[0]);

    // Merge 3 channels in the vector to form the color image in YcrCb color space
    merge(vecChannels, histEqualizedImage);

    // Cinvert the histogram equalized image from YCrCb to BGR color spce again
    cvtColor(histEqualizedImage, histEqualizedImage, COLOR_YCrCb2BGR);

    String windowNameOriginalImage = "Original Image";
    String windowNameHistogramEqualized = "Histogram Equalized Color Image";

    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameHistogramEqualized, WINDOW_NORMAL);

    imshow(windowNameOriginalImage, image);
    imshow(windowNameHistogramEqualized, histEqualizedImage);

    waitKey(0);

    destroyAllWindows();

    return 0;
}