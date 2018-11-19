#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat image = imread("../sample1.png");

    if(image.empty()) {
        cout << "Could not open or read the image" << endl;
        cin.get();
        return -1;
    }

    Mat imageBrightnessHigh50;
    // increase the brightness by 50
    image.convertTo(imageBrightnessHigh50, -1, 1, 50);

     Mat imageBrightnessHigh100;
    // increase the brightness by 100
    image.convertTo(imageBrightnessHigh100, -1, 1, 100);

     Mat imageBrightnessLow50;
    // decrease the brightness by 50
    image.convertTo(imageBrightnessLow50, -1, 1, -50);

     Mat imageBrightnessLow100;
    // decrfease the brightness by 100
    image.convertTo(imageBrightnessLow100, -1, 1, -100);

    // Defining window names for above images
    String windowNameOriginalImage = "Original Image";
    String windowNameBrightnessHigh50 = "Brightness increased by 50";
    String windowNameBrightnessHigh100 = "Brightness increased by 100";
    String windowNameBrightnessLow50 = "Brightness decreased by 50";
    String windowNameBrightnessLow100 = "Brightness decreased by 100";

    // Create and open windows for above images
    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessHigh50, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessHigh100, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow50, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow100, WINDOW_NORMAL);

    // Show the above images inside the created windows
    imshow(windowNameOriginalImage, image);
    imshow(windowNameBrightnessHigh50, imageBrightnessHigh50);
    imshow(windowNameBrightnessHigh100, imageBrightnessHigh100);
    imshow(windowNameBrightnessLow50, imageBrightnessLow50);
    imshow(windowNameBrightnessLow100, imageBrightnessLow100);

    waitKey(0);

    destroyAllWindows();

    return 0;
}