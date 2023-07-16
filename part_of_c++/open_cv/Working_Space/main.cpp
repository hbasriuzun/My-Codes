#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

int main() {
    std::string path = "Resources/shapes.png";
    cv::Mat img = imread(path);

    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
    Canny(imgBlur, imgCanny, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDil, kernel);
    erode(imgDil, imgErode, kernel);


    cv::imshow("Image", img);
    // cv::imshow("Image Gray", imgGray);
    // cv::imshow("Image Blur", imgBlur);
    // cv::imshow("Image Canny", imgCanny);
    // cv::imshow("Image Dil", imgDil);
    // cv::imshow("Image Erode", imgErode);


    cv::waitKey(1);
    
    


    return 0;
}
