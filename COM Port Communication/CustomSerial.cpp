#include "CustomSerial.h"

int Serial::CustomSerial(char* ComPort, DWORD BaudRate) {
	IsConnected = false;

	hCom = CreateFileA(static_cast<LPCSTR>(ComPort),
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hCom == INVALID_HANDLE_VALUE) {
		if (GetLastError() == ERROR_FILE_NOT_FOUND) {
			printf("W: %s not available\n", ComPort);
			return 0;
		}
	}
	else {
		DCB dcb = { 0 };
		if (!GetCommState(hCom, &dcb)) {
			printf("W: didnt get com state");
			return 0;
		}
		else 
		{
			dcb.BaudRate = BaudRate;
			dcb.ByteSize = 8;
			dcb.StopBits = ONESTOPBIT;
			dcb.Parity = NOPARITY;
			dcb.fDtrControl = DTR_CONTROL_ENABLE;
			if (!SetCommState(hCom, &dcb)) {
				printf("W: could not set dcb\n");
				return 0;
			}
			else {
				IsConnected = true;
				PurgeComm(hCom, PURGE_RXCLEAR | PURGE_TXCLEAR);
			}
		}
	}
	return 1;
}

char Serial::Read() {

	DWORD bytes_read;
	char inc_msg[1] ={ 0 };
	bool began = false;

	ClearCommError(hCom, &errors, &status);

	while (!began) {
		if (ReadFile(hCom, inc_msg, 1, &bytes_read, NULL)) {
			began = 1;
		}
	}
	return inc_msg[0];
}

int Serial::Close() {
	if (IsConnected) {
		IsConnected = 0;
		CloseHandle(hCom);
		return 1;
	}
	else {
		return 0;
	}
}

int Serial::Write(char* data_sent)
{
	DWORD bytes_sent;

	unsigned int data_sent_length = strlen(data_sent);

	if (!WriteFile(hCom, (void*)data_sent, data_sent_length, &bytes_sent, NULL)) {
		ClearCommError(hCom, &errors, &status);
		return false;
	}
	else {
		return true;
	}
}