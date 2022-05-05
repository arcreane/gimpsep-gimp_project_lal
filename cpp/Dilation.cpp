#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include "Dilation.h" 

using namespace cv;
using namespace std;



/* dilate = opération consiste à convoluer une image A avec un certain noyau ( B), */
/* il s(agit du noyau qui est une matrice 3*3 par defaut, we can choose the shape 
il existe different forme du noyau tq un rectangle, une ellipse ... 
element = noyaux auquel l'image va etre convoluer
il suffit de spécifier la taille de notre noyau et le point d'ancrage. S'il n'est pas spécifié, il est supposé être au centre.
*/ 

// des des 2 fonction interieur 
/* pour la dilattion, il faut faire grossir les regiosn claire de l'image , La zone claire de la lettre se dilate autour des régions noires du fond.
pour cela on : 
- balaye le noyau sur l'image 
- calcule la valeur du pixel recouvert par le noyau appele max_elem
- remplace le pixel de l'image a la position du point d'ancrage par max_elem */
// in the begining all the variable are worth 0 

int dilation_elem = 0;
int dilation_size = 0;

void dilation::doit(int max_elem, int max_kernel_size)
{
    //string ad_image;
    //load the image ; 
    //cout << "Please give me the image property " << endl;
    //cin >> ad_image; 
    im_source = imread("HappyFish.jpg", IMREAD_UNCHANGED);
    // the case if the image is empty 
    if (im_source.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
      //  cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return ;
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




