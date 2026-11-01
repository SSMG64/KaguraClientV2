/*
___  ____                            __ _     ___________________   __
|  \/  (_)                          / _| |   /  ___| ___ \ ___ \ \ / /
| .  . |_ _ __   ___  ___ _ __ __ _| |_| |_  \ `--.| |_/ / |_/ /\ V /
| |\/| | | '_ \ / _ \/ __| '__/ _` |  _| __|  `--. \  __/|    / /   \
| |  | | | | | |  __/ (__| | | (_| | | | |_  /\__/ / |   | |\ \/ /^\ \
\_|  |_/_|_| |_|\___|\___|_|  \__,_|_|  \__| \____/\_|   \_| \_\/   \/

                          Made by Misaki
*/

#include <Util/Dialog.h>
#ifdef KAGURA_PS3DK
#include <stddef.h>
#include <sys/prx_module.h>
#define MODULE_ARGS size_t, void*
#else
#define MODULE_ARGS void
#endif
#include "Util/Includes.h"

#ifndef KAGURA_PS3DK
SYS_MODULE_INFO(Minecraft, 0, 1, 1);
SYS_MODULE_START(Minecraft_Main);
SYS_MODULE_STOP(Minecraft_Stop);
#endif

extern "C" int Minecraft_Main(MODULE_ARGS)
{
	BetterOptions();
	Dialog::msgdialog_mode = Dialog::MODE_RUNNING;
	Dialog::ProgressBar("Kagura Client V2\n Open menu  + \n Made by AzeY !", "Loading ", 20);
	Dialog::End();

	InstallHooks();
	return SYS_PRX_RESIDENT;
}
extern "C" int Minecraft_Stop(MODULE_ARGS)
{
	UninstallHooks();
	return SYS_PRX_RESIDENT;
}
#ifdef KAGURA_PS3DK
extern "C" int module_start(size_t, void*) { return Minecraft_Main(0, 0); }
extern "C" int module_stop(size_t, void*) { return Minecraft_Stop(0, 0); }
#endif