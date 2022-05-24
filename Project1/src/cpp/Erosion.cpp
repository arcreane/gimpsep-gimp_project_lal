#include "Erosion.h" 
#include "secondary.h"

using namespace cv;
using namespace std;

// in the begining all the variable are worth 0 
int erosion_elem = 0;
int erosion_size = 0;


void erosion::doit(int max_elem, int max_kernel_size, String filename)
{
    im_source = imread(filename, IMREAD_UNCHANGED);
    // the case if the image is empty 
    if (im_source.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        return;
    }

    string windowName = "Erosion Demo";
    namedWindow(windowName);

    imshow(windowName, im_source);
    moveWindow(windowName, 0, 0);

    //The first trackbar "Element" returns erosion_elem
    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", windowName,
        &erosion_elem, max_elem,
        erosion::Erosion, this);
    // "Kernel size" return erosion_size for the corresponding operation.
    createTrackbar("Kernel size:\n 2n +1", windowName,
        &erosion_size, max_kernel_size,
        erosion::Erosion, this);
}

void erosion::doit(int max_elem, int max_kernel_size, Mat image)
{
    im_source = image;
    // the case if the image is empty 
    if (im_source.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        return;
    }

    string windowName = "Erosion Demo";

    namedWindow(windowName, WINDOW_AUTOSIZE);

  
    //The first trackbar "Element" returns erosion_elem
    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", windowName,
        &erosion_elem, max_elem,
        erosion::Erosion, this);
    // "Kernel size" return erosion_size for the corresponding operation.
    createTrackbar("Kernel size:\n 2n +1", windowName,
        &erosion_size, max_kernel_size,
        erosion::Erosion, this);

    imshow(windowName, im_source);
    moveWindow(windowName, 0, 0);

}

void erosion::Erosion(int value, void* img)
{
    erosion* src = (erosion*)(img);
    int erosion_type = 0;
    if (erosion_elem == 0)
    {
        erosion_type = MORPH_RECT;  // Rectangular box 
    }
    else if (erosion_elem == 1)
    {
        erosion_type = MORPH_CROSS; // a cross
    }
    else if (erosion_elem == 2)
    {
        erosion_type = MORPH_ELLIPSE;  // an ellipse 
    }
    Mat element = getStructuringElement(erosion_type,
        Size(2 * erosion_size + 1, 2 * erosion_size + 1),
        Point(erosion_size, erosion_size));

    erode(src->im_source, src->erosion_dst, element);
    imshow("Erosion Demo", src->erosion_dst);

}

void Erode() {
    string filename;
    cout << "Please type the filename/filepath of the file you want to erode." << endl;
    cin >> filename;
    int const max_elem = 2;
    int const max_kernel_size = 21; // taille du noyaux max vaut
    erosion erodeImg;
    erodeImg.doit(max_elem, max_kernel_size, filename);
    waitKey(0);
    anotherEdit(erodeImg.erosion_dst);
    // destroyWindow("Erosion Demo");
    // saveas(erodeImg.erosion_dst, "temp");
}

void Erode(Mat image) {
    int const max_elem = 2;
    int const max_kernel_size = 21; // taille du noyaux max vaut
    erosion erodeImg;
    //destroyWindow("Erosion Demo");
    erodeImg.doit(max_elem, max_kernel_size, image);
    waitKey(0);
    anotherEdit(erodeImg.erosion_dst);
    // destroyWindow("Erosion Demo");
    // saveas(erodeImg.erosion_dst, "temp");
}