#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


int main()
{
    string path = "Resources/Burcu.jpeg";
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
    
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(img, imgBlur, Size(5,5), 5, 0);
    Canny(imgBlur, imgCanny, 50, 150);

      
    dilate(imgCanny, imgDil, getStructuringElement(MORPH_RECT, Size(5,5)));

    imshow("Image", img);
    imshow("Image Gray", imgGray);
    imshow("Image Blur", imgBlur);
    imshow("Image Canny", imgCanny);
    imshow("Image Dilate", imgDil);

    waitKey(0);

    return 0;
}


