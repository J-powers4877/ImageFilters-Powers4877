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

    String windowName;

    if (mBicycle.empty() || mDog.empty() || mEdge.empty() || mSouth.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get();
        return -1;
    }

    int iSwitch;

    cout << "Enter a number to choose a photo:" << endl;
    cout << "1: Dog" << endl;
    cout << "2: Bicycle" << endl;
    cout << "3: Edge?!?!" << endl;
    cout << "4: South?!?!" << endl;
    cin >> iSwitch;

    switch (iSwitch)
    {
    case 1:
        system("CLS");

        windowName = "The Bicycle";
        namedWindow(windowName);
        imshow(windowName, mBicycle);
        waitKey(0);

        break;
    case 2:
        system("CLS");

        windowName = "The Dog";
        namedWindow(windowName);
        imshow(windowName, mDog);
        waitKey(0);

        break;
    case 3:
        system("CLS");

        windowName = "The Edge";
        namedWindow(windowName);
        imshow(windowName, mEdge);
        waitKey(0);

        break;
    case 4:
        system("CLS");

        windowName = "The South";
        namedWindow(windowName);
        imshow(windowName, mSouth);
        waitKey(0);

        break;
    }

    destroyWindow(windowName);

    return 0;

    /*
    Mat mBicycle = imread("../bicycle.bmp");
    Mat mDog = imread("../dog.bmp");
    Mat mEdge = imread("../edge_L-150x150.png");
    Mat mSouth = imread("../south_L-150x150.png");

    if (mBicycle.empty() || mDog.empty() || mEdge.empty() || mSouth.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get();
        return -1;
    }

    String windowName1 = "The Bicycle";
    String windowName2 = "The Dog";
    String windowName3 = "The Edge";
    String windowName4 = "The South";
    String windowName5 = "The New Bicycle";

    Mat mNewBicycle;

    //boxFilter(mBicycle, mNewBicycle, -1, Size(3, 3));
    //boxFilter(mBicycle, mNewBicycle, -1, Size(7, 7));
    //Sobel(mBicycle, mNewBicycle, -1, 1, 1);
    //GaussianBlur(mBicycle, mNewBicycle, Size(3, 3), 0);
    //GaussianBlur(mBicycle, mNewBicycle, Size(7, 7), 0);

    namedWindow(windowName1);
    namedWindow(windowName2);
    namedWindow(windowName3);
    namedWindow(windowName4);
    namedWindow(windowName5);

    imshow(windowName1, mBicycle);
    imshow(windowName2, mDog);
    imshow(windowName3, mEdge);
    imshow(windowName4, mSouth);
    imshow(windowName5, mNewBicycle);

    waitKey(0);

    destroyWindow(windowName1);
    destroyWindow(windowName2);
    destroyWindow(windowName3);
    destroyWindow(windowName4);
    destroyWindow(windowName5);
    */
}