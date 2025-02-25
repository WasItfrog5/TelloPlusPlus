#include <iostream>
#include <windows.h>//------------------------------for GetAsyncKeyState
#include <frog/Tello++.h>//-------------------------include library

//this is simple code for controlling the drone with wasd, arrow keys and space/ctrl using built in windows functions
//if you want to learn more, go through header file in include/frog and through tello SDK user guides (both 1.3 and 2.0 depending on your version)
//SDK1.3(SDK13 in this library): https://dl-cdn.ryzerobotics.com/downloads/tello/20180910/Tello%20SDK%20Documentation%20EN_1.3.pdf
//SDK2.0(SDK20 in this library): https://dl-cdn.ryzerobotics.com/downloads/Tello/Tello%20SDK%202.0%20User%20Guide.pdf

#define W_KEY 0x57
#define A_KEY 0x41
#define S_KEY 0x53
#define D_KEY 0x44
#define UP_ARROW 0x26
#define LEFT_ARROW 0x25
#define RIGHT_ARROW 0x27
#define DOWN_ARROW 0x28
#define SPACE_KEY 0x20
#define CTRL_KEY 0xA2
#define ESC_KEY 0x1B
#define T_KEY 0x54
#define Q_KEY 0x51
#define E_KEY 0x45

int main() {
    fr::TelloSDK13 tello;//-------------------------make tello class
    tello.connect();//------------------------------connect to tello's address and port and enter SDK mode
    while (true) {
        if (GetAsyncKeyState(T_KEY) & 0x8000) {//----T button pressed 
            tello.takeoff();//-----------------------tello takeoff
            std::cout << "TAKEOFF" << std::endl;
        }
        if (GetAsyncKeyState(Q_KEY) & 0x8000) {//----Q button pressed 
            tello.rotate_counter_clockwise(5);//-----rotate tello counter clockwise by 5 degrees
            std::cout << "ROTATING" << std::endl;
        }
        if (GetAsyncKeyState(E_KEY) & 0x8000) {//----E button pressed 
            tello.rotate_clockwise(5);//-------------rotate tello counter clockwise by 5 degrees
            std::cout << "ROTATING" << std::endl;
        }
        if (GetAsyncKeyState(W_KEY) & 0x8000) {//----W button pressed
            tello.forward(5);//----------------------move tello forward by 5cm
            std::cout << "W" << std::endl;
        }
        if (GetAsyncKeyState(A_KEY) & 0x8000) {//----A button pressed
            tello.left(5);//-------------------------move tello left by 5 cm
            std::cout << "A" << std::endl;
        }
        if (GetAsyncKeyState(D_KEY) & 0x8000) {//----D button pressed
            tello.right(5);//------------------------move tello right by 5 cm
            std::cout << "D" << std::endl;
        }
        if (GetAsyncKeyState(S_KEY) & 0x8000) {//----S button pressed
            tello.back(5);//-------------------------move tello back by 5 cm
            std::cout << "S" << std::endl;
        }

        if (GetAsyncKeyState(UP_ARROW) & 0x8000) {//----up arrow button pressed
            tello.flip_forward();//---------------------flip tello forward
        }
        if (GetAsyncKeyState(LEFT_ARROW) & 0x8000) {//--left arrow button pressed
            tello.flip_left();//------------------------flip tello left
        }
        if (GetAsyncKeyState(RIGHT_ARROW) & 0x8000) {//-right arrow button pressed
            tello.flip_right();//-----------------------flip tello right
        }
        if (GetAsyncKeyState(DOWN_ARROW) & 0x8000) {//--down arrow button pressed
            tello.flip_back();//------------------------flip tello back
        }

        if (GetAsyncKeyState(SPACE_KEY) & 0x8000) {//---space button pressed 
            tello.up(5);//------------------------------move tello up/fly up
        }
        if (GetAsyncKeyState(CTRL_KEY) & 0x8000) {//----ctrl button pressed 
            tello.down(5);//----------------------------move tello down/fly down
        }
        if (GetAsyncKeyState(ESC_KEY) & 0x8000) {//-----esc button pressed 
            tello.land();//-----------------------------lands the drone
            break;//------------------------------------breaks the loop
        }
        Sleep(10);//------------------------------------wait 10 miliseconds to prevent cpu overloading
        system("cls");//--------------------------------for clearing the screen (not needed)
    }
    tello.close();//------------------------------------please use this to prevent resource leaking and other unwanted things
}
