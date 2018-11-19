#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    // Read the image file
    Mat image = imread("../sample1.png");

    // Check for failure
    if(image.empty()) {
        cout << "Could not open or find the image" << endl;
        cin.get();
        return -1;
    }

    /*
      Make changes to the image as necessary
      1. Change brightness/contrast of the image
      2. Smooth/Blur image
      3. Crop the image
      4. R0tate the image
      5. Draw shapes on the image
     */
    
    bool isSuccess = imwrite("./image.png", image); // write the image to a file as JPEG

    if(isSuccess == false) {
        cout << "Failed to save the image" << endl;
        cin.get();
        return -1;
    }

    cout << "IMage is successfully saved to a file" << endl;

    String windowName = "The Saved Image";

    namedWindow(windowName);

    imshow(windowName, image);

    waitKey(0);

    destroyWindow(windowName);

    return 0;

}