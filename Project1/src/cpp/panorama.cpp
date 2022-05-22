#include "panorama.h"
#include "save.h"
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

int pano() {
	Stitcher::Mode mode = Stitcher::PANORAMA;
	int numImages;
	string filename;
	Mat temp;
	vector<Mat> matImages;
	cout << "How many images?\n->";
	cin >> numImages;
	cout << "Type image filenames separated by a newline" << endl;
	for (int i = 0; i < numImages; i++) {
		cin >> filename;
		Mat temp = cv::imread(filename);
		if (temp.empty()) {
			cout << "Image Unreadable/File Does Not Exist" << endl;
			return -1;
		}
		matImages.push_back(temp);
	}

	Mat result = panorama(matImages, mode);

	if (result.empty()) {
		cout << "Unknown Error, Empty Final Image" << endl;
		return -1;
	}

	imshow("Result", result);
	waitKey(0);
	save(result);
	destroyWindow("Result");
	return 0;
}