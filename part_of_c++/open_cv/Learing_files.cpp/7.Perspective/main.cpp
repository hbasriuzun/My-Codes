#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>

const int width = 250, height = 350;
cv::Mat imgWarp, matrix;

using namespace std;
using namespace cv;

int main() {
    std::string path = "Resources/cards.jpg";
    cv::Mat img = imread(path);

    cv::Point2f src[4] = {{529, 142}, {771, 190}, {405, 395}, {674, 457}};
    cv::Point2f dst[4] = {{0.0f, 0.0f}, {width, 0.0f}, {0.0f, height}, {width, height}};

    matrix = cv::getPerspectiveTransform(src, dst);
    cv::warpPerspective(img, imgWarp, matrix, cv::Point(width, height));

    for(int i = 0; i < 4; i++){
        cv::circle(img, src[i], 10, cv::Scalar(0, 0, 255), cv::FILLED);
    }

    cv::imshow("Image", img);
    cv::imshow("Image Warp", imgWarp);
    cv::waitKey(0);


    return 0;
}
