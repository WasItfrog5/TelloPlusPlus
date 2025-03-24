#include <iostream>
#include <frog/Tello++.cpp>//----------------------include library (change to however you want, but instead of dll im using this way)
//this is simple code for controlling the drone with wasd, arrow keys and space/ctrl
//if you want to learn more, go through header file in include/frog and through tello SDK user guides (both 1.3 and 2.0 depending on your version)
//SDK1.3(SDK13 in this library): https://dl-cdn.ryzerobotics.com/downloads/tello/20180910/Tello%20SDK%20Documentation%20EN_1.3.pdf
//SDK2.0(SDK20 in this library): https://dl-cdn.ryzerobotics.com/downloads/Tello/Tello%20SDK%202.0%20User%20Guide.pdf

int main() {
    fr::TelloSDK13 tello;//-------------------------make tello class
    char buffer[1024];//----------------------------buffer for receiving data
    tello.connect();//------------------------------connect to tello's address and port and enter SDK mode
    tello.receiveResponse(buffer, sizeof(buffer));//-receive response from tello
    //we wont print it because it will be "ok" (responding to tello.connect()) and we dont need that
    while(true) {
        std::string customCommand;
        getline(std::cin, customCommand);
        if(customCommand == "close") {
            tello.close();//-------------------------------please use this to prevent resource leaking and other unwanted things
        }
        else {
            tello.sendCustomMessage(customCommand);//---------------------------send custom command to tello
            int receivedBytes = tello.receiveResponse(buffer, sizeof(buffer));//receive response from tello in bytes
            if(receivedBytes > 0) {
                std::cout << "Response: " << buffer << std::endl;//-------------print response (we dont put any wait functions here because receiveResponse functions already waits for response)
		//so if you dont understand why do we print char buffer instead of tello.receiveResponse or something, its because receiveResponse or receiveState changes buffer to be the received message
            }
            else {
                std::cout << "No response" << std::endl;//----------------------if no response is received
            }
        }
    }
    tello.close();//------------------------------------------------------------close the connection
}