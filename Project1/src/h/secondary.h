#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include "save.h"

using namespace cv;

int secondary(Mat image);
Mat GetSquareImage(const cv::Mat& img, int target_width);