#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
	Mat img = imread("~/Download/wangbaoqiang.jpg");
	imshow("Image",img);

	waitKey(6000);

}
