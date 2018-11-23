#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
   Mat image = imread("../sample.jpg");

   if(image.empty()) {
       cout << "Cannot find or open the image" << endl;
       cin.get();
       return -1;
   }

   String windowName = "Image";

   namedWindow(windowName);

    // Create trackbar to change brightness
    int slider = 51;
    createTrackbar("Brightness", windowName, &slider, 100);

    int slider2;
    createTrackbar("Contrast", windowName, &slider2, 100);

    while(true) {
        Mat newImage;
        int brightness = slider - 50;
        double contrast = slider2/50.0;
        image.convertTo(newImage, contrast, brightness);

        imshow(windowName, newImage);

        if(waitKey(10) == 27) {
            cout << "Esc key pressed by user." << endl;
            break;
        }
    }

    return 0;
}
