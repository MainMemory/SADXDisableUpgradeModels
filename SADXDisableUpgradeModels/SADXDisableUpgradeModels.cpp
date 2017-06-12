// SADXDisableUpgradeModels.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "..\sadx-mod-loader\SADXModLoader\include\SADXModLoader.h"

extern "C"
{
	__declspec(dllexport) void Init(const char *path, const HelperFunctions &helperFunctions)
	{
		WriteData((char*)0x49BE2B, (char)0xEBu); // Sonic's upgrades
		WriteJump((void*)0x4618B0, (void*)0x46193B); // Tails' Jet Anklet
		WriteJump((void*)0x46220F, (void*)0x4622FE); // Tails' upgrades
		WriteData<5>((void*)0x47B460, 0x90u); // Knuckles' upgrades
		WriteJump((void*)0x48B502, (void*)0x48B52B); // Amy's Long Hammer
		WriteData<5>((void*)0x48B542, 0x90u); // Amy's Warrior Feather
		WriteJump((void*)0x47FD75, (void*)0x47FDAA); // Gamma's Laser Blaster
		WriteJump((void*)0x48018E, (void*)0x4802BB); // Gamma's Jet Booster
		WriteJump((void*)0x491270, (void*)0x4913BF); // Big's upgrades
		WriteData<3>((void*)0x4913CA, 0x90u); // extra instruction
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}