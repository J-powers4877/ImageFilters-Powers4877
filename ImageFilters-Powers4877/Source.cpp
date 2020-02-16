#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat mBicycle = imread("../bicycle.bmp");
    Mat mDog = imread("../dog.bmp");
    Mat mEdge = imread("../edge_L-150x150.png");
    Mat mSouth = imread("../south_L-150x150.png");

    Mat mChanged;

    Mat Sobelx;
    Mat Sobely;

    Mat kernal;
    Mat kernal2;

    Mat kernal3;
    Mat kernal4;

    Mat Test1;
    Mat Test2;
    Mat Test3;

    Mat kernal5;

    String windowName;

    if (mBicycle.empty() || mDog.empty() || mEdge.empty() || mSouth.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get();
        return -1;
    }

    //TODO: Rearrange positioning
    int iKernelSize3x3 = 3;
    m3BoxKernel = Mat::ones(iKernelSize3x3, iKernelSize3x3, CV_32F) / (float)(iKernelSize3x3 * iKernelSize3x3);

    int kernal_size2 = 7;
    kernal2 = Mat::ones(kernal_size2, kernal_size2, CV_32F) / (float)(kernal_size2 * kernal_size2);

    m3YSobelKernel = (Mat_<float>(3, 3) << 
        -1, 0, 1, 
        -2, 0, 2, 
        -1, 0, 1);

    m3XSobelKernel = (Mat_<float>(3, 3) << 
       -1, -2, -1, 
        0,  0,  0, 
        1,  2,  1);

    m7XSobelKernel = (Mat_<float>(7, 7) <<
        -1, -1, -1, -2, -1, -1, -1,
        -1, -1, -1, -2, -1, -1, -1,
        -1, -1, -1, -2, -1, -1, -1,
         0,  0,  0,  0,  0,  0,  0,
         1,  1,  1,  2,  1,  1,  1,
         1,  1,  1,  2,  1,  1,  1,
         1,  1,  1,  2,  1,  1,  1);

    m7YSobelKernel = (Mat_<float>(7, 7) <<
        -1, -1, -1, 0,  1,  1,  1,
        -1, -1, -1, 0,  1,  1,  1,
        -1, -1, -1, 0,  1,  1,  1,
        -2, -2, -2, 0,  2,  2,  2,
        -1, -1, -1, 0,  1,  1,  1,
        -1, -1, -1, 0,  1,  1,  1,
        -1, -1, -1, 0,  1,  1,  1);

    //TODO: Figure out how this works
    addWeighted(m3YSobelKernel, 0.5, m3XSobelKernel, 0.5, 0, m3XYSobelKernel);
    addWeighted(m7XSobelKernel, 0.5, m7YSobelKernel, 0.5, 0, m7XYSobelKernel);

    cout << "Press any key after each photo to display the next." << endl;
    cout << "The windows will be destroyed after each time. Only continue when pleased." << endl;
    cout << endl;
    cout << "Press enter to continue." << endl;
    cin.get();

    //TODO: Comment lines correctly, structure each correctly.

    sWindowName = "The Original Bicycle";
    namedWindow(sWindowName);
    imshow(sWindowName, mBicycle);

    sWindowName = "Bicycle: OpenCV Box (3x3)";
    boxFilter(mBicycle, mChanged, -1, Size(3, 3));
    namedWindow(sWindowName);
    imshow(sWindowName, mChanged);

    sWindowName = "Bicycle: Created Box (3x3)";
    filter2D(mBicycle, mChanged, -1, m3BoxKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName);
    imshow(sWindowName, mChanged);

    sWindowName = "Bicycle: OpenCV Box (7x7)";
    boxFilter(mBicycle, mChanged, -1, Size(7, 7));
    namedWindow(sWindowName);
    imshow(sWindowName, mChanged);

    sWindowName = "Bicycle: Created Box (7x7)";
    filter2D(mBicycle, mChanged, -1, m7BoxKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName);
    imshow(sWindowName, mChanged);
    
    sWindowName = "Bicycle: OpenCV Sobel (3x3)";
    Sobel(mBicycle, mChanged, -1, 1, 1, 3);
    namedWindow(sWindowName);
    imshow(sWindowName, mChanged);
    
    sWindowName = "Bicycle: Created Soble X (3x3)";
    filter2D(mBicycle, mSobelX, -1, m3XSobelKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName);
    imshow(sWindowName, mSobelX);
    
    sWindowName = "Bicycle: Created Soble Y (3x3)";
    filter2D(mBicycle, mSobelY, -1, m3YSobelKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName);
    imshow(sWindowName, mSobelY);
    
    sWindowName = "Bicycle: Created XY (3x3)";
    filter2D(mBicycle, mChanged, -1, m3XYSobelKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName);
    imshow(sWindowName, mChanged);

    sWindowName = "Bicycle: OpenCV Sobel (7x7)";
    Sobel(mBicycle, mChanged, -1, 1, 1, 7);
    namedWindow(sWindowName);
    imshow(sWindowName, mChanged);

    sWindowName = "Bicycle: Created Soble X (7x7)";
    filter2D(mBicycle, mSobelX, -1, m7XSobelKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName);
    imshow(sWindowName, mSobelX);

    sWindowName = "Bicycle: Created Soble Y (7x7)";
    filter2D(mBicycle, mSobelY, -1, m7YSobelKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName);
    imshow(sWindowName, mSobelY);

    sWindowName = "Bicycle: Created Soble XY (7x7)";
    filter2D(mBicycle, mChanged, -1, m7XYSobelKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName);
    imshow(sWindowName, mChanged);

    sWindowName = "Bicycle: OpenCV Gaussian (3x3)";
    GaussianBlur(mBicycle, mChanged, Size(3, 3), 0);
    namedWindow(sWindowName);
    imshow(sWindowName, mChanged);

    sWindowName = "Bicycle: OpenCV Gaussian (7x7)";
    GaussianBlur(mBicycle, mChanged, Size(7, 7), 0);
    namedWindow(sWindowName);
    imshow(sWindowName, mChanged);
    waitKey(0);


    //TODO: Add Created Sobel to each, restructure
    //windowName = "Bicycle: OpenCV Sobel (7x7)";
    //Sobel(mBicycle, mChanged, -1, 1, 1, 7);
    //namedWindow(windowName);
    //imshow(windowName, mChanged);

    //windowName = "Bicycle: OpenCV Box (3x3)";
    //boxFilter(mBicycle, mChanged, -1, Size(3, 3));
    //namedWindow(windowName);
    //imshow(windowName, mChanged);
    //
    //windowName = "Bicycle: Created Box (3x3)";
    //filter2D(mBicycle, mChanged, -1, kernal, Point(-1, -1), 0, BORDER_DEFAULT);
    //namedWindow(windowName);
    //imshow(windowName, mChanged);
    //
    //windowName = "Bicycle: OpenCV Box (7x7)";
    //boxFilter(mBicycle, mChanged, -1, Size(7, 7));
    //namedWindow(windowName);
    //imshow(windowName, mChanged);
    //
    //windowName = "Bicycle: Created Box (7x7)";
    //filter2D(mBicycle, mChanged, -1, kernal2, Point(-1, -1), 0, BORDER_DEFAULT);
    //namedWindow(windowName);
    //imshow(windowName, mChanged);

    //windowName = "Bicycle: OpenCV Gaussian (3x3)";
    //GaussianBlur(mBicycle, mChanged, Size(3, 3), 0);
    //namedWindow(windowName);
    //imshow(windowName, mChanged);

    //windowName = "Bicycle: OpenCV Gaussian (7x7)";
    //GaussianBlur(mBicycle, mChanged, Size(7, 7), 0);
    //namedWindow(windowName);
    //imshow(windowName, mChanged);
    //waitKey(0);

    //destroyAllWindows();

    ////Start Dog
    //windowName = "The Original Dog";
    //namedWindow(windowName);
    //imshow(windowName, mDog);

    //windowName = "Dog: OpenCV Sobel (3x3)";
    //Sobel(mDog, mChanged, -1, 1, 1, 3);
    //namedWindow(windowName);
    //imshow(windowName, mChanged);

    //windowName = "Dog: OpenCV Sobel (7x7)";
    //Sobel(mDog, mChanged, -1, 1, 1, 7);
    //namedWindow(windowName);
    //imshow(windowName, mChanged);

    //windowName = "Dog: OpenCV Box (3x3)";
    //boxFilter(mDog, mChanged, -1, Size(3, 3));
    //namedWindow(windowName);
    //imshow(windowName, mChanged);

    //windowName = "Dog: OpenCV Box (7x7)";
    //boxFilter(mDog, mChanged, -1, Size(7, 7));
    //namedWindow(windowName);
    //imshow(windowName, mChanged);

    //windowName = "Dog: OpenCV Gaussian (3x3)";
    //GaussianBlur(mDog, mChanged, Size(3, 3), 0);
    //namedWindow(windowName);
    //imshow(windowName, mChanged);

    //windowName = "Dog: OpenCV Gaussian (7x7)";
    //GaussianBlur(mDog, mChanged, Size(7, 7), 0);
    //namedWindow(windowName);
    //imshow(windowName, mChanged);
    //waitKey(0);

    sWindowName = "Dog: Created Soble XY (7x7)";
    filter2D(mDog, mChanged, -1, m7XYSobelKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName);
    imshow(sWindowName, mChanged);

    sWindowName = "Dog: OpenCV Gaussian (3x3)";
    GaussianBlur(mDog, mChanged, Size(3, 3), 0);
    namedWindow(sWindowName);
    imshow(sWindowName, mChanged);

    sWindowName = "Dog: OpenCV Gaussian (7x7)";
    GaussianBlur(mDog, mChanged, Size(7, 7), 0);
    namedWindow(sWindowName);
    imshow(sWindowName, mChanged);
    waitKey(0);

    destroyAllWindows();
    
    //Start Edge
    sWindowName = "The Original Edge";
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mEdge);

    sWindowName = "Edge: OpenCV Box (3x3)";
    boxFilter(mEdge, mChanged, -1, Size(3, 3));
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mChanged);

    sWindowName = "Edge: Created Box (3x3)";
    filter2D(mEdge, mChanged, -1, m3BoxKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mChanged);

    sWindowName = "Edge: OpenCV Box (7x7)";
    boxFilter(mEdge, mChanged, -1, Size(7, 7));
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mChanged);

    sWindowName = "Edge: Created Box (7x7)";
    filter2D(mEdge, mChanged, -1, m7BoxKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mChanged);

    sWindowName = "Edge: OpenCV Sobel (3x3)";
    Sobel(mEdge, mChanged, -1, 1, 1, 3);
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mChanged);

    sWindowName = "Edge: Created Soble X (3x3)";
    filter2D(mEdge, mSobelX, -1, m3XSobelKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mChanged);

    sWindowName = "Edge: Created Soble Y (3x3)";
    filter2D(mEdge, mSobelY, -1, m3YSobelKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mChanged);

    sWindowName = "Edge: Created XY (3x3)";
    filter2D(mEdge, mChanged, -1, m3XYSobelKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mChanged);

    sWindowName = "Edge: OpenCV Sobel (7x7)";
    Sobel(mEdge, mChanged, -1, 1, 1, 7);
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mChanged);

    sWindowName = "Edge: Created Soble X (7x7)";
    filter2D(mEdge, mSobelX, -1, m7XSobelKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mSobelX);

    sWindowName = "Edge: Created Soble Y (7x7)";
    filter2D(mEdge, mSobelY, -1, m7YSobelKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mSobelY);

    sWindowName = "Edge: Created Soble XY (7x7)";
    filter2D(mEdge, mChanged, -1, m7XYSobelKernel, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mChanged);

    sWindowName = "Edge: OpenCV Gaussian (3x3)";
    GaussianBlur(mEdge, mChanged, Size(3, 3), 0);
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mChanged);

    sWindowName = "Edge: OpenCV Gaussian (7x7)";
    GaussianBlur(mEdge, mChanged, Size(7, 7), 0);
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mChanged);    
    waitKey(0);

    destroyAllWindows();
    
    //Start South
    sWindowName = "The Original South";
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mSouth);

    sWindowName = "South: OpenCV Box (3x3)";
    boxFilter(mSouth, mChanged, -1, Size(3, 3));
    namedWindow(sWindowName, WINDOW_NORMAL);
    resizeWindow(sWindowName, 400, 400);
    imshow(sWindowName, mChanged);

    //windowName = "Edge: OpenCV Sobel (3x3)";
    //Sobel(mEdge, mChanged, -1, 1, 1, 3);
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mChanged);

    //windowName = "Edge: OpenCV Sobel (7x7)";
    //Sobel(mEdge, mChanged, -1, 1, 1, 7);
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mChanged);

    //windowName = "Edge: OpenCV Box (3x3)";
    //boxFilter(mEdge, mChanged, -1, Size(3, 3));
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mChanged);

    //windowName = "Edge: OpenCV Box (7x7)";
    //boxFilter(mEdge, mChanged, -1, Size(7, 7));
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mChanged);

    //windowName = "Edge: OpenCV Gaussian (3x3)";
    //GaussianBlur(mEdge, mChanged, Size(3, 3), 0);
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mChanged);

    //windowName = "Edge: OpenCV Gaussian (7x7)";
    //GaussianBlur(mEdge, mChanged, Size(7, 7), 0);
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mChanged);
    //waitKey(0);

    //destroyAllWindows();
    //
    ////Start South
    //windowName = "The Original South";
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mSouth);

    //windowName = "South: OpenCV Sobel (3x3)";
    //Sobel(mSouth, mChanged, -1, 1, 1, 3);
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mChanged);

    //windowName = "South: OpenCV Sobel (7x7)";
    //Sobel(mSouth, mChanged, -1, 1, 1, 7);
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mChanged);

    //windowName = "South: OpenCV Box (3x3)";
    //boxFilter(mSouth, mChanged, -1, Size(3, 3));
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mChanged);

    //windowName = "South: OpenCV Box (7x7)";
    //boxFilter(mSouth, mChanged, -1, Size(7, 7));
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mChanged);

    //windowName = "South: OpenCV Gaussian (3x3)";
    //GaussianBlur(mSouth, mChanged, Size(3, 3), 0);
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mChanged);

    //windowName = "South: OpenCV Gaussian (7x7)";
    //GaussianBlur(mSouth, mChanged, Size(7, 7), 0);
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mChanged);
    //waitKey(0);

    //destroyAllWindows();

    return 0;
}