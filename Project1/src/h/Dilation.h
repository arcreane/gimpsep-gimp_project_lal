#pragma once
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

class dilation{

private:
	/* def des variable image*/
public: 
	Mat dilation_dst;
	Mat im_source;
	
	

public:
	/* def des fonction */
	void doit(int max_elem, int max_kernel_size, string filename, string windowname);
	static void Dilation(int, void*);
	void doit(int max_elem, int max_kernel_size, Mat image, string windowname);
	
};

void Dilate();
void Dilate(Mat image);