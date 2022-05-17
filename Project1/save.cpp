
#include "save.h"
#include "opencv2/opencv.hpp"

using namespace cv;


int save(cv::Mat& image)
{
	char save;
	String filename;
	std::cout << "Would you like to save your image? Type y for yes or n for no" << std::endl;
	std::cin >> save;
	if (save == 'y') {
		std::cout << "What would you like your filename to be? (enter without extension, as all will be saved as jpg)" << std::endl;
		std::cin >> filename;
		imwrite(filename + ".jpg", image);
	}
	return 0;
}
