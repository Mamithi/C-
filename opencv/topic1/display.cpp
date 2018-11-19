#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat image = imread("sample1.png"); // Read the image file

    if(image.empty()){ // Check for failure
        cout << "Could not open or find image" << endl;
        cin.get();
        return -1;
    }

    String windowName = "Display Image"; // Name of the window

    namedWindow(windowName); // Create a window

    imshow(windowName, image); // show our image inside the created window

    waitKey(0); // Wait for any keystroke in the window

    destroyWindow(windowName); // destroy the created window

    return 0;
}