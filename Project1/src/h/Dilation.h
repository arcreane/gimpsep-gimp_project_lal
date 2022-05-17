#pragma once
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

class dilation{

private:
	/* def des variable image*/
	Mat dilation_dst;
	Mat im_source;
	

public:
	/* def des fonction */
	void doit(int max_elem, int max_kernel_size, String filename);
	static void Dilation(int, void*);
};
