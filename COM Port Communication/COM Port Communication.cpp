#include "Config.h"
#include "CustomSerial.h"
#include "Handlers.h"

#include <ctime>
#include <chrono>
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <thread>
using namespace std;

void loop(Serial com, Config cfg);
void errorhandler(Config cfg);

int main()
{
	int working = 0;
	Serial com;
	Config cfg;

	cout << cfg.ComPort << "\n";
	working = com.CustomSerial(cfg.ComPort,cfg.BaudRate);
	cout << "The port is " << com.IsConnected << "\n";
	

	if (working  == 1)
	{
		loop(com, cfg);
	}
	else 
	{
		cout << "Failed initializing";
	}

	return 0;
}

void loop(Serial com, Config cfg) {
	char temp = 0;
	int i = 0;
	Handlers H;
	time_t Time = time(nullptr);
	while (H.Error == 0) {
		H.LatestInput = com.Read();

		for (i = 0; i < H.Input.size() - 1; i++)
		{
			if (H.Input[i] == NULL) {
				H.Input[i] = H.LatestInput;
				break;
			}
		}

		H.NICounter++;
		if ((time(nullptr) - Time ) > cfg.WaitTime)
		{
			H.OutputNeeded = H.CommandHandler(H);
		}
		if (H.OutputNeeded == 1)
		{
			H.OutputNeeded = 0;
			com.Write(&H.Output[0]);
		}
		cout << "looping";

	}
	if (H.Error != 0)
	{
		errorhandler(cfg);
	}
}

void errorhandler(Config cfg) {
	cout << "error handler place holder\n";
}

