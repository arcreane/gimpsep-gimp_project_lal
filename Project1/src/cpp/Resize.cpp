#include "Resize.h" 
#include "save.h"

using namespace cv;
using namespace std;


Mat resizeMe(Mat img, double scaleX, double scaleY)
{

	Mat result;
	double width = int(img.cols * scaleX);
	double height = int(img.rows * scaleY);

	resize(img, result, Size(width, height), INTER_LINEAR);

	return result;
}


void resizer() {
	String filename;
	double X, Y;
	Mat resizedImage;

	cout << "Please type the filename/filepath of the file you want to resize." << endl;
	cin >> filename;

	Mat im_source;
	im_source = imread(filename, IMREAD_UNCHANGED);
	// the case if the image is empty 
	if (im_source.empty())
	{
		cout << "Could not open or find the image!\n" << endl;
		return;
	}

	Mat srcImage = cv::imread(filename, IMREAD_UNCHANGED);

	cout << "Enter scale for x and y (between 0 and 1 is making smaller, >1 is making bigger), both cannot be 1" << endl;
	
	cin >> X >> Y;

	resizedImage = resizeMe(srcImage, X, Y);

	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", srcImage);
	namedWindow("Resized Image", WINDOW_AUTOSIZE);
	imshow("Resized Image", resizedImage);
	waitKey(0);
	destroyWindow("Original Image");
	save(resizedImage);
	destroyWindow("Resized Image");
}

void resizer(Mat im_source) {

	double X, Y;
	Mat resizedImage;
	// the case if the image is empty 
	if (im_source.empty())
	{
		cout << "Could not open or find the image!\n" << endl;
		return;
	}


	cout << "Enter scale for x and y (between 0 and 1 is making smaller, >1 is making bigger), both cannot be 1" << endl;
	cin >> X >> Y;

	resizedImage = resizeMe(im_source, X, Y);

	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", im_source);
	namedWindow("Resized Image", WINDOW_AUTOSIZE);
	imshow("Resized Image", resizedImage);
	destroyWindow("Original Image");
	waitKey(0);
	save(resizedImage);
	destroyWindow("Resized Image");
}

void resizing() {
	string filename;
	double X, Y;
	Mat resizedImage;

	cout << "Please type the filename/filepath of the file you want to resize." << endl;
	cin >> filename;
	Mat srcImage = cv::imread(filename, IMREAD_UNCHANGED);

	cout << "Enter scale for x and y (between 0 and 1 is making smaller, >1 is making bigger), both cannot be 1" << endl;
	cin >> X >> Y;

	resizedImage = resizeMe(srcImage, X, Y);

	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", srcImage);
	namedWindow("Resized Image", WINDOW_AUTOSIZE);
	imshow("Resized Image", resizedImage);
	destroyWindow("Original Image");
	waitKey(0);
	moveWindow("Resized Image", 0, 0);
	save(srcImage);
	// destroyWindow("Resized Image");
}