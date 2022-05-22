#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include<opencv2/imgproc.hpp>

#include "save.h"
#include "secondary.h"
#include "CannyEdge.h"

using namespace cv;

Mat detectEdges(Mat src,const int factor) {
	cv::Mat imgGrayscale;
	cv::Mat imgBlurred;
	cv::Mat imgCanny;
	int lowThreshold = 10;
	int highThreshold = lowThreshold * factor;
	

	cv::cvtColor(src, imgGrayscale, CV_32S);

	cv::GaussianBlur(imgGrayscale, imgBlurred, cv::Size(5, 5), 1.5);
	cv::Canny(imgBlurred, imgCanny,lowThreshold,highThreshold);


	return imgCanny;

}

void CannyEdgeDetection() {
	string filename;
	Mat edges;
	Mat srcImage;
	int factor;

	cout << "Please type the filename/filepath of the file from which you want the edge detection done." << endl;
	cin >> filename;
	cout << "Please enter the detection factor (integer)" << endl;
	cin >> factor;
	srcImage = cv::imread(filename, IMREAD_UNCHANGED);

	edges = detectEdges(srcImage, factor);

	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", srcImage);

	namedWindow("Edge Detection", WINDOW_AUTOSIZE);
	imshow("Edge Detection", edges);

	waitKey(0);
	//destroyWindow("Original Image");
	moveWindow("Edge Detection", 0, 0);
	char option;
	while (true) {
		cout << "Would you like to try another threshold?  Reply y for yes" << endl;
		cin >> option;
		if (option == 'y') {
			cout << "Please enter the detection factor (integer)" << endl;
			cin >> factor;
			edges = detectEdges(srcImage, factor);
			imshow("Edge Detection", edges);
			waitKey(0);
		}
		else {
			save(edges);
			break;
		}
	}

	//destroyWindow("Edge Detection");
}

void CannyEdgeDetection(Mat image) {
	Mat edges;

	int factor;
	cout << "Please enter the detection factor (integer)" << endl;
	cin >> factor;

	edges = detectEdges(image, factor);

	imshow("Original Image", image);

	imshow("Edge Detection", edges);

	waitKey(0);
	destroyWindow("Original Image");
	moveWindow("Edge Detection", 0, 0);

	char option;
	while (true) {
		cout << "Would you like to try another threshold?  Reply y for yes" << endl;
		cin >> option;
		if (option == 'y') {
			cout << "Please enter the detection factor (integer)" << endl;
			cin >> factor;
			edges = detectEdges(image, factor);
			imshow("Edge Detection", edges);
			waitKey(0);
		}
		else {
			save(edges);
			break;
		}
	}
	

	// destroyWindow("Edge Detection");
}