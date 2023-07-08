#include <opencv2/opencv.hpp>

int main() {
    // Cascade sınıflandırıcısını yükleyin
    cv::CascadeClassifier dogCascade;
    dogCascade.load("Resources/haarcascade_frontalcatface.xml");

    // Giriş video akışını açın
    cv::VideoCapture cap("Resources/dog_video.mp4");
    if (!cap.isOpened()) {
        std::cout << "Video açılamadı!" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (cap.read(frame)) {
        // Gri tonlamaya dönüştürün
        cv::Mat gray;
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        // Köpekleri algılayın
        std::vector<cv::Rect> dogs;
        dogCascade.detectMultiScale(gray, dogs, 1.1, 3, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

        // Algılanan köpekleri dikdörtgenle çerçeveleyin
        for (const cv::Rect& dog : dogs) {
            cv::rectangle(frame, dog, cv::Scalar(0, 255, 0), 2);
        }

        // Sonuçları gösterin
        cv::imshow("Köpek Algılama", frame);

        // Çıkış için ESC tuşuna basılıp basılmadığını kontrol edin
        if (cv::waitKey(10) == 27) {
            break;
        }
    }

    // Kaynakları serbest bırakın
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
