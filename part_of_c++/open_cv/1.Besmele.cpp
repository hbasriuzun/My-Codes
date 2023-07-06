#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    cv::Mat img = cv::imread("resim.jpg");
    cv::imshow("resim", img);
    cv::waitKey(0);
    return 0;
}
```