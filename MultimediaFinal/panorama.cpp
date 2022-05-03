#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <stdio.h>

#include "panorama.h"
using namespace cv;
using namespace std;

Mat panorama(std::vector<Mat> matImages, Stitcher::Mode mode) {
	Mat result;
	Ptr<Stitcher> stitcher = Stitcher::create(mode);
	Stitcher::Status status = stitcher->stitch(matImages, result);

	if (status != Stitcher::OK) {
		cout << "Images not compatable" << endl;
		return result;
	}
	

	return result;
}