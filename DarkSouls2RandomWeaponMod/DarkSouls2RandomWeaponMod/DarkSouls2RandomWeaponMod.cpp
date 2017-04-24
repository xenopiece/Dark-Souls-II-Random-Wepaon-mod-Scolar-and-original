// DarkSouls2RandomWeaponMod.cpp : Defines the entry point for the console application.
//



#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <windows.h>
#include <vector>
#include <cstdint>
#include <regex>
#include "Utilities.h"

int main()
{
	SetConsoleTitle(L"Dark Souls II Random mod, BobRoss is god ela13");
	srand(clock());

	//timer
	double timer = 0;
	//offsets
	DWORD H_OFF1 = 0x74;
	DWORD H_OFF2 = 0x378;
	DWORD H_OFF3 = 0x1A8;

	DWORD W_Offset1 = 0x74;
	DWORD W_Offset2 = 0x2D4;
	DWORD W_Offset3 = 0x10;
	DWORD W_Offset4 = 0x1C;

	DWORD Upgrade_lvl1 = 0x74;
	DWORD Upgrade_lvl2 = 0x2D4;
	DWORD Upgrade_lvl3 = 0x14;
	DWORD Upgrade_lvl4 = 0xD8;

	DWORD Infusion1 = 0x74;
	DWORD Infusion2 = 0x2D4;
	DWORD Infusion3 = 0x14;
	DWORD Infusion4 = 0xD9;

	DWORD Everything = 0x11493F4;

	int upgradeLevel = 0;
	int Hollow_of = 0;
	int Infusion_stuff = 0;
	int Hollow = 0;
	int RWeapon = 0;
	int Hollow_on = 1;
	
	//variables
	bool gUpgradeLvl;
	bool infusion;
	int RandomUpgradeindex;
	int RandomInfusionIndex;

	int weapon; //5350000 why did i leave this in you might think? i dunno

	std::cout << "Welcome to the Dark Souls II RandomWeapon Mod by Some idiot online" << std::endl;

	HWND WindowHandle = FindWindow(NULL, L"Dark Souls II");
	int BaseA = Utils::GetModuleBaseAddress(L"DarkSoulsII.exe", L"DarkSoulsII.exe");
	if (!BaseA)
	{
		std::cout << "please start the game nepsMug" << std::endl;
	}
	else
	{
		DWORD Procid = Utils::FindProcessId(L"DarkSoulsII.exe");
		HANDLE hprocess = OpenProcess(PROCESS_ALL_ACCESS, 0, Procid);
		if (!Procid)
		{
			std::cout << "start the game as admin! nepsMug" << std::endl;
		}
		else
		{
			for (;;) {
				std::cout << "How fast would you like the mod to switch weapon my good sir? " << std::endl;
				std::cout << "(If your timer is set to 0 or under the weaponlevel is always set to 5" << std::endl;
				std::cout << "and infusions are off)" << std::endl;
				std::cin >> timer;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
					std::cout << "error, your hay, retry" << std::endl;
					Sleep(1000);
					system("cls");
					continue;
				}
				else {
					break;
				}

			}
			if (timer < 1)
			{
				infusion = 0;
				gUpgradeLvl = 0;
				goto duck;
			}
			system("cls");
			for (;;) {
				std::cout << "Would you like to have upgradelvl from 5 - 10 (1 for yes, 0 for no)?" << std::endl;
				std::cin >> gUpgradeLvl;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
					std::cout << "error, your hay, retry" << std::endl;
					Sleep(1000);
					system("cls");
					continue;
				}
				else
				{
					break;
				}
			}
			for (;;) {
				std::cout << "Should Weapons have infusions (1 for yes, 0 for no)?" << std::endl;
				std::cin >> infusion;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(INT_MAX, '\n');
					std::cout << "error, your hay, retry" << std::endl;
					Sleep(1000);
					system("cls");
					continue;
				}
				else
				{
					break;
				}
			}
			duck:
			system("cls");
			SetConsoleTitle(L"Dark Souls II Random mod, BobRoss is god ela13");
			ReadProcessMemory(hprocess, (LPVOID*)(BaseA + Everything), &RWeapon, sizeof(RWeapon), NULL);
			ReadProcessMemory(hprocess, (LPVOID*)(RWeapon + W_Offset1), &RWeapon, sizeof(RWeapon), NULL);
			ReadProcessMemory(hprocess, (LPVOID*)(RWeapon + W_Offset2), &RWeapon, sizeof(RWeapon), NULL);
			ReadProcessMemory(hprocess, (LPVOID*)(RWeapon + W_Offset3), &RWeapon, sizeof(RWeapon), NULL);

			ReadProcessMemory(hprocess, (LPVOID*)(BaseA + Everything), &Hollow, sizeof(Hollow), NULL);
			ReadProcessMemory(hprocess, (LPVOID*)(Hollow + H_OFF1), &Hollow, sizeof(Hollow), NULL);
			ReadProcessMemory(hprocess, (LPVOID*)(Hollow + H_OFF2), &Hollow, sizeof(Hollow), NULL);

			ReadProcessMemory(hprocess, (LPVOID*)(BaseA + Everything), &upgradeLevel, sizeof(upgradeLevel), NULL);
			ReadProcessMemory(hprocess, (LPVOID*)(upgradeLevel + Upgrade_lvl1), &upgradeLevel, sizeof(upgradeLevel), NULL);
			ReadProcessMemory(hprocess, (LPVOID*)(upgradeLevel + Upgrade_lvl2), &upgradeLevel, sizeof(upgradeLevel), NULL);
			ReadProcessMemory(hprocess, (LPVOID*)(upgradeLevel + Upgrade_lvl3), &upgradeLevel, sizeof(upgradeLevel), NULL);

			ReadProcessMemory(hprocess, (LPVOID*)(BaseA + Everything), &Infusion_stuff, sizeof(Infusion_stuff), NULL);
			ReadProcessMemory(hprocess, (LPVOID*)(Infusion_stuff + Infusion1), &Infusion_stuff, sizeof(Infusion_stuff), NULL);
			ReadProcessMemory(hprocess, (LPVOID*)(Infusion_stuff + Infusion2), &Infusion_stuff, sizeof(Infusion_stuff), NULL);
			ReadProcessMemory(hprocess, (LPVOID*)(Infusion_stuff + Infusion3), &Infusion_stuff, sizeof(Infusion_stuff), NULL);
			std::cout << "Welcome to the Dark Souls II RandomWeapon Mod by BobRoss " << std::endl << "Timer set to " << timer <<" seconds" << std::endl;
			while (true)
			{
				weapon = Utils::Weaponfcs();
				RandomUpgradeindex = Utils::UpgradeLevel(weapon, gUpgradeLvl);

				RandomInfusionIndex = Utils::Infuison(weapon, infusion);

				WriteProcessMemory(hprocess, (LPVOID*)(RWeapon + W_Offset4), &weapon, sizeof(weapon), NULL);

				WriteProcessMemory(hprocess, (LPVOID*)(Hollow + H_OFF3), &Hollow_on, sizeof(Hollow_on), NULL);
				
				Sleep(40);
				WriteProcessMemory(hprocess, (LPVOID*)(Hollow + H_OFF3), &Hollow_of, sizeof(Hollow_of), NULL);
				
				Sleep(150);
				if (timer < 1 )
				{
					RandomUpgradeindex = 5;
					RandomInfusionIndex = 0;
				}

				WriteProcessMemory(hprocess, (LPVOID*)(upgradeLevel + Upgrade_lvl4), &RandomUpgradeindex, sizeof(RandomUpgradeindex), NULL);
				Sleep(150);
				WriteProcessMemory(hprocess, (LPVOID*)(Infusion_stuff + Infusion4), &RandomInfusionIndex, sizeof(RandomInfusionIndex), NULL);
				Sleep(timer * 1000);
			}

		}

	}
	system("pause");
    return 0;
}

