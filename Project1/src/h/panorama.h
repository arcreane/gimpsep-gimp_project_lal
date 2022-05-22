#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <stdio.h>

using namespace cv;

Mat panorama(std::vector<Mat> matImages, Stitcher::Mode mode);
int pano();