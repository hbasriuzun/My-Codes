#include <opencv2/opencv.hpp>

int main() {
    // Cascade sınıflandırıcısını yükleyin
    cv::CascadeClassifier faceCascade;
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");

    // Giriş video akışını açın veya webcam'den alın
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cout << "Kamera açılamadı!" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        // Kameradan bir kare alın
        cap >> frame;

        // Gri tonlamaya dönüştürün
        cv::Mat gray;
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        // Yüzleri algılayın
        std::vector<cv::Rect> faces;
        faceCascade.detectMultiScale(gray, faces, 1.1, 3, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

        // Algılanan yüzleri dikdörtgenle çerçeveleyin
        for (const cv::Rect& face : faces) {
            cv::rectangle(frame, face, cv::Scalar(0, 255, 0), 2);
        }

        // Sonuçları gösterin
        cv::imshow("Yüz Algılama", frame);

        // Çıkış için ESC tuşuna basılıp basılmadığını kontrol edin
        if (cv::waitKey(1) == 27) {
            break;
        }
    }

    // Kaynakları serbest bırakın
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
