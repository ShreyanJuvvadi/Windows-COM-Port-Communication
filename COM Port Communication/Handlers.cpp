#include "Handlers.h"
#include <tchar.h>
#include <cstring>
using namespace std;

int Handlers::CommandHandler(Handlers H) {
	int i = 0; 
	int temp = 0;
	Output.clear();
	OutputNeeded = CommandList(H);

	for (i = 0; i < H.Input.size(); i++)
	{
		if (Input[i] == NULL)
		{
			temp = i - 1;
			break;
		}
	}
	if (Input[temp] == 59)
	{
		ClearInput(H);
	}
	
	return OutputNeeded;
}


int Handlers::ClearInput(Handlers H) {
	int i = 0;
	for (i = 0; i < Input.size() - 1; i++)
	{
		Input[i] = ResetCharInput;
	}
	return 1;
}

int Handlers::CommandList(Handlers H) {
	if (std::strcmp(&Input[0], "working") == 0)
	{
		Output = "It works";
		return 1;
	}
	if (std::strcmp(&Input[0], "chrome") == 0)
	{
		string command = "start chrome https://www.google.com/";
		system(command.c_str());
		Output = "Chrome has launched";
		return 1;
	}
	return 0;

}

