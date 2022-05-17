#include "../h/Erosion.h" 

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

    string windowName2 = "Erosion Demo";
    namedWindow(windowName2, WINDOW_AUTOSIZE);
    imshow(windowName2, im_source);
    moveWindow(windowName2, 0, 0);

    //The first trackbar "Element" returns erosion_elem
    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", windowName2,
        &erosion_elem, max_elem,
        erosion::Erosion, this);
    // "Kernel size" return erosion_size for the corresponding operation.
    createTrackbar("Kernel size:\n 2n +1", windowName2,
        &erosion_size, max_kernel_size,
        erosion::Erosion, this);
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

