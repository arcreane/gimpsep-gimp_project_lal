#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include<opencv2/imgproc.hpp>

#include "../h/CannyEdge.h"

using namespace cv;

Mat detectEdges(Mat src,const int factor) {
	cv::Mat imgGrayscale;
	cv::Mat imgBlurred;
	cv::Mat imgCanny;
	int lowThreshold = 10;
	int highThreshold = lowThreshold * factor;
	

	cv::cvtColor(src, imgGrayscale, CV_32S);

	cv::GaussianBlur(imgGrayscale, imgBlurred, cv::Size(5, 5), 1.5);
	cv::Canny(imgBlurred, imgCanny,lowThreshold,highThreshold);


	return imgCanny;

}