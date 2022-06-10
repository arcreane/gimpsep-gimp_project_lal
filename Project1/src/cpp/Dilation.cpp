#include "Dilation.h" 
#include "save.h"
#include "secondary.h"

using namespace cv;
using namespace std;

int dilation_elem = 0;
int dilation_size = 0;

void dilation::doit(int max_elem, int max_kernel_size, string filename, string windowname)
{
    im_source = imread(filename, IMREAD_UNCHANGED);
    // the case if the image is empty 
    if (im_source.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        return;
    }
    namedWindow(windowname, WINDOW_GUI_EXPANDED);
    imshow(windowname, im_source);
    moveWindow(windowname, 0, 0);

    //use a trackbar to control the size of an image.
    //The first trackbar "Element" returns dilation_elem
    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", windowname,
        &dilation_elem, max_elem,
        dilation::Dilation, this);
    // "Kernel size" return dilation_size for the corresponding operation.
    createTrackbar("Kernel size:\n 2n +1", windowname,
        &dilation_size, max_kernel_size,
        dilation::Dilation, this);

    // Call once dilation and erosion to show the initial image.
    // les zone sombre s'ecralicisse avec la dilatation 
}

void dilation::doit(int max_elem, int max_kernel_size, Mat image, string windowname)
{
    im_source = image;
    // the case if the image is empty 
    if (im_source.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        return;
    }
    namedWindow(windowname, WINDOW_GUI_EXPANDED);


    //use a trackbar to control the size of an image.
    //The first trackbar "Element" returns dilation_elem
    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", windowname,
        &dilation_elem, max_elem,
        dilation::Dilation, this);
    // "Kernel size" return dilation_size for the corresponding operation.
    createTrackbar("Kernel size:\n 2n +1", windowname,
        &dilation_size, max_kernel_size,
        dilation::Dilation, this);

    // Call once dilation and erosion to show the initial image.
    // les zone sombre s'ecralicisse avec la dilatation 
    imshow(windowname, im_source);
    moveWindow(windowname, 0, 0);
}


void dilation::Dilation(int value, void* img)
{
    dilation* src = (dilation*)(img);
    int dilation_type = 0;
    if (dilation_elem == 0) {
        dilation_type = MORPH_RECT;  // si savaut  0  alors la forme dilate donnera
    }
    else if (dilation_elem == 1)
    {
        dilation_type = MORPH_CROSS;
    }
    else if (dilation_elem == 2)
    {
        dilation_type = MORPH_ELLIPSE;
    }

    Mat element = getStructuringElement(dilation_type,
        Size(2 * dilation_size + 1, 2 * dilation_size + 1),
        Point(dilation_size, dilation_size));
    /* utiliation de la fct dilate */
    
    dilate(src->im_source, src->dilation_dst, element);
    imshow("Dilation Demo", GetSquareImage(src->dilation_dst, 500));
}

void Dilate() {
    string filename;
    string windowName = "Dilation Demo";
    cout << "Please type the filename/filepath of the file you want to dilate." << endl;
    cin >> filename;
    int const max_elem = 2;
    int const max_kernel_size = 21; // taille du noyaux max vaut
    dilation dilateImg;
    dilateImg.doit(max_elem, max_kernel_size, filename, windowName);
    waitKey(0);

    anotherEdit(dilateImg.dilation_dst);
    // destroyWindow("Dilation Demo");
}

void Dilate(Mat image) {
    string windowName = "Dilation Demo";
    int const max_elem = 2;
    int const max_kernel_size = 21; // taille du noyaux max vaut
    dilation dilateImg;
    dilateImg.doit(max_elem, max_kernel_size, image, windowName);
    waitKey(0);

    anotherEdit(dilateImg.dilation_dst);
    // destroyWindow("Dilation Demo");
}