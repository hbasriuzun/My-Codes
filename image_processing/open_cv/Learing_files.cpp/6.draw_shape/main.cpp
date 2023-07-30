#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#define endl "\n"
using namespace cv;
using namespace std;

/////////////// draw shape //////////////

int main()
{
    string path = "Resources/Burcu.jpeg";
    Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
    
    circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
    rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
    line(img,Point(130,296), Point(382,296), Scalar(255, 255, 255), 2);

    putText(img, "Burcu", Point(137, 262), FONT_ITALIC, 0.75, Scalar(0, 69, 255), 2);

    imshow("Image", img);
   

    waitKey(0);

    return 0;
}


