#pragma once

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <chrono>
#include <thread>
#include <time.h>
#include <fstream>

class Serial {
private:
    HANDLE hCom = 0;
    COMSTAT status = { 0 };
    DWORD errors = 0;

public:
    Serial() {std::cout << "\n";}
    int CustomSerial(char* com_port, DWORD COM_BAUD_RATE);
    char Read();
    int Close();
    int Write(char* data_sent);
    int IsConnected = 0;
};