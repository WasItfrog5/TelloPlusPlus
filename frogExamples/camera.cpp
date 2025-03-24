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
	    int key = cv::waitKey(1) & 0xFF;
        std::cout << key << std::endl;
        if(key == 113) {//Q to take picture
            int currTime = time(0);
            cv::imwrite(std::to_string(currTime) + ".jpg", img);
            std::cout << "Picture taken: " << std::to_string(currTime) + ".jpg" << std::endl;
        }
        if(key == 27) {//esc to leave
            break;
        }
    }
    tello.close();
}
