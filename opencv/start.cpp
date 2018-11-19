#include <opencv2/highgui.hpp>

int main(int argc, char** argv){
	cv::Mat imgOriginal;

	imgOriginal = cv::imread("sample1.png");

	// cv::Mat img = cv::imread("sample1.png");

	if(imgOriginal.empty()) return -1;
	cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
	cv::imshow("Example1", imgOriginal);
	cv::waitKey(0);
	cv::destroyWindow("Example1");
	return 0;
}
