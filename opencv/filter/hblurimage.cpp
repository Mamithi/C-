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

   // Blur the image with 3x3 kernel
   Mat imageBlurred3x3;
   blur(image, imageBlurred3x3, Size(3, 3));

   // Blur the image with 5x5 kernel
   Mat imageBlurred5x5;
   blur(image, imageBlurred5x5, Size(5, 5));

    // Define names of the windows
    String windowName = "The guitar";
    String windowNameImageBlurred3x3 = "The guitar blurred with 3x3 kernel";
    String windowNameImageBlurred5x5 = "The guitar blurred with 5x5 kernel";

    namedWindow(windowName);
    namedWindow(windowNameImageBlurred3x3);
    namedWindow(windowNameImageBlurred5x5);

    // show the images
    imshow(windowName, image);
    imshow(windowNameImageBlurred3x3, imageBlurred3x3);
    imshow(windowNameImageBlurred5x5, imageBlurred3x3);

    waitKey(0);

    destroyAllWindows();

    return 0;
}