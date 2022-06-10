#pragma once
#include <opencv2/opencv.hpp>
#include "lighten.h"
#include "darken.h"
#include "Resize.h"
#include "Dilation.h"
#include "Erosion.h"
#include "secondary.h"
#include "CannyEdge.h"
#include "save.h"

using namespace cv;
using namespace std;

cv::Mat GetSquareImage(const cv::Mat& img, int target_width = 500)
{
	int width = img.cols,
		height = img.rows;

	cv::Mat square = cv::Mat::zeros(target_width, target_width, img.type());

	int max_dim = (width >= height) ? width : height;
	float scale = ((float)target_width) / max_dim;
	cv::Rect roi;
	if (width >= height)
	{
		roi.width = target_width;
		roi.x = 0;
		roi.height = height * scale;
		roi.y = (target_width - roi.height) / 2;
	}
	else
	{
		roi.y = 0;
		roi.height = target_width;
		roi.width = width * scale;
		roi.x = (target_width - roi.width) / 2;
	}

	cv::resize(img, square(roi), roi.size());

	return square;
}

int secondary(Mat image) {
	while (true) {
		int selection = -1;
		cout << "Select an option below by typing the number corresponding to that option." << endl;
		cout << "1. Dilation\n2. Erosion\n3. Resizing\n4. Lighten\n5. Darken\n6. Panorama (NOT AN OPTION TO MODIFY)\n7. Canny Edge Detection\n8. Go back to previous menu" << endl;
		cin >> selection;

		if (!(selection > 0 && selection <= 8)) {
			cout << "You have typed something outside of range, please try again.";
			break;
		}

		switch (selection) {
		case 1:
			cout << "You have selected Dilation." << endl;
			Dilate(image);
			break;
		case 2:
			cout << "You have selected Erosion." << endl;
			Erode(image);
			break;
		case 3:
			cout << "You have selected Resizing." << endl;
			resizer(image);
			break;
		case 4:
			cout << "You have selected Lighten." << endl;
			lighten(image);
			break;
		case 5:
			cout << "You have selected Darken." << endl;
			darken(image);
			break;
		case 6:
			cout << "Panorama is not an option for modified images, please try again." << endl;
			break;
		case 7:
			cout << "You have selected Canny Edge Detection" << endl;
			CannyEdgeDetection(image);
			break;
		case 8:
			return 0;
		default:
			break;
		}
	}
	destroyAllWindows();
	return 0;
}

