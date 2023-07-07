#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

///////////////// İMAGE ///////////////////////

// int main()
// {
//     string path = "Resources/test.png";
//     Mat img = imread(path);
//     imshow("Image", img);
//     waitKey(0);

//     return 0;
// }

///////////////// VIDEO ///////////////////////

// int main()
// {
//     string path = "Resources/test_video.mp4";

//     VideoCapture cap(path);
//     Mat img;

//     while(true){

//         cap.read(img);

//         imshow("Image", img);
//         waitKey(1);
//     }
    

//     return 0;
// }

///////////////// WEBCAM ///////////////////////

int main()
{

    VideoCapture cap(0);
    Mat img;

    while(true){

        cap.read(img);

        imshow("Image", img);
        waitKey(1);
    }
    

    return 0;
}
