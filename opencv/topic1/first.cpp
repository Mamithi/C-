#include <iostream>
#include <opencv2/highgui.hpp>


using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    Mat img;
    img = imread("sample1.png");

    if(img.empty()) return -1;
    cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example1", img);
    cv::waitKey(0);
    cv::destroyWindow("Example1");

    return 0;
}
