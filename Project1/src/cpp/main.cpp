#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <stdio.h>
#include "../h/lighten.h"
#include "../h/darken.h"
#include "../h/panorama.h"
#include "../h/Dilation.h"
#include "../h/Erosion.h"
#include "../h/Resize.h"
#include "main2.h"
#include "save.h"
#include "../h/CannyEdge.h"

using namespace std;
Mat i;

int save(Mat image) {
	char save;
	String filename;
	cout << "Would you like to save your image? Type y for yes or n for no" << endl;
	cin >> save;
	if (save == 'y') {
		cout << "What would you like your filename to be? (enter without extension, as all will be saved as jpg)" << endl;
		cin >> filename;
		imwrite(filename+".jpg", image);
	}
	return 0;
}

void lighten() {
	String filename;
	int factor;
	cout << "Please type the filename/filepath of the file you want to lighten." << endl;
	cin >> filename;
	cout << "Please type the factor by which you would like to increase the brightness of the image, ranging from 0 to 255" << endl;
	cin >> factor;
	Mat srcImage = cv::imread(filename);
	Mat brightImage;
	srcImage.copyTo(brightImage);
	namedWindow("Original Image");
	namedWindow("Bright Image");

	makeBrightness(brightImage, factor);

	imshow("Original Image", srcImage);
	imshow("Bright Image", brightImage);
	waitKey(0);
	save(brightImage);
}

void darken() {
	String filename;
	int factor;
	cout << "Please type the filename/filepath of the file you want to darken." << endl;
	cin >> filename;
	cout << "Please type the factor by which you would like to make the image darker, ranging from 0 to 255" << endl;
	cin >> factor;
	Mat srcImage = cv::imread(filename);
	Mat brightImage;
	srcImage.copyTo(brightImage);
	namedWindow("Original Image");
	namedWindow("Bright Image");

	makeDarkness(brightImage, factor);

	imshow("Original Image", srcImage);
	imshow("Bright Image", brightImage);
	waitKey(0);
	save(brightImage);
}

int pano() {
	Stitcher::Mode mode = Stitcher::PANORAMA;
	int numImages;
	String filename;
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
	return 0;
}


void Dilation() {
	String filename;
	cout << "Please type the filename/filepath of the file you want to dilate." << endl;
	cin >> filename;
	int const max_elem = 2;
	int const max_kernel_size = 21; // taille du noyaux max vaut
	dilation dilateImg;
	dilateImg.doit(max_elem, max_kernel_size, filename);
	waitKey(0);
}

void Erosion() {
	String filename;
	cout << "Please type the filename/filepath of the file you want to erode." << endl;
	cin >> filename;
	int const max_elem = 2;
	int const max_kernel_size = 21; // taille du noyaux max vaut
	erosion erodeImg;
	erodeImg.doit(max_elem, max_kernel_size, filename);
	waitKey(0);
}

void resizing() {
	String filename;
	double X, Y;
	Mat resizedImage;
	
	cout << "Please type the filename/filepath of the file you want to resize." << endl;
	cin >> filename;
	Mat srcImage = cv::imread(filename, IMREAD_UNCHANGED);
	//srcImage.copyTo(resizedImage);

	cout << "Enter scale for x and y" << endl;
	cin >> X >> Y;

	resizedImage = resizeMe(filename, X, Y);
	
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", srcImage);
	namedWindow("Resized Image", WINDOW_AUTOSIZE);
	imshow("Resized Image", resizedImage);
	waitKey(0);
	save(srcImage);
}

void CannyEdgeDetection() {
	String filename;
	Mat edges;
	Mat srcImage;
	int factor;

	cout << "Please type the filename/filepath of the file from which you want the edge detection done." << endl;
	cin >> filename;
	cout << "Please enter the detection factor (integer)" << endl;
	cin >> factor;
	srcImage = cv::imread(filename, IMREAD_UNCHANGED);

	edges = detectEdges(srcImage,factor);
		
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", srcImage);

	namedWindow("Edge Detection", WINDOW_AUTOSIZE);
	imshow("Edge Detection", edges);

	waitKey(0);


}

int main() {
	while (true) {
		int selection = -1;
		cout << "Welcome to the Image Editor\nWhat would you like to do today?\n";
		cout << "Select an option below by typing the number corresponding to that option." << endl;
		cout << "1. Dilation\n2. Erosion\n3. Resizing\n4. Lighten\n5. Darken\n6. Panorama\n7. Canny Edge Detection\n8. Quit Program" << endl;

		cin >> selection;

		if (!(selection > 0 && selection <= 8)) {
			cout << "You have typed something outside of range, please try again.";
			return -1;
		} 

	switch (selection) {
	case 1:
		cout << "You have selected Dilation." << endl;
		Dilation();
		break;
	case 2:
		cout << "You have selected Erosion." << endl;
		Erosion();
		break;
	case 3:
		cout << "You have selected Resizing." << endl;
		resizing();
		break;
	case 4:
		cout << "You have selected Lighten." << endl;
		lighten();
		break;
	case 5:
		cout << "You have selected Darken." << endl;
		darken();
		break;
	case 6:
		cout << "You have selected Panorama." << endl;
		pano();
		break;
	case 7:
		cout << "You have selected Canny Edge Detection." << endl;
		CannyEdgeDetection();
		break;
	default:
		break;
	}
	}
	return 0;
}