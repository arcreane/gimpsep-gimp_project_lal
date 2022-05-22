#pragma once
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;



Mat resizeMe(Mat im_source, double scaleX, double scaleY);
void resizer();
void resizer(Mat im_source);
void resizing();


