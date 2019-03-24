#include <iostream>
#include <Windows.h>

using namespace std;

int main(int argc, char* argv[])
{
	char dllpath[] = "C:\\Users\\QuocC\\Desktop\\Dll4.dll";
	HMODULE hKernel32 = ::GetModuleHandle("Kernel32");

	HWND hWnd = FindWindow(NULL, "C:\\Users\\QuocC\\Desktop\\LOLCuong.exe");
	std::cout << "Finded handle: " << hWnd << '\n';

	DWORD id;
	GetWindowThreadProcessId(hWnd, &id);
	std::cout << "Thread id: " << id << "\n";

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, id);
	std::cout << "HANDLE Process to control Process: " << hProcess << '\n';

	void* pLibAddress = VirtualAllocEx(hProcess, NULL, sizeof(dllpath),
		MEM_COMMIT, PAGE_READWRITE);

	bool isOK = WriteProcessMemory(hProcess, pLibAddress, (void*)dllpath, 
		sizeof(dllpath), NULL);

	std::cout << "Check writed memory: " << isOK << "\n";

	#pragma region copy

	HANDLE hRemoteThread = ::CreateRemoteThread(hProcess, NULL, 0,
		(LPTHREAD_START_ROUTINE)::GetProcAddress(hKernel32, "LoadLibraryA"),
		pLibAddress, 0, NULL);

	//GetProcAddress()

	WaitForSingleObject(hRemoteThread, INFINITE);

	// Get handle of the loaded module
	DWORD hLibModule;
	GetExitCodeThread(hRemoteThread, &hLibModule);

	//void (*p)() =(void (__cdecl*)()) GetProcAddress((HMODULE)hLibModule, "test");
	//std::cout << hLibModule;
	//p();
	// release memory
	CloseHandle(hRemoteThread);
	VirtualFreeEx(hProcess, pLibAddress, sizeof(dllpath), MEM_RELEASE);
	#pragma endregion copy
	system("pause");
	return 0;
}