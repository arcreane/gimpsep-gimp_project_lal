#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>

using namespace cv;
Mat makeDarkness(Mat src, int factor);
void darken();
void darken(Mat image);