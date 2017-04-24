#pragma once
//did not get the idea from the github or anything nepBaka

#include <vector>
#include <regex>
#include <iostream>
#include "Weapons_list.h"
namespace Utils {

	int Weaponfcs()
	{
		srand(clock());
		int Weapoond;
		int count = static_cast<int>(WeaponList.size());
		int RandomWeaponIndex = rand() % count;

		Weapoond = stoi(WeaponList[RandomWeaponIndex]);
		return Weapoond;

	}
	int UpgradeLevel(int weap, bool off)
	{
		int min;
		int max;
		bool isbossweapon = false;
		int UpgradeLevel;
		for (int i = 0; i < BossList.size(); i++) {
			int woof = stoi(BossList[i]);
			if (weap == woof) { isbossweapon = true; }
		}
		if(isbossweapon == true && off == false)
		{ 
			UpgradeLevel = rand() % 6;
		}
		if(isbossweapon == false && off == false)
		{
			UpgradeLevel = rand() % 11;
		}
		if (isbossweapon == true && off == true)
		{
			min = 2;
			max = 6;
			UpgradeLevel = rand() % (max - min) + min;
		}
		if (isbossweapon == false && off == true)
		{
			min = 5;
			max = 11;
			UpgradeLevel = rand() % (max - min) + min;

		}
			
		return UpgradeLevel;
	}
	int Infuison(int infu, bool Off)
	{
		int min;
		int max;
		bool isInfusionWeapon = false;
		int Infus;
		for (int i = 0; i < InfusionList.size(); i++) {
			int woof = stoi(InfusionList[i]);
			if (infu == woof) { isInfusionWeapon = true; }
		}
		if (isInfusionWeapon == true && Off == true)
		{
			Infus = 0;
		}
		if(isInfusionWeapon == false && Off == true)
		{
			Infus = rand() % 11;
		}
		if (isInfusionWeapon == true && Off == false)
		{
			Infus = 0;
		}
		if (isInfusionWeapon == false && Off == false)
		{
			Infus = 0;
		}
		return Infus;
	}



	int GetModuleBaseAddress(LPCWSTR szProcessName, LPCWSTR szModuleName)
	{
		HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		PROCESSENTRY32 pe32;

		if (hSnap == INVALID_HANDLE_VALUE)
		{
			return 0;
		}
		pe32.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(hSnap, &pe32) == 0)
		{
			CloseHandle(hSnap);
			return 0;
		}

		do
		{
			if (lstrcmp(pe32.szExeFile, szProcessName) == 0)
			{
				int PID;
				PID = pe32.th32ProcessID;

				HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, PID);
				MODULEENTRY32 xModule;

				if (hSnap == INVALID_HANDLE_VALUE)
				{
					return 0;
				}
				xModule.dwSize = sizeof(MODULEENTRY32);
				if (Module32First(hSnap, &xModule) == 0)
				{
					CloseHandle(hSnap);
					return 0;
				}

				do
				{
					if (lstrcmp(xModule.szModule, szModuleName) == 0)
					{
						CloseHandle(hSnap);
						return (int)xModule.modBaseAddr;
					}
				} while (Module32Next(hSnap, &xModule));
				CloseHandle(hSnap);
				return 0;
			}
		} while (Process32Next(hSnap, &pe32));
		CloseHandle(hSnap);
		return 0;
	}

	DWORD FindProcessId(const std::wstring& processName)
	{
		PROCESSENTRY32 processInfo;
		processInfo.dwSize = sizeof(processInfo);

		HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		if (processesSnapshot == INVALID_HANDLE_VALUE)
			return 0;

		Process32First(processesSnapshot, &processInfo);
		if (!processName.compare(processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}

		while (Process32Next(processesSnapshot, &processInfo))
		{
			if (!processName.compare(processInfo.szExeFile))
			{
				CloseHandle(processesSnapshot);
				return processInfo.th32ProcessID;
			}
		}

		CloseHandle(processesSnapshot);
		return 0;
	}

}
