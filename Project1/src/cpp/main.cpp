#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <stdio.h>
#include "lighten.h"
#include "darken.h"
#include "panorama.h"
#include "Dilation.h"
#include "Erosion.h"
#include "Resize.h"
#include "secondary.h"
#include "save.h"
#include "CannyEdge.h"
#include "main.h"

using namespace std;


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
		Dilate();
		break;
	case 2:
		cout << "You have selected Erosion." << endl;
		Erode();
		break;
	case 3:
		cout << "You have selected Resizing." << endl;
		resizer();
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
	case 8:
		return 0;
	default:
		break;
	}
	destroyAllWindows();
	}
	return 0;
}