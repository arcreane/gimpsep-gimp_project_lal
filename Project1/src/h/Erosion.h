#pragma once
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

class erosion {
	
private : 
	// def des variable image
	
	Mat im_source;

public : 
	//def des fonction 
	Mat erosion_dst;
	void doit(int max_elem, int max_kernel_size, String filename);
	static void Erosion(int, void*);
	void doit(int max_elem, int max_kernel_size, Mat image);
};


void Erode();
void Erode(Mat image);

