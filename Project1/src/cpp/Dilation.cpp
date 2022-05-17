#include "Dilation.h" 

using namespace cv;
using namespace std;

int dilation_elem = 0;
int dilation_size = 0;

void dilation::doit(int max_elem, int max_kernel_size, String filename)
{
    //string ad_image;
    //load the image ; 
    //cout << "Please give me the image property " << endl;
    //cin >> ad_image; 
    im_source = imread(filename, IMREAD_UNCHANGED);
    // the case if the image is empty 
    if (im_source.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        //  cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return;
    }

    string windowName = "Dilation Demo";

    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, im_source);
    moveWindow(windowName, 0, 0);


    //use a trackbar to control the size of an image.
    //The first trackbar "Element" returns dilation_elem
    createTrackbar("Element:\n 0: Rect \n 1: Cross \n 2: Ellipse", windowName,
        &dilation_elem, max_elem,
        dilation::Dilation, this);
    // "Kernel size" return dilation_size for the corresponding operation.
    createTrackbar("Kernel size:\n 2n +1", windowName,
        &dilation_size, max_kernel_size,
        dilation::Dilation, this);

    // Call once dilation and erosion to show the initial image.
    // les zone sombre s'ecralicisse avec la dilatation 
//  Dilation(0, 0);

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
    imshow("Dilation Demo", src->dilation_dst);
}
