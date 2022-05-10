#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include "Resize.h" 

using namespace cv;
using namespace std;


Mat resizeMe(Mat im_source, int max_scaleX, int max_scaleY)
{

	im_source = imread("HappyFish.jpg", IMREAD_UNCHANGED);
	// the case if the image is empty 
	if (im_source.empty())
	{
		cout << "Could not open or find the image!\n" << endl;
		//  cout << "Usage: " << argv[0] << " <Input image>" << endl;
		return;
	}

	string windowName3 = "Resize Demo";
	namedWindow(windowName3, WINDOW_AUTOSIZE);
	imshow(windowName3, im_source);
	createTrackbar("Value of horizontal axis", windowName3 , &scaleX, max_scaleX , doit , this);

	createTrackbar("Value of vertical axis", windowName3, &scaleY, max_scaleY, doit, this);


	//create the window
	namedWindow(windowName3, WINDOW_AUTOSIZE);
	//show the images 
	imshow(windowName3, im_source);
	moveWindow(windowName3, 0, 0);

}

void doit() {


	for (float x = 0; x < 2;  x++) 
		double width = int(x * im_source.cols);

	for (float y = 0; y < 2; y++)
		double height = int(y * im_source.rows);

}



resize(im_source, dst, cv::Size(width, height), INTER_LINEAR);



	
	