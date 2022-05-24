#include "../h/lighten.h"
#include "save.h"
#include "secondary.h"
using namespace cv;
using namespace std;

Mat makeBrightness(Mat src, int factor) {
    for (int i = 0; i < src.rows; i++) {
        for (int j = 0; j < src.cols; j++) {
            for (int k = 0; k < 3; k++) {
                if (src.at<Vec3b>(i, j)[k] <= 255 - factor)
                    src.at<Vec3b>(i, j)[k] += factor;
                else
                    src.at<Vec3b>(i, j)[k] = 255;
            }
        }
    }
    return src;
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
	destroyWindow("Original Image");
	/*char option;
	cout << "Would you like to make another edit to the modified image?  Reply y for yes" << endl;
	cin >> option;*/
	anotherEdit(brightImage);
	//if (option == 'y') {
	//	secondary(brightImage);
	//}
	//else {
	//	save(brightImage);
	//	destroyWindow("Bright Image");
	//}
	
}


void lighten(Mat image) {
	int factor;
	cout << "Please type the factor by which you would like to increase the brightness of the image, ranging from 0 to 255" << endl;
	cin >> factor;

	namedWindow("Bright Image");

	makeBrightness(image, factor);

	imshow("Bright Image", image);
	waitKey(0);

	/*char option;
	cout << "Would you like to make another edit to the modified image?  Reply y for yes" << endl;
	cin >> option;*/
	anotherEdit(image);
	//if (option == 'y') {
	//	secondary(image);
	//	// waitKey(0);
	//}
	//else {
	//	save(image);
	//}
	// destroyWindow("Bright Image");
}