#include <iostream>
#include <frog/Tello++.cpp>//change to however you want, but instead of dll im using this way
#include <array>
#include <windows.h>

std::array<int, 4> keyCheck(fr::TelloSDK13 tello) {
    std::array<int, 4> m = {0, 0, 0, 0};
    int s = 100;
    if(GetAsyncKeyState('D')) {
        m[0] = s;
    }
    if(GetAsyncKeyState('A')) {
        m[0] = -s;
    }
    if(GetAsyncKeyState('W')) {
        m[1] = s;
    }
    if(GetAsyncKeyState('S')) {
        m[1] = -s;
    }
    if(GetAsyncKeyState('E')) {
        tello.takeoff();
    }
    if(GetAsyncKeyState('1')) {
        tello.land();
    }
    if(GetAsyncKeyState(VK_UP)) {
        m[2] = s;
    }
    if(GetAsyncKeyState(VK_DOWN)) {
        m[2] = -s;
    }
    if(GetAsyncKeyState(VK_LEFT)) {
        m[3] = -s;
    }
    if(GetAsyncKeyState(VK_RIGHT)) {
        m[3] = s;
    }
    if(GetAsyncKeyState('F')) {
        tello.flip_forward();
    }
    if(GetAsyncKeyState('B')) {
        tello.flip_back();
    }
    if(GetAsyncKeyState('R')) {
        tello.flip_right();
    }
    if(GetAsyncKeyState('L')) {
        tello.flip_right();
    }
    if(GetAsyncKeyState(VK_ESCAPE)) {
        tello.land();
        Sleep(3000);
        tello.close();
    }
    return m;
}

int main() {
    fr::TelloSDK13 tello;
    tello.connect();
    tello.streamon();
    std::array<int, 4> k;
    while(true) {
        k = keyCheck(tello);

        if(k[0] != 0 || k[1] != 0 || k[2] != 0 || k[3] != 0) {
            tello.setRC(k[0], k[1], k[2], k[3]);
        }
        else {
            k[0] = 0, k[1] = 0, k[2] = 0, k[3] = 0;
            tello.setRC(k[0], k[1], k[2], k[3]);
        }
        Sleep(10);//VERY IMPORTANT, PROBLEM WITH PAST EXAMPLES WAS NOT USING "Sleep(any)", WITHOUT THIS IT CAUSES THE DRONE TO RESPOND TO MESSAGES VERY LATE, WHICH CAUSES DRONE CRASHES
    }
}
