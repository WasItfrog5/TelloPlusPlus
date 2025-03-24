/*⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣠⠞⣉⡭⣭⡙⢦⡀⢀⡴⢛⣩⢭⣍⠳⣆⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢰⠇⣼⣿⣿⣶⠹⡆⠛⠚⢡⣿⣿⣿⡎⢳⠘⡇⠀⠀⠀⠀
⠀⠀⠀⠀⠘⣇⠻⣟⠟⢋⣼⠃⠀⠀⠈⢯⡛⠛⣁⡾⢠⠇⠀⠀⠀⠀
⠀⠀⠀⠀⣸⠋⠀⠈⠉⠉⠀⠀⠀⠀⠀⠀⠉⠉⠁⠀⠈⢧⠀⠀⠀⠀
⠀⠀⠀⠀⣯⠀⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠀⢸⠀⠀⠀⠀
⠀⠀⠀⠀⠸⣆⠀⠈⠑⠲⠤⣄⣀⣀⣀⣠⠴⠚⠁⠀⣠⠏⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⣳⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⠋⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢰⠃⠀⠉⠙⣲⠶⠶⠶⠶⣖⠋⠉⠀⠘⣦⠀⠀⠀⠀⠀
⢀⣤⠖⠲⢤⡟⠀⠀⠀⡼⠁⠀⠀⠀⠀⠈⢳⡀⠀⠀⢹⣠⠶⠲⢤⡀
⡾⠀⠀⠀⠈⡇⠀⠀⢸⡃⠀⠀⠀⠀⠀⠀⠈⡇⠀⠀⢸⠇⠀⠀⠀⢻
⢳⡀⠀⠀⠀⢿⠀⠀⠈⣧⠀⠀⠀⠀⠀⠀⣰⠇⠀⠀⣼⠀⠀⠀⢀⡼
⠀⠙⢦⣀⠀⢈⣧⠀⠀⠈⠳⣄⣀⣀⣠⠴⠃⠀⠀⣰⡃⠀⢀⡴⠛⠀
⠀⠀⣴⣺⢗⣉⣁⣀⣀⣀⡶⠤⠤⠤⠤⠶⣆⢀⣀⣀⣉⡻⣟⣦⡀⠀
⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀

a cute frog
*/
//made by frog5, dont use as your own or do idrc
#define WIN32_LEAN_AND_MEAN
#include "Tello++1.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <iostream>
#include <cstring>
#include <cmath>
WSADATA data;
//WSAStartup(MAKEWORD(2,2), &data);
SOCKET sock = INVALID_SOCKET;
sockaddr_in server;
//server.sin_family = AF_INET;
std::string message_431295;
const int bufferSize_12389543 = 1024;
char buffer_71205643[bufferSize_12389543];
char buffer_41205643[bufferSize_12389543];
sockaddr_in from;
int fromLen = sizeof(from);
sockaddr_in from1;
int fromLen1 = sizeof(from1);

//first SDK1.3
//sending and receiving first
int fr::TelloSDK13::connect() {
    WSAStartup(MAKEWORD(2,2), &data);
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("192.168.10.1");
    server.sin_port = htons(SendReceive);
    from.sin_family = AF_INET;
    from.sin_addr.s_addr = htonl(INADDR_ANY);
    from.sin_port = htons(ReceiveState);

    from1.sin_family = AF_INET;
    from1.sin_addr.s_addr = htonl(INADDR_ANY);
    from1.sin_port = htons(SendReceive);
    std::string customCommand = "command";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
//ok sdk2.0 here
int fr::TelloSDK20::connect() {
    WSAStartup(MAKEWORD(2,2), &data);
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("192.168.10.1");
    server.sin_port = htons(SendReceive);
    from.sin_family = AF_INET;
    from.sin_addr.s_addr = htonl(INADDR_ANY);
    from.sin_port = htons(ReceiveState);

    from1.sin_family = AF_INET;
    from1.sin_addr.s_addr = htonl(INADDR_ANY);
    from1.sin_port = htons(SendReceive);
    std::string customCommand = "command";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
/*int fr::TelloSDK13::init() { //i wont use this for default, you can, but its easier to send "command" with connect(), it makes this simpler
    std::string customCommand = "command";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};*/
//some other things

int fr::TelloSDK20::sendCustomMessage(std::string message) {
    sendto(sock, message.c_str(), message.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};

int fr::TelloSDK20::receiveState(char* buffer, int sizeofBuffer) { //8890
    memset(buffer, 0, sizeofBuffer);
    int received = recvfrom(sock, buffer, sizeof(buffer), 0, (sockaddr*)&from, &fromLen);
    return received;
};

int fr::TelloSDK20::receiveResponse(char* buffer, int sizeofBuffer) { //8889
    memset(buffer, 0, sizeofBuffer);
    int received = recvfrom(sock, buffer, sizeof(buffer), 0, (sockaddr*)&from1, &fromLen1);
    return received;
};

int fr::TelloSDK20::close() {
    closesocket(sock);
    WSACleanup();
    return 0;
};


//some other things sdk13
int fr::TelloSDK13::sendCustomMessage(std::string message) {
    sendto(sock, message.c_str(), message.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};

int fr::TelloSDK13::receiveState(char* buffer, int sizeofBuffer) {
    memset(buffer, 0, sizeofBuffer);
    int received = recvfrom(sock, buffer, sizeof(buffer), 0, (sockaddr*)&from, &fromLen);
    return received;
};

int fr::TelloSDK13::receiveResponse(char* buffer, int sizeofBuffer) {
    memset(buffer, 0, sizeofBuffer);
    int received = recvfrom(sock, buffer, sizeof(buffer), 0, (sockaddr*)&from1, &fromLen1);
    return received;
};

int fr::TelloSDK13::close() {
    closesocket(sock);
    WSACleanup();
    return 0;
};

int fr::TelloSDK13::takeoff() {
    std::string customCommand = "takeoff";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::land() {
    std::string customCommand = "land";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::streamon() {
    std::string customCommand = "streamon";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::streamoff() {
    std::string customCommand = "streamoff";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::emergency() {
    std::string customCommand = "emergency";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::up(int x) {
    std::string customCommand = "up " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::down(int x) {
    std::string customCommand = "down " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::left(int x) {
    std::string customCommand = "left " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::right(int x) {
    std::string customCommand = "right " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::forward(int x) {
    std::string customCommand = "forward " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::back(int x) {
    std::string customCommand = "back " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::rotate_clockwise(int x) {
    std::string customCommand = "cw " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::rotate_counter_clockwise(int x) {
    std::string customCommand = "ccw " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::flip_left() {
    std::string customCommand = "flip l";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::flip_right() {
    std::string customCommand = "flip r";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::flip_forward() {
    std::string customCommand = "flip f";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::flip_back() {
    std::string customCommand = "flip b";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::go(int x, int y, int z, int speed) {
    std::string customCommand = "go " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + " " + std::to_string(speed);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
double fr::TelloSDK13::getTimeTo(int x, int y, int z, int speed) {
    double formula1 = sqrt(x*x + y*y + z*z);
    double finalFormula = formula1/speed;
    return finalFormula;
};
double fr::TelloSDK13::getDistanceTo(int x, int y, int z, int speed) {
    double formula1 = sqrt(x*x + y*y + z*z);
    return formula1;
};
int fr::TelloSDK13::curve(int x1, int y1, int z1, int x2, int y2, int z2, int speed) {
    std::string customCommand = "curve " + std::to_string(x1) + " " + std::to_string(y1) + " " + std::to_string(z1) + " " + std::to_string(x2)+ " " + std::to_string(y2) +" " + std::to_string(z2) + " " + std::to_string(speed);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
//set commands
int fr::TelloSDK13::setSpeed(int x) {
    std::string customCommand = "speed " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::setRC(int a, int b, int c, int d) {
    std::string customCommand = "rc " + std::to_string(a) + " " + std::to_string(b) + " " +std::to_string(c) + " " + std::to_string(d);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::TelloWifi(std::string ssid, std::string password) {
    std::string customCommand = "wifi " + ssid + " " + password;
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::connectMeTo(std::string address) {
    server.sin_addr.s_addr = inet_addr(address.c_str());
    if(server.sin_addr.s_addr == INADDR_NONE) {
        MessageBoxW(NULL, L"Invalid IP Address", L"Tello++", MB_OK);
        return 1;
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(8889);
    return 0;
};
//read commands
int fr::TelloSDK13::getSpeed() {
    std::string customCommand = "speed?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    /*char* buffer1 = new char[1024];
    receiveState(buffer1);
    int Perc = std::atoi(buffer1);
    delete[] buffer1;
    return Perc;*/
    return 0;
};
int fr::TelloSDK13::getBattery() {
    std::string customCommand = "battery?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::getTime() {
    std::string customCommand = "time?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::getHeight() {
    std::string customCommand = "height?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::getTemp() {
    std::string customCommand = "temp?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::getAttitude() {
    std::string customCommand = "attitude?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::getBaro() {
    std::string customCommand = "baro?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::getAcceleration() {
    std::string customCommand = "acceleration?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::getTof() {
    std::string customCommand = "tof?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK13::getWifiSNR() {
    std::string customCommand = "wifi?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};






//SDK2.0 now
//sending and receiving first
/*int fr::TelloSDK20::init() { //i wont use this for default, you can, but its easier to send "command" with connect(), it makes this simpler
    std::string customCommand = "command";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};*/
int fr::TelloSDK20::takeoff() {
    std::string customCommand = "takeoff";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::land() {
    std::string customCommand = "land";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::streamon() {
    std::string customCommand = "streamon";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::streamoff() {
    std::string customCommand = "streamoff";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::emergency() {
    std::string customCommand = "emergency";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::up(int x) {
    std::string customCommand = "up " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::down(int x) {
    std::string customCommand = "down " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::left(int x) {
    std::string customCommand = "left " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::right(int x) {
    std::string customCommand = "right " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::forward(int x) {
    std::string customCommand = "forward " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::back(int x) {
    std::string customCommand = "back " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::rotate_clockwise(int x) {
    std::string customCommand = "cw " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::rotate_counter_clockwise(int x) {
    std::string customCommand = "ccw " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::flip_left() {
    std::string customCommand = "flip l";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::flip_right() {
    std::string customCommand = "flip r";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::flip_forward() {
    std::string customCommand = "flip f";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::flip_back() {
    std::string customCommand = "flip b";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::go(int x, int y, int z, int speed) {
    std::string customCommand = "go " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + " " + std::to_string(speed);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
double fr::TelloSDK20::getTimeTo(int x, int y, int z, int speed) {
    double formula1 = sqrt(x*x + y*y + z*z);
    double finalFormula = formula1/speed;
    return finalFormula;
};
double fr::TelloSDK20::getDistanceTo(int x, int y, int z, int speed) {
    double formula1 = sqrt(x*x + y*y + z*z);
    return formula1;
};
int fr::TelloSDK20::stop() {
    std::string customCommand = "stop";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::curve(int x1, int y1, int z1, int x2, int y2, int z2, int speed) {
    std::string customCommand = "curve " + std::to_string(x1) + " " + std::to_string(y1) + " " + std::to_string(z1) + " " + std::to_string(x2)+ " " + std::to_string(y2) +" " + std::to_string(z2) + " " + std::to_string(speed);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::goMissionPad(int x, int y, int z, int speed, std::string MissionPadId) {
    std::string customCommand = "go " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + " " + std::to_string(speed) + " " + MissionPadId;
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::curveMissionPad(int x1, int y1, int z1, int x2, int y2, int z2, int speed, std::string MissionPadId) {
    std::string customCommand = "curve " + std::to_string(x1) + " " + std::to_string(y1) + " " + std::to_string(z1) + " " + std::to_string(x2)+ " " + std::to_string(y2) +" " + std::to_string(z2) + " " + std::to_string(speed) + " " + MissionPadId;
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::jumpMissionPad(int x, int y, int z, int speed, std::string MissionPadId1, std::string MissionPadId2) {
    std::string customCommand = "jump " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + " " + std::to_string(speed) + " " + MissionPadId1 + " " + MissionPadId2;
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
//set commands
int fr::TelloSDK20::setSpeed(int x) {
    std::string customCommand = "speed " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::setRC(int a, int b, int c, int d) {
    std::string customCommand = "rc " + std::to_string(a) + " " + std::to_string(b) + " " +std::to_string(c) + " " + std::to_string(d);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::TelloWifi(std::string ssid, std::string password) {
    std::string customCommand = "wifi " + ssid + " " + password;
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::connectMeTo(std::string address) {
    server.sin_addr.s_addr = inet_addr(address.c_str());
    if(server.sin_addr.s_addr == INADDR_NONE) {
        MessageBoxW(NULL, L"Invalid IP Address", L"Tello++", MB_OK);
        return 1;
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(8889);
    return 0;
};
int fr::TelloSDK20::setMon() {
    std::string customCommand = "mon";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::setMoff() {
    std::string customCommand = "moff";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::setMdirection(int x) {
    std::string customCommand = "mdirection " + std::to_string(x);
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::setTelloAP(std::string ssid, std::string password) {
    std::string customCommand = "ap " + ssid +" "+password;
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
//read commands
int fr::TelloSDK20::getSpeed() {
    std::string customCommand = "speed?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::getBattery() {
    std::string customCommand = "battery?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::getTime() {
    std::string customCommand = "time?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::getWifiSNR() {
    std::string customCommand = "wifi?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::getSDK() {
    std::string customCommand = "sdk?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};
int fr::TelloSDK20::getSN() {
    std::string customCommand = "sn?";
    sendto(sock, customCommand.c_str(), customCommand.length(), 0, (sockaddr*)&server, sizeof(server));
    return 0;
};