#pragma once
#include <iostream>

using namespace std;
namespace cv{
class Mat;
}
	
int save(cv::Mat& image);
using namespace std;
void saveas(cv::Mat& image, std::string name);
void anotherEdit(cv::Mat& src);