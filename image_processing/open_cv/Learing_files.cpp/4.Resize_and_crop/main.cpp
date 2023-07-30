#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#define endl "\n"
using namespace cv;
using namespace std;

/////////////// Resize and Crop //////////////

int main()
{
    string path = "Resources/Burcu.jpeg";
    Mat img = imread(path), imgResize, imgCrop;
    
    cout << img.size() << endl;

    resize(img, imgResize, Size(), 0.5, 0.5);

    Rect roi(100, 100, 300, 250);
    imgCrop = imgResize(roi);
    
    imshow("Image", img);
    imshow("Image Resize", imgResize);
    imshow("Image Crop", imgCrop);

    waitKey(0);

    return 0;
}


