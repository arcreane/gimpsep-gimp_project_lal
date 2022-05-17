#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include "Resize.h" 

using namespace cv;
using namespace std;


Mat resizeMe(String filename, double scaleX, double scaleY)
{
	Mat im_source;
	im_source = imread(filename, IMREAD_UNCHANGED);
	// the case if the image is empty 
	if (im_source.empty())
	{
		cout << "Could not open or find the image!\n" << endl;
		return im_source;
	}

	Mat result;
	double width = int(im_source.cols * scaleX);
	double height = int(im_source.rows * scaleY);

	resize(im_source, result, Size(width, height), INTER_LINEAR);
	
	
	//createTrackbar("Value of horizontal axis", windowName3 , &scaleX, max_scaleX , doit , this);

	//createTrackbar("Value of vertical axis", windowName3, &scaleY, max_scaleY, doit, this);

	return result;
}
