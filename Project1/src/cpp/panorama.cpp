#include "../h/panorama.h"
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