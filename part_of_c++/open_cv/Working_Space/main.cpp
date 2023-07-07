#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


int main()
{
    string path = "Resources/test.png";
    Mat img = imread(path);
    Mat imgGray;

    cvtColor(img, imgGray, COLOR_BGR2GRAY);

    imshow("Image", img);
    imshow("Image Gray", imgGray);
    waitKey(0);

    return 0;
}


