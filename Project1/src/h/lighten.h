#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>

using namespace cv;
Mat makeBrightness(Mat src, int factor);

void lighten();
void lighten(Mat image);