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
#include <array>
#define HistoryLength 32
#define ResetCharInput 0

class Handlers {
private:

public:
    Handlers(){std::cout << "\n";}
    int CommandHandler(Handlers H);
    int ClearInput(Handlers H);
    int CommandList(Handlers H);
    int Error = 0;
    std::array <char, HistoryLength> Input{};
    int NICounter = -1;
    std::string Output{};
    int OutputNeeded = 0;
    char LatestInput = 0;
    

};