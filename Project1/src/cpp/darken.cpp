#pragma once
#include "../h/darken.h"
#include "main2.h"
#include "save.h"

using namespace cv;
using namespace std;

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
	char option;
	cout << "Would you like to make another edit to the modified image?  Reply y for yes" << endl;
	cin >> option;
	if (option == 'y') {
		main2(brightImage);
	}
	else {
		save(brightImage);
	}
	
}

void darken(Mat image) {
	String filename;
	int factor;
	cout << "Please type the filename/filepath of the file you want to darken." << endl;
	cin >> filename;
	cout << "Please type the factor by which you would like to make the image darker, ranging from 0 to 255" << endl;
	cin >> factor;
	Mat srcImage = image;
	namedWindow("Original Image");
	namedWindow("Bright Image");

	makeDarkness(image, factor);

	imshow("Original Image", srcImage);
	imshow("Bright Image", image);
	waitKey(0);
	char option;
	cout << "Would you like to make another edit to the modified image?  Reply y for yes" << endl;
	cin >> option;
	if (option == 'y') {
		main2(image);
	}
	else {
		save(image);
	}
	
}