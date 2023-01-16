#pragma once
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <chrono>
#include <thread>
#include <time.h>
#include <fstream>
#include <Windows.h>
#include <string>

class Config {
private:

public:
	Config() { std::cout << "\n";}
	char ComPort[5] = "COM3";
	DWORD BaudRate = CBR_9600;
	int WaitTime = 0;
};