#pragma once
#include <opencv2/opencv.hpp>
#include "lighten.h"
#include "darken.h"
#include "main2.h"

using namespace cv;
using namespace std;


void main2(Mat image) {
	while (true) {
		int selection = -1;
		cout << "Select an option below by typing the number corresponding to that option." << endl;
		cout << "1. Dilation\n2. Erosion\n3. Resizing\n4. Lighten\n5. Darken\n7. Canny Edge Detection\n8. Quit Program" << endl;
		cin >> selection;

		if (!(selection > 0 && selection <= 8)) {
			cout << "You have typed something outside of range, please try again.";
			break;
		}

		switch (selection) {
		case 1:
			//cout << "You have selected Dilation." << endl;
			//Dilation();
			break;
		case 2:
			/*	cout << "You have selected Erosion." << endl;
				Erosion();*/
			break;
		case 3:
			/*cout << "You have selected Resizing." << endl;
			resizing();*/
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
			/*cout << "You have selected Panorama." << endl;
			pano();*/
			break;
		case 7:
			cout << "You have selected Canny Edge Detection." << endl;
			//cannyedge();
			break;
		default:
			break;
		}
	}
}

