#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat image = imread("../sample1.png");

    if(image.empty()) {
        cout << "Could not open or locate the image" << endl;
        cin.get();
        return -1;
    }

    

    Mat imageContrastHigh2;
    image.convertTo(imageContrastHigh2, -1, 2, 0); // increase contrast by 2

    Mat imageContrastHigh4;
    image.convertTo(imageContrastHigh4, -1, 4, 0); // increase contrast by 4

    Mat imageContrastLow0_5;
    image.convertTo(imageContrastLow0_5, -1, 0.5, 0); // increase contrast by 0.5

    Mat imageContrastLow0_25;
    image.convertTo(imageContrastLow0_25, -1, 0.25, 0); // increase contrast by 2



    // Defining windows for the above images
    String windowNameOriginal = "Original Image";
    String windowNameContrastHigh2 = "Contrast increased by 2";
    String windowNameContrastHigh4 = "Contrast increased by 4";
    String windowNameContrastLow0_5 = "Contrast decreased by 0.5";
    String windowNameContrastLow0_25 = "Contrast decreased by 0.25";

   

    // Create and open windows for above images
    namedWindow(windowNameOriginal, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh2, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh4, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_5, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_25, WINDOW_NORMAL);

     

    // Show above images inside the created windows
    imshow(windowNameOriginal, image);
    imshow(windowNameContrastHigh2, imageContrastHigh2);
    imshow(windowNameContrastHigh4, imageContrastHigh4);
    imshow(windowNameContrastLow0_5, imageContrastLow0_5);
    imshow(windowNameContrastLow0_25, imageContrastLow0_25);

    

    waitKey(0);

    destroyAllWindows();

    return 0;
}
