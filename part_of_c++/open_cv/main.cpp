#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    cv::Mat img = cv::imread("capybara.jpeg");
    if (img.empty()) {
        std::cout << "Görüntü yüklenemedi!" << std::endl;
        return -1;
    }

    cv::imshow("capybara", img);
    cv::waitKey(0);
    return 0;
}
