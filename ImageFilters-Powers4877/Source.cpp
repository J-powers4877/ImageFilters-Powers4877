#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    //TODO: Trim Mats, Rename to useful names
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
    int kernal_size = 3;
    kernal = Mat::ones(kernal_size, kernal_size, CV_32F) / (float)(kernal_size * kernal_size);

    int kernal_size2 = 7;
    kernal2 = Mat::ones(kernal_size2, kernal_size2, CV_32F) / (float)(kernal_size2 * kernal_size2);

    kernal3 = (Mat_<float>(3, 3) << 
        -1, 0, 1, 
        -2, 0, 2, 
        -1, 0, 1);

    kernal4 = (Mat_<float>(3, 3) << 
       -1, -2, -1, 
        0,  0,  0, 
        1,  2,  1);

    //TODO: Figure out how this works
    addWeighted(kernal3, 0.5, kernal4, 0.5, 0, Test3);

    cout << "Press any key after each photo to display the next." << endl;
    cout << "The windows will be destroyed after each time. Only continue when pleased." << endl;
    cout << endl;
    cout << "Press enter to continue." << endl;
    cin.get();

    //TODO: Comment lines correctly, structure each correctly.
    //Start Bike
    windowName = "The Original Bicycle";
    namedWindow(windowName);
    imshow(windowName, mBicycle);
    
    windowName = "Bicycle: OpenCV Sobel (3x3)";
    Sobel(mBicycle, mChanged, -1, 1, 1, 3);
    namedWindow(windowName);
    imshow(windowName, mChanged);
    
    windowName = "Bicycle: Created Soble X (3x3)";
    filter2D(mBicycle, Sobelx, -1, kernal3, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(windowName);
    imshow(windowName, mChanged);
    
    windowName = "Bicycle: Created Soble Y (3x3)";
    filter2D(mBicycle, Sobely, -1, kernal4, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(windowName);
    imshow(windowName, mChanged);
    
    windowName = "Bicycle: Created XY (3x3)";
    filter2D(mBicycle, mChanged, -1, Test3, Point(-1, -1), 0, BORDER_DEFAULT);
    namedWindow(windowName);
    imshow(windowName, mChanged);
    
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

    //destroyAllWindows();
    //
    ////Start Edge
    //windowName = "The Original Edge";
    //namedWindow(windowName, WINDOW_NORMAL);
    //resizeWindow(windowName, 400, 400);
    //imshow(windowName, mEdge);

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