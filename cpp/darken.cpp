#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>

#include "../h/darken.h"
using namespace cv;

Mat makeDarkness(Mat src, int factor) {
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            for (int k = 0; k < 3; k++) {
                if (src.at<Vec3b>(i, j)[k] >= 0 + factor)
                    src.at<Vec3b>(i, j)[k] -= factor;
                else
                    src.at<Vec3b>(i, j)[k] = 0;
            }
        }
    }
    return src;
}