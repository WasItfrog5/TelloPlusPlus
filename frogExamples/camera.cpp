#include <opencv2/opencv.hpp>
#include <frog/Tello++.cpp>

int main() {
    fr::TelloSDK13 tello;
    tello.connect();
    tello.streamon();
    cv::VideoCapture cap("udp://192.168.10.1:11111");
    cv::Mat img;
    while(true) {
        cap.read(img);
        cv::imshow("Tello Camera", img);
        if(cv::waitKey(1) == 27) {
            break;
        }
    }
    tello.close();
}
