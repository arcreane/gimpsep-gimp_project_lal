#pragma once
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;



/* def des variable image*/
	Mat im_source; 
	Mat dst; 
	int scaleX;
	int scaleY;
	int const max_scaleX = 3; 
	int const max_scaleY = 3;

Mat resizeMe(Mat im_source, int max_scaleX, int max_scaleY);



