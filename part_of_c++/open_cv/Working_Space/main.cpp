#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#define endl "\n"
using namespace cv;
using namespace std;

/////////////// Basic Functions ///////////////

int main()
{
    string path = "Resources/Burcu.jpeg";
    Mat img = imread(path), imgResize, imgCrop;
    
    cout << img.size() << endl;

    resize(img, imgResize, Size(), 0.5, 0.5);
    
    imshow("Image", img);


    waitKey(0);

    return 0;
}


