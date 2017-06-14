// SADXDisableUpgradeModels.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "..\sadx-mod-loader\SADXModLoader\include\SADXModLoader.h"
#include "..\mod-loader-common\ModLoaderCommon\IniFile.hpp"

#define upgradecheck(name) bool Disable##name = settings->getBool("", "Disable"#name, true)

extern "C"
{
	__declspec(dllexport) void Init(const char *path, const HelperFunctions &helperFunctions)
	{
		const IniFile *settings = new IniFile(std::string(path) + "\\config.ini");
		upgradecheck(CrystalRing);
		upgradecheck(LightShoes);
		upgradecheck(JetAnklet);
		upgradecheck(RhythmBadge);
		upgradecheck(FightingGloves);
		upgradecheck(ShovelClaw);
		upgradecheck(LongHammer);
		upgradecheck(WarriorFeather);
		upgradecheck(LaserBlaster);
		upgradecheck(JetBooster);
		upgradecheck(PowerRod);
		upgradecheck(LifeRing);
		delete settings;
		if (DisableCrystalRing && DisableLightShoes)
			WriteData((char*)0x49BE2B, (char)0xEBu);
		else if (DisableCrystalRing)
			WriteJump((void*)0x49BE68, (void*)0x49BE87);
		else if (DisableLightShoes)
			WriteJump((void*)0x49BE2D, (void*)0x49BE68);
		if (DisableJetAnklet)
			WriteJump((void*)0x4618B0, (void*)0x46193B);
		if (DisableJetAnklet && DisableRhythmBadge)
			WriteJump((void*)0x46220F, (void*)0x4622FE);
		else if (DisableJetAnklet)
			WriteJump((void*)0x46220F, (void*)0x46229A);
		else if (DisableRhythmBadge)
			WriteJump((void*)0x46229A, (void*)0x4622FE);
		if (DisableFightingGloves && DisableShovelClaw)
			WriteData<5>((void*)0x47B460, 0x90u);
		else if (DisableFightingGloves)
			WriteData((char*)0x4726A6, (char)Upgrades_ShovelClaw);
		else if (DisableShovelClaw)
			WriteData((char*)0x4726A6, (char)Upgrades_FightingGloves);
		if (DisableLongHammer)
			WriteJump((void*)0x48B502, (void*)0x48B52B);
		if (DisableWarriorFeather)
			WriteData<5>((void*)0x48B542, 0x90u);
		if (DisableLaserBlaster)
			WriteJump((void*)0x47FD75, (void*)0x47FDAA);
		if (DisableJetBooster)
			WriteJump((void*)0x48018E, (void*)0x4802BB);
		if (DisablePowerRod && DisableLifeRing)
			WriteJump((void*)0x491270, (void*)0x4913BF);
		else if (DisablePowerRod)
			WriteJump((void*)0x49137A, (void*)0x4913BF);
		else if (DisableLifeRing)
			WriteJump((void*)0x491270, (void*)0x49137A);
		if (DisablePowerRod)
			WriteData<3>((void*)0x4913CA, 0x90u); // extra instruction
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}