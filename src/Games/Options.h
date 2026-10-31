#pragma once

namespace Modules
{
	void ModulesTextRender()
	{
		if (Zoom)
			DrawTextWithShadow(L"Zoom Mode", 584, 15, color(MC_Color::White));
		if (TPAura)
			DrawTextWithShadow(L"TP Aura", 595, 25, color(MC_Color::White));
		if (AutoTossItems)
			DrawTextWithShadow(L"Auto Toss", 603, 35, color(MC_Color::White));
	}

	void setLocation(double x, double y, double z)
	{
		mc->theMinecraft->cMultiplayerLocalPlayer->SetPosition(x + 0.5, y + 1 + 0.5, z + 0.5);
	}

	void ZoomModule()
	{
		if (Zoom)
		{
			if (Buttons::IsMCButtonPressed(Buttons::R3))
			{
				*(int*)0x014C670C = 0x40500000;
			}
			else
			{
				*(int*)0x014C670C = 0x3F800000;
			}
		}
	}
	void TP_Aura(ServerPlayer* player)
	{
		if (TPAura)
		{
			TargetposX = player->posX;
			TargetposY = player->posY;
			TargetposZ = player->posZ;

			if (frameTime(0, 1, false))
			{
				*(int*)0x00AEC34C = 0x40820024;
				setLocation(TargetposX, TargetposY + 10, TargetposZ); //TARGET POS
				sleep(400);
				setLocation(TargetposX, TargetposY, TargetposZ); //TARGET POS
				sleep(400);
				setLocation(TargetposX, TargetposY, TargetposZ); //TARGET POS
				sleep(400);
				setLocation(TargetposX + 5, TargetposY + 10, TargetposZ); //TARGET POS
				sleep(400);
				setLocation(TargetposX, TargetposY + 10, TargetposZ + 5); //TARGET POS
				*(int*)0x00AEC34C = 0x41820024;
			}
		}
	}
	void AutoToss()
	{
		if (AutoTossItems)
		{
			if (Buttons::IsMCButtonPressed(Buttons::O))
			{
				*(int*)0x00AEF428 = 0x40820024;
			}
			else
			{
				*(int*)0x00AEF428 = 0x41820024;
			}
		}
	}
}

namespace Offsets
{
	//Clean Offsets
	void GOD_MODE(bool toggle) { if (toggle) { *(int*)0x4B2020 = 0xFC80F890; } else { *(int*)0x4B2020 = 0xFC20F890; } }
	void INSTANT_DAMAGE(bool toggle) { if (toggle) { *(int*)0x003A3FF0 = 0x40800000; } else { *(int*)0x003A3FF0 = 0x3F000000; } }
	void NO_DAMAGE_HIT(bool toggle) { if (toggle) { *(int*)0x3A3FF0 = 0xFF000000; } else { *(int*)0x3A3FF0 = 0x3F000000; } }
	void KNOCKBACK(bool toggle) { if (toggle) { *(int*)0x003A4018 = 0x40CCCCCD; } else { *(int*)0x003A4018 = 0x3ECCCCCD; } }
	void ANTI_KNOCKBACK(bool toggle) { if (toggle) { *(int*)0x3A4018 = 0x00CCCCCD; } else { *(int*)0x3A4018 = 0x3ECCCCCD; } }
	void POTIONS_FLYING(bool toggle) { if (toggle) { *(int*)0x0065FB60 = 0x2D4CCCCD; } else { *(int*)0x0065FB60 = 0x3D4CCCCD; } }
	void POTIONS_NO_GRAVITY(bool toggle) { if (toggle) { *(int*)0x0065FB60 = 0x4D4CCCCD; } else { *(int*)0x0065FB60 = 0x3D4CCCCD; } }
	void INFINITE_PICKUP_ITEMS(bool toggle) { if (toggle) { *(int*)0x224B10 = 0x38800000; } else { *(int*)0x224B10 = 0x38800001; } }
	void MAX_PICKUP_ITEMS(bool toggle) { if (toggle) { *(int*)0x310AD4 = 0x41810034; } else { *(int*)0x310AD4 = 0x40810034; } }
	void INFINITE_BLOCKS(bool toggle) { if (toggle) { *(int*)0x10673C = 0x38800000; } else { *(int*)0x10673C = 0x38800001; } }
	void BURN_IN_WATER(bool toggle) { if (toggle) { *(int*)0x225EA8 = 0x418100A4; } else { *(int*)0x225EA8 = 0x408100A4; } }
	void REMOVE_FIRE(bool toggle) { if (toggle) { *(int*)0x225E80 = 0x40820020; } else { *(int*)0x225E80 = 0x41820020; } }
	void BYPASS_MAX_ITEMS(bool toggle) { if (toggle) { *(int*)0x310AFC = 0x41820008; } else { *(int*)0x310AFC = 0x40820008; } }
	void DISABLE_PORTALS(bool toggle) { if (toggle) { *(int*)0x2379E4 = 0x38600000; } else { *(int*)0x2379E4 = 0x38600001; } }
	void FREEZE_ALL_ENTITY(bool toggle) { if (toggle) { *(int*)0x3A9FE8 = 0x4E800020; } else { *(int*)0x3A9FE8 = 0xF821FF81; } }
	void ITEMS_ON_HEAD(bool toggle) { if (toggle) { *(int*)0x428704 = 0x4082001C; } else { *(int*)0x428704 = 0x4182001C; } }
	void ENTITY_GOD_MODE(bool toggle) { if (toggle) { *(int*)0x003A3F6C = 0x4082004C; } else { *(int*)0x003A3F6C = 0x4182004C; } }
	void FAST_BOW(bool toggle) { if (toggle) { *(int*)0x000FB4C4 = 0xFFE01818; } else { *(int*)0x000FB4C4 = 0xFFE00818; } }
	void STOP_BOAT(bool toggle) { if (toggle) { *(int*)0xE0F90 = 0x41800034; } else { *(int*)0xE0F90 = 0x40800034; } }
	void NO_WEB(bool toggle) { if (toggle) { *(int*)0x234F9C = 0x38800000; } else { *(int*)0x234F9C = 0x38800001; } }
	void DROP_ITEMS_FAR(bool toggle) { if (toggle) { *(int*)0x14C6880 = 0x3FFF0000; } else { *(int*)0x14C6880 = 0x3F800000; } }
	void LOCK_GAMEMODE(bool toggle) { if (toggle) { *(int*)0x002F03D0 = 0x4182000C; } else { *(int*)0x002F03D0 = 0x4082000C; } }
	void LOCK_WEATHER(bool toggle) { if (toggle) { *(int*)0x00393E84 = 0x4182048C; } else { *(int*)0x00393E84 = 0x4082048C; } }
	void STOP_ENDERMAN_TP(bool toggle) { if (toggle) { *(int*)0x3B30A8 = 0x4E800020; } else { *(int*)0x3B30A8 = 0xF821FEB1; } }

	//Basic Offsets
	void SUPER_SPEED(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0xFF, 0xFF, 0xFF };
			sys_dbg_write_process_memory(0x003ABD49, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003ABD49, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x26, 0xAD, 0x89 };
			sys_dbg_write_process_memory(0x003ABD49, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003ABD49, &HEX, sizeof(HEX));
		}
	}
	void MULTI_JUMP(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x14 };
			sys_dbg_write_process_memory(0x0022790B, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0022790B, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x18 };
			sys_dbg_write_process_memory(0x0022790B, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0022790B, &HEX, sizeof(HEX));
		}
	}
	void INSTANT_HIT(bool toggle)
	{
		if (toggle)
		{
			char SPEED[] = { 0xFF };
			sys_dbg_write_process_memory(0x00AEBED4, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00AEBED4, &SPEED, sizeof(SPEED));
		}
		else
		{
			char SPEED[] = { 0x3E };
			sys_dbg_write_process_memory(0x00AEBED4, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00AEBED4, &SPEED, sizeof(SPEED));
		}
	}
	void REACH_ATTACK(bool toggle)
	{
		if (toggle)
		{
			char MODZ[] = { 0x80 };
			char MOD[] = { 0x80 };
			char MO[] = { 0x43, 0xA0, 0x00, 0x00 };
			char MA[] = { 0x43, 0xA0, 0x00, 0x00 };

			sys_dbg_write_process_memory(0x00A95FB9, &MODZ, sizeof(MODZ));
			sys_dbg_write_process_memory(0x00A95FC1, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory(0x00B351D8, &MO, sizeof(MO));
			sys_dbg_write_process_memory(0x00B351DC, &MA, sizeof(MA));
			sys_dbg_write_process_memory_ps3mapi(0x00A95FB9, &MODZ, sizeof(MODZ));
			sys_dbg_write_process_memory_ps3mapi(0x00A95FC1, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00B351D8, &MO, sizeof(MO));
			sys_dbg_write_process_memory_ps3mapi(0x00B351DC, &MA, sizeof(MA));
		}
		else
		{
			char MODZ[] = { 0x18 };
			char MOD[] = { 0x08 };
			char MO[] = { 0x40, 0xA0, 0x00, 0x00 };
			char MA[] = { 0x40, 0x90, 0x00, 0x00 };

			sys_dbg_write_process_memory(0x00A95FB9, &MODZ, sizeof(MODZ));
			sys_dbg_write_process_memory(0x00A95FC1, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory(0x00B351D8, &MO, sizeof(MO));
			sys_dbg_write_process_memory(0x00B351DC, &MA, sizeof(MA));
			sys_dbg_write_process_memory_ps3mapi(0x00A95FB9, &MODZ, sizeof(MODZ));
			sys_dbg_write_process_memory_ps3mapi(0x00A95FC1, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00B351D8, &MO, sizeof(MO));
			sys_dbg_write_process_memory_ps3mapi(0x00B351DC, &MA, sizeof(MA));
		}
	}
	void KILL_AURA(bool toggle)
	{
		if (toggle)
		{
			char SPEED[] = { 0xFF };
			sys_dbg_write_process_memory(0x00233290, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00233290, &SPEED, sizeof(SPEED));
		}
		else
		{
			char SPEED[] = { 0x00 };
			sys_dbg_write_process_memory(0x00233290, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00233290, &SPEED, sizeof(SPEED));
		}
	}

	void FULL_AURA(bool toggle)
	{
		if (toggle)
		{
			char SPEED[] = { 0xFF }; //Kill Aura
			sys_dbg_write_process_memory(0x00233290, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00233290, &SPEED, sizeof(SPEED));

			char MODZ[] = { 0x80 }; //Reach Attack
			char MOD[] = { 0x80 };
			char MO[] = { 0x43, 0xA0, 0x00, 0x00 };
			char MA[] = { 0x43, 0xA0, 0x00, 0x00 };

			sys_dbg_write_process_memory(0x00A95FB9, &MODZ, sizeof(MODZ));
			sys_dbg_write_process_memory(0x00A95FC1, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory(0x00B351D8, &MO, sizeof(MO));
			sys_dbg_write_process_memory(0x00B351DC, &MA, sizeof(MA));
			sys_dbg_write_process_memory_ps3mapi(0x00A95FB9, &MODZ, sizeof(MODZ));
			sys_dbg_write_process_memory_ps3mapi(0x00A95FC1, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00B351D8, &MO, sizeof(MO));
			sys_dbg_write_process_memory_ps3mapi(0x00B351DC, &MA, sizeof(MA));

			char SPEED1[] = { 0xFF }; //Instant Hit
			sys_dbg_write_process_memory(0x00AEBED4, &SPEED1, sizeof(SPEED1));
			sys_dbg_write_process_memory_ps3mapi(0x00AEBED4, &SPEED1, sizeof(SPEED1));

			char SPEED2[] = { 0xBE }; //Unfair Attack
			sys_dbg_write_process_memory(0x00AEBED4, &SPEED2, sizeof(SPEED2));
			sys_dbg_write_process_memory_ps3mapi(0x00AEBED4, &SPEED2, sizeof(SPEED2));

			char HEX[] = { 0x40 }; //Auto Hit
			sys_dbg_write_process_memory(0x00AEC34C, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AEC34C, &HEX, sizeof(HEX));
		}
		else
		{
			char SPEED[] = { 0x00 };
			sys_dbg_write_process_memory(0x00233290, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00233290, &SPEED, sizeof(SPEED));

			char MODZ[] = { 0x18 };
			char MOD[] = { 0x08 };
			char MO[] = { 0x40, 0xA0, 0x00, 0x00 };
			char MA[] = { 0x40, 0x90, 0x00, 0x00 };

			sys_dbg_write_process_memory(0x00A95FB9, &MODZ, sizeof(MODZ));
			sys_dbg_write_process_memory(0x00A95FC1, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory(0x00B351D8, &MO, sizeof(MO));
			sys_dbg_write_process_memory(0x00B351DC, &MA, sizeof(MA));
			sys_dbg_write_process_memory_ps3mapi(0x00A95FB9, &MODZ, sizeof(MODZ));
			sys_dbg_write_process_memory_ps3mapi(0x00A95FC1, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00B351D8, &MO, sizeof(MO));
			sys_dbg_write_process_memory_ps3mapi(0x00B351DC, &MA, sizeof(MA));

			char SPEED1[] = { 0x3E };
			sys_dbg_write_process_memory(0x00AEBED4, &SPEED1, sizeof(SPEED1));
			sys_dbg_write_process_memory_ps3mapi(0x00AEBED4, &SPEED1, sizeof(SPEED1));

			char SPEED2[] = { 0x3E };
			sys_dbg_write_process_memory(0x00AEBED4, &SPEED2, sizeof(SPEED2));
			sys_dbg_write_process_memory_ps3mapi(0x00AEBED4, &SPEED2, sizeof(SPEED2));

			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x00AEC34C, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AEC34C, &HEX, sizeof(HEX));
		}
	}
	void CAN_FLY(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x00B02378, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00B02378, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x00B02378, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00B02378, &HEX, sizeof(HEX));
		}
	}
	void NO_COLISSION(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
			sys_dbg_write_process_memory(0x00011230, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00011230, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00011230, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00011230, &HEX, sizeof(HEX));
		}
	}
	void SWIM_FLY(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x3B, 0x40, 0x00, 0x10 };
			sys_dbg_write_process_memory(0x00390410, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00390410, &HEX, sizeof(HEX));

			char HEX1[] = { 0x3D };
			sys_dbg_write_process_memory(0x003ABD44, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x003ABD44, &HEX1, sizeof(HEX1));
		}
		else
		{
			char HEX[] = { 0x3B, 0x40, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00390410, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00390410, &HEX, sizeof(HEX));

			char HEX1[] = { 0x3C };
			sys_dbg_write_process_memory(0x003ABD44, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x003ABD44, &HEX1, sizeof(HEX1));
		}
	}
	void INSTANT_MINE(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0xBF };
			sys_dbg_write_process_memory(0x00AEB090, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AEB090, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x3F };
			sys_dbg_write_process_memory(0x00AEB090, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AEB090, &HEX, sizeof(HEX));
		}
	}
	void INFINITE_CRAFT(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x01 };
			sys_dbg_write_process_memory(0x0098871F, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0098871F, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x00 };
			sys_dbg_write_process_memory(0x0098871F, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0098871F, &HEX, sizeof(HEX));
		}
	}
	void NAME_OVER_HEAD(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x4C };
			sys_dbg_write_process_memory(0x00AD8158, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AD8158, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x2C };
			sys_dbg_write_process_memory(0x00AD8158, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AD8158, &HEX, sizeof(HEX));
		}
	}
	void SCAFFOLD_BETA(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x50 };
			sys_dbg_write_process_memory(0x0022C7FC, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0022C7FC, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x0022C7FC, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0022C7FC, &HEX, sizeof(HEX));


		}
	}
	void DAY_NIGHT(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x2F };
			sys_dbg_write_process_memory(0x014C6880, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x014C6880, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x3F };
			sys_dbg_write_process_memory(0x014C6880, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x014C6880, &HEX, sizeof(HEX));;
		}
	}
	void ALWAYS_CROUCH(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x0F };
			sys_dbg_write_process_memory(0x00B0143F, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00B0143F, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x0E };
			sys_dbg_write_process_memory(0x00B0143F, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00B0143F, &HEX, sizeof(HEX));
		}
	}
	void LEVITATION(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0xBF };
			sys_dbg_write_process_memory(0x003ABDD0, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003ABDD0, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x3F };
			sys_dbg_write_process_memory(0x003ABDD0, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003ABDD0, &HEX, sizeof(HEX));
		}
	}
	void AUTO_LADDER(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x01 };
			sys_dbg_write_process_memory(0x003A74F3, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003A74F3, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x00 };
			sys_dbg_write_process_memory(0x003A74F3, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003A74F3, &HEX, sizeof(HEX));
		}
	}
	void AIR_TO_WATER(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x001D7FCC, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x001D7FCC, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x001D7FCC, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x001D7FCC, &HEX, sizeof(HEX));
		}
	}
	void AUTO_SPRINT(bool toggle)
	{
		if (toggle)
		{
			char SPEED[] = { 0x40 };
			sys_dbg_write_process_memory(0x00B01DEC, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00B01DEC, &SPEED, sizeof(SPEED));
		}
		else
		{
			char SPEED[] = { 0x41 };
			sys_dbg_write_process_memory(0x00B01DEC, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00B01DEC, &SPEED, sizeof(SPEED));
		}
	}
	void REMOVE_HURT_CAM(bool toggle)
	{
		if (toggle)
		{
			char SPEED[] = { 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00A972B0, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00A972B0, &SPEED, sizeof(SPEED));
		}
		else
		{
			char SPEED[] = { 0x40, 0x49 };
			sys_dbg_write_process_memory(0x00A972B0, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00A972B0, &SPEED, sizeof(SPEED));
		}
	}
	void SHOW_ARMOR(bool toggle)
	{
		if (toggle)
		{
			char SPEED[] = { 0x38, 0x80, 0x00, 0x01 };
			sys_dbg_write_process_memory(0x0090B5F0, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x0090B5F0, &SPEED, sizeof(SPEED));
		}
		else
		{
			char SPEED[] = { 0x38, 0x80, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x0090B5F0, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x0090B5F0, &SPEED, sizeof(SPEED));
		}
	}
	void UNFAIR_ATTACK(bool toggle)
	{
		if (toggle)
		{
			char SPEED[] = { 0xBE };
			sys_dbg_write_process_memory(0x00AEBED4, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00AEBED4, &SPEED, sizeof(SPEED));
		}
		else
		{
			char SPEED[] = { 0x3E };
			sys_dbg_write_process_memory(0x00AEBED4, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00AEBED4, &SPEED, sizeof(SPEED));
		}
	}
	void HITBOX_BETA(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x01 };
			char MOD1[] = { 0xFF };

			sys_dbg_write_process_memory(0x0003AE03, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory(0x00233290, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0003AE03, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00233290, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD[] = { 0x00 };
			char MOD1[] = { 0x00 };

			sys_dbg_write_process_memory(0x0003AE03, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory(0x00233290, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0003AE03, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00233290, &MOD1, sizeof(MOD1));
		}
	}
	void BIG_VELOCITY(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0xD3, 0x23, 0x01, 0x30 };
			char MOD1[] = { 0xD8, 0x43, 0x01, 0x38 };
			char MOD2[] = { 0xD9, 0x63, 0x01, 0x40 };

			sys_dbg_write_process_memory(0x002335C8, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory(0x002335CC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory(0x002335D0, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory_ps3mapi(0x002335C8, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x002335CC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x002335D0, &MOD2, sizeof(MOD2));
		}
		else
		{
			char MOD[] = { 0xD8, 0x23, 0x01, 0x30 };
			char MOD1[] = { 0xD8, 0x43, 0x01, 0x38 };
			char MOD2[] = { 0xD8, 0x63, 0x01, 0x40 };

			sys_dbg_write_process_memory(0x002335C8, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory(0x002335CC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory(0x002335D0, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory_ps3mapi(0x002335C8, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x002335CC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x002335D0, &MOD2, sizeof(MOD2));
		}
	}
	void NO_VELOCITY(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0xD3, 0x23, 0x01, 0x30 };
			char MOD1[] = { 0xD8, 0x43, 0x01, 0x38 };
			char MOD2[] = { 0xD3, 0x63, 0x01, 0x40 };

			sys_dbg_write_process_memory(0x002335C8, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory(0x002335CC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory(0x002335D0, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory_ps3mapi(0x002335C8, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x002335CC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x002335D0, &MOD2, sizeof(MOD2));
		}
		else
		{
			char MOD[] = { 0xD8, 0x23, 0x01, 0x30 };
			char MOD1[] = { 0xD8, 0x43, 0x01, 0x38 };
			char MOD2[] = { 0xD8, 0x63, 0x01, 0x40 };

			sys_dbg_write_process_memory(0x002335C8, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory(0x002335CC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory(0x002335D0, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory_ps3mapi(0x002335C8, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x002335CC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x002335D0, &MOD2, sizeof(MOD2));
		}
	}
	void TNT_NUCLEAR(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x42, 0x80, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x0051E0D0, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0051E0D0, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x40, 0x80, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x0051E0D0, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0051E0D0, &HEX, sizeof(HEX));
		}
	}
	void TNT_FLYING(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x2F, 0xA4 };
			sys_dbg_write_process_memory(0x0051E558, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0051E558, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x3F, 0xA4 };
			sys_dbg_write_process_memory(0x0051E558, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0051E558, &HEX, sizeof(HEX));
		}
	}
	void CREEPER_NUCLEAR(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x3F, 0xFF };
			sys_dbg_write_process_memory(0x001CC7E0, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x001CC7E0, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x001CC7E0, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x001CC7E0, &HEX, sizeof(HEX));
		}
	}
	void CREEPER_FIRE(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x39, 0x40, 0x00, 0x10 };
			sys_dbg_write_process_memory(0x001CC894, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x001CC894, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x39, 0x40, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x001CC894, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x001CC894, &HEX, sizeof(HEX));
		}
	}
	void DISABLE_TOTEM(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x4E, 0x80, 0x00, 0x20 };
			sys_dbg_write_process_memory(0x003A52B8, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003A52B8, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0xF8, 0x21, 0xFF, 0x41 };
			sys_dbg_write_process_memory(0x003A52B8, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003A52B8, &HEX, sizeof(HEX));
		}
	}
	void INFINITE_OXYGEN(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x0039DE28, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0039DE28, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x0039DE28, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0039DE28, &HEX, sizeof(HEX));
		}
	}
	void CUSTOM_SKY(bool toggle)
	{

		if (toggle)
		{
			char HEX1[] = { 0x41, 0x30 };
			sys_dbg_write_process_memory(0x00B21F28, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B21F28, &HEX1, sizeof(HEX1));

			//multiple sky  { 0x3F, 0xFF }; //0xF8 for sky with moon //DEFAULT REMOVE SUN { 0x3F, 0x80 };
			char HEX2[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x00B21F1C, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory_ps3mapi(0x00B21F1C, &HEX2, sizeof(HEX2));

			// draw sky hook
			char HEX3[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x031BC7E0, &HEX3, sizeof(HEX3));
			sys_dbg_write_process_memory_ps3mapi(0x00B21F1C, &HEX3, sizeof(HEX3));

			char HEX4[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x3D800801, &HEX4, sizeof(HEX4));
			sys_dbg_write_process_memory_ps3mapi(0x3D800801, &HEX4, sizeof(HEX4));

			char HEX5[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x031BC7E4, &HEX5, sizeof(HEX5));
			sys_dbg_write_process_memory_ps3mapi(0x031BC7E4, &HEX5, sizeof(HEX5));

			char HEX6[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x7D8903A6, &HEX6, sizeof(HEX6));
			sys_dbg_write_process_memory_ps3mapi(0x7D8903A6, &HEX6, sizeof(HEX6));

			char HEX7[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x031BC7E8, &HEX7, sizeof(HEX7));
			sys_dbg_write_process_memory_ps3mapi(0x031BC7E8, &HEX7, sizeof(HEX7));

			char HEX8[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x4E800420, &HEX8, sizeof(HEX8));
			sys_dbg_write_process_memory_ps3mapi(0x4E800420, &HEX8, sizeof(HEX8));

			//color sky
			char HEX9[] = { 0x3F, 0x10 };
			sys_dbg_write_process_memory(0x00410738, &HEX9, sizeof(HEX9));
			sys_dbg_write_process_memory_ps3mapi(0x00410738, &HEX9, sizeof(HEX9));

			char HEX10[] = { 0x42, 0x00 };
			sys_dbg_write_process_memory(0x00B21F24, &HEX10, sizeof(HEX10));
			sys_dbg_write_process_memory_ps3mapi(0x00B21F24, &HEX4, sizeof(HEX10));

			//time sky
			char HEX11[] = { 0x84, 0x84 };
			sys_dbg_write_process_memory(0x00B21F5C, &HEX11, sizeof(HEX11));
			sys_dbg_write_process_memory_ps3mapi(0x00B21F5C, &HEX11, sizeof(HEX11));
		}
		else
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x0039DE28, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0039DE28, &HEX, sizeof(HEX));

			char HEX1[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x00B21F1C, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B21F1C, &HEX1, sizeof(HEX1));

		}
	}
	void MOBS_IGNORE_ME(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x3F, 0x00 };
			sys_dbg_write_process_memory(0x00A98F50, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00A98F50, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x3D, 0x8C };
			sys_dbg_write_process_memory(0x00A98F50, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00A98F50, &HEX, sizeof(HEX));
		}
	}
	void BEST_SKY(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x3F, 0x10 };
			char MOD2[] = { 0x7F };
			sys_dbg_write_process_memory(0x00410738, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory(0x0038C658, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory_ps3mapi(0x00410738, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x3F, 0x80 };
			char MOD2[] = { 0x3F };
			sys_dbg_write_process_memory(0x00410738, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory(0x0038C658, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory_ps3mapi(0x00410738, &MOD1, sizeof(MOD1));
		}
	}
	void STARS_IN_SKY(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x7F };
			sys_dbg_write_process_memory(0x0038C658, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0038C658, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x3F };
			sys_dbg_write_process_memory(0x0038C658, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0038C658, &MOD1, sizeof(MOD1));
		}
	}
	void DISABLE_SPAWN_MOBS(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x004619E4, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x004619E4, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x004619E4, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x004619E4, &HEX, sizeof(HEX));
		}
	}
	void ALL_PLAYERS_FAST_MINE(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0xFF, 0xE0, 0x28, 0x90 };
			sys_dbg_write_process_memory(0x0010E0C4, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x0010E0C4, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0xFF, 0xE0, 0x08, 0x90 };
			sys_dbg_write_process_memory(0x0010E0C4, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x0010E0C4, &MOD, sizeof(MOD));
		}
	}

	void ALL_PLAYERS_CANNOT_MINE(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0xFF, 0xE0, 0x18, 0x90 };
			sys_dbg_write_process_memory(0x0010E0C4, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x0010E0C4, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0xFF, 0xE0, 0x08, 0x90 };
			sys_dbg_write_process_memory(0x0010E0C4, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x0010E0C4, &MOD, sizeof(MOD));
		}
	}

	void ALL_PLAYERS_CANT_RUN(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0xFF, 0xE0, 0x00, 0x90 };
			sys_dbg_write_process_memory(0x00018CE4, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00018CE4, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0xFF, 0xE0, 0x08, 0x90 };
			sys_dbg_write_process_memory(0x00018CE4, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00018CE4, &MOD, sizeof(MOD));
		}
	}

	void ALL_PLAYERS_SUPER_SPEED(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0xFF, 0xE0, 0x28, 0x90 };
			sys_dbg_write_process_memory(0x00018CE4, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00018CE4, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0xFF, 0xE0, 0x08, 0x90 };
			sys_dbg_write_process_memory(0x00018CE4, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00018CE4, &MOD, sizeof(MOD));
		}
	}

	void ALL_PLAYERS_SUPER_RUN(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x58 };
			sys_dbg_write_process_memory(0x004668B6, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x004668B6, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0x08 };
			sys_dbg_write_process_memory(0x004668B6, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x004668B6, &MOD, sizeof(MOD));
		}
	}

	void ALL_PLAYERS_CANT_JOIN_THE_WORLD(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x01 };
			sys_dbg_write_process_memory(0x0098871F, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x0098871F, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0x00 };
			sys_dbg_write_process_memory(0x0098871F, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x0098871F, &MOD, sizeof(MOD));
		}
	}

	void ALL_PLAYERS_SUFFOCATE(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x4E, 0x80, 0x00, 0x20 };
			sys_dbg_write_process_memory(0x0022FDC8, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x0022FDC8, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0xF8, 0x21, 0xFF, 0x11 };
			sys_dbg_write_process_memory(0x0022FDC8, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x0022FDC8, &MOD, sizeof(MOD));
		}
	}

	void ALL_PLAYERS_IN_FIRE(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x40 };
			sys_dbg_write_process_memory(0x00225FA0, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00225FA0, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0x41 };
			sys_dbg_write_process_memory(0x00225FA0, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00225FA0, &MOD, sizeof(MOD));
		}
	}
	void FAST_BUILD(bool toggle)
	{
		if (toggle)
		{
			char SPEED[] = { 0x40 };
			sys_dbg_write_process_memory(0x00AECE70, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00AECE70, &SPEED, sizeof(SPEED));
		}
		else
		{
			char SPEED[] = { 0x41 };
			sys_dbg_write_process_memory(0x00AECE70, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00AECE70, &SPEED, sizeof(SPEED));
		}
	}
	void ESP_PLAYERS(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x00AD5B60, &HEX, sizeof(HEX));

			char HEX1[] = { 0x6F, 0xFF };
			sys_dbg_write_process_memory(0x00AD5A5C, &HEX1, sizeof(HEX1));

			sys_dbg_write_process_memory_ps3mapi(0x00AD5B60, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AD5A5C, &HEX1, sizeof(HEX1));
		}
		else
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x00AD5B60, &HEX, sizeof(HEX));

			char HEX1[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x00AD5A5C, &HEX1, sizeof(HEX1));

			sys_dbg_write_process_memory_ps3mapi(0x00AD5B60, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AD5A5C, &HEX1, sizeof(HEX1));
		}
	}
	void GRAVITY_MOON(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x003ABF88, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003ABF88, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x003ABF88, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003ABF88, &HEX, sizeof(HEX));
		}
	}
	void WATER_SLOWDOWN(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x3F, 0x7C, 0xCC, 0xCD };
			sys_dbg_write_process_memory(0x0003AA964, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0003AA964, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x3F, 0x4C, 0xCC, 0xCD };
			sys_dbg_write_process_memory(0x0003AA964, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0003AA964, &HEX, sizeof(HEX));
		}
	}
	void JUMP_IN_LAVA(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x3F, 0xF4, 0x7A, 0xE1 };
			sys_dbg_write_process_memory(0x003AA940, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003AA940, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x3F, 0xBA, 0xCC, 0xCD };
			sys_dbg_write_process_memory(0x003AA940, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003AA940, &HEX, sizeof(HEX));
		}
	}
	void POSITION_PLACE_BLOCK(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x28 };
			sys_dbg_write_process_memory(0x0022C85A, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0022C85A, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x08 };
			sys_dbg_write_process_memory(0x0022C85A, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x0022C85A, &HEX, sizeof(HEX));
		}
	}
	void ITEMS_IDS(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x003097C8, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003097C8, &HEX, sizeof(HEX));

			char HEX1[] = { 0x40 };
			sys_dbg_write_process_memory(0x003097B8, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x003097B8, &HEX1, sizeof(HEX1));
		}
		else
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x003097C8, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003097C8, &HEX, sizeof(HEX));

			char HEX1[] = { 0x41 };
			sys_dbg_write_process_memory(0x003097B8, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x003097B8, &HEX1, sizeof(HEX1));
		}
	}
	void JUMP_FOR_BUILD(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0xFC, 0x80 };
			sys_dbg_write_process_memory(0x002271F4, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x002271F4, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0xFC, 0x20 };
			sys_dbg_write_process_memory(0x002271F4, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x002271F4, &HEX, sizeof(HEX));
		}
	}
	void ESP_CHESTS(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x3E, 0xFF };
			sys_dbg_write_process_memory(0x00A9C2B4, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00A9C2B4, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x00A9C2B4, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00A9C2B4, &HEX, sizeof(HEX));
		}
	}
	void SENSIBILITY_FAST(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x42, 0xFF };
			sys_dbg_write_process_memory(0x00ABA948, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00ABA948, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x42, 0x48 };
			sys_dbg_write_process_memory(0x00ABA948, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00ABA948, &HEX, sizeof(HEX));
		}
	}
	void WALK_ALONE(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0xFF, 0x40 };
			sys_dbg_write_process_memory(0x003ABE18, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003ABE18, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0xFF, 0x20 };
			sys_dbg_write_process_memory(0x003ABE18, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003ABE18, &HEX, sizeof(HEX));
		}
	}
	void AUTO_JUMP(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x00B01BAC, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00B01BAC, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x00B01BAC, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00B01BAC, &HEX, sizeof(HEX));
		}
	}

	void AUTO_CHANGE_VIEW(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x00AEF56C, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AEF56C, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x00AEF56C, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AEF56C, &HEX, sizeof(HEX));
		}
	}

	void AUTO_CROUCH(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x00AEF514, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AEF514, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x00AEF514, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AEF514, &HEX, sizeof(HEX));
		}
	}

	void AUTO_MINE(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x40 };
			sys_dbg_write_process_memory(0x00AEC42C, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00AEC42C, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0x41 };
			sys_dbg_write_process_memory(0x00AEC42C, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00AEC42C, &MOD, sizeof(MOD));
		}
	}

	void AUTO_HIT(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x00AEC34C, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AEC34C, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x00AEC34C, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AEC34C, &HEX, sizeof(HEX));
		}
	}

	void AUTO_BUILD(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x00AECF10, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AECF10, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x00AECF10, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AECF10, &HEX, sizeof(HEX));
		}
	}
	void PRESS_X_FOR_HIT(bool toggle)
	{
		if (toggle)
		{
			char SPEED[] = { 0x0F };
			sys_dbg_write_process_memory(0x00AEEB83, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00AEEB83, &SPEED, sizeof(SPEED));
		}
		else
		{
			char SPEED[] = { 0x01 };
			sys_dbg_write_process_memory(0x00AEEB83, &SPEED, sizeof(SPEED));
			sys_dbg_write_process_memory_ps3mapi(0x00AEEB83, &SPEED, sizeof(SPEED));
		}
	}
	void SPECIAL_ITEMS(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x32, 0x1B, 0xB4, 0x20 };
			char HEX1[] = { 0x32, 0x1B, 0xB7, 0xF0 };
			char HEX2[] = { 0x32, 0x1D, 0x45, 0x90 };
			char HEX3[] = { 0x32, 0x1D, 0x9B, 0x10 };
			char HEX4[] = { 0x32, 0x1D, 0x9D, 0xE0 };
			char HEX5[] = { 0x32, 0x1D, 0x70, 0x00 };
			char HEX6[] = { 0x32, 0x20, 0x8D, 0xA0 };
			char HEX7[] = { 0x32, 0x1B, 0xE3, 0xA0 };
			char HEX8[] = { 0x32, 0x1B, 0xE9, 0xF0 };
			char HEX9[] = { 0x32, 0x1B, 0xEC, 0xE0 };
			char HEX10[] = { 0x32, 0x1B, 0xEF, 0xD0 };
			char HEX11[] = { 0x32, 0x1B, 0xF2, 0xC0 };
			char HEX12[] = { 0x32, 0x1B, 0xF5, 0x10 };
			char HEX13[] = { 0x32, 0x1B, 0xF7, 0x60 };
			char HEX14[] = { 0x32, 0x1B, 0xF9, 0xB0 };
			char HEX15[] = { 0x32, 0x1B, 0xFC, 0x00 };
			char HEX16[] = { 0x32, 0x1B, 0xFE, 0x50 };
			char HEX17[] = { 0x32, 0x1C, 0x00, 0xA0 };
			char HEX18[] = { 0x32, 0x1C, 0x84, 0xF0 };
			char HEX19[] = { 0x32, 0x1C, 0x89, 0x90 };
			char HEX20[] = { 0x32, 0x1D, 0x2B, 0x90 };
			char HEX21[] = { 0x32, 0x1D, 0xA7, 0xA0 };
			char HEX22[] = { 0x32, 0x1D, 0xC0, 0x70 };
			char HEX23[] = { 0x32, 0x1E, 0x8D, 0x20 };
			char HEX24[] = { 0x32, 0x1E, 0x8F, 0x70 };
			char HEX25[] = { 0x32, 0x1E, 0x91, 0xC0 };
			char HEX26[] = { 0x32, 0x1E, 0x94, 0x10 };
			char HEX27[] = { 0x32, 0x1E, 0x96, 0x60 };
			char HEX28[] = { 0x32, 0x1E, 0x98, 0xB0 };
			char HEX29[] = { 0x32, 0x20, 0x8F, 0xF0 };
			char HEX30[] = { 0x32, 0x1B, 0xC1, 0x60 };
			char HEX31[] = { 0x32, 0x1B, 0xDA, 0x60 };
			char HEX32[] = { 0x32, 0x1B, 0xDC, 0xB0 };
			char HEX33[] = { 0x32, 0x1B, 0xDF, 0x00 };
			char HEX34[] = { 0x32, 0x1F, 0xB4, 0xC0 };
			char HEX35[] = { 0x32, 0x20, 0x01, 0xC0 };
			char HEX36[] = { 0x32, 0x20, 0x0B, 0xE0 };
			char HEX37[] = { 0x32, 0x20, 0x32, 0x80 };
			char HEX38[] = { 0x32, 0x20, 0x64, 0x20 };

			sys_dbg_write_process_memory(0x3241B6B4, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory(0x3241B7A4, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory(0x3241B894, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory(0x3241B984, &HEX3, sizeof(HEX3));
			sys_dbg_write_process_memory(0x3241BA74, &HEX4, sizeof(HEX4));
			sys_dbg_write_process_memory(0x3241BB64, &HEX5, sizeof(HEX5));
			sys_dbg_write_process_memory(0x3241BC54, &HEX6, sizeof(HEX6));
			sys_dbg_write_process_memory(0x3241BD44, &HEX7, sizeof(HEX7));
			sys_dbg_write_process_memory(0x3241BE34, &HEX8, sizeof(HEX8));
			sys_dbg_write_process_memory(0x3241BF24, &HEX9, sizeof(HEX9));
			sys_dbg_write_process_memory(0x3241C014, &HEX10, sizeof(HEX10));
			sys_dbg_write_process_memory(0x3241C104, &HEX11, sizeof(HEX11));
			sys_dbg_write_process_memory(0x3241B3D4, &HEX12, sizeof(HEX12));
			sys_dbg_write_process_memory(0x3241B284, &HEX13, sizeof(HEX13));
			sys_dbg_write_process_memory(0x3241B134, &HEX14, sizeof(HEX14));
			sys_dbg_write_process_memory(0x3241AFE4, &HEX15, sizeof(HEX15));
			sys_dbg_write_process_memory(0x3241AE94, &HEX16, sizeof(HEX16));
			sys_dbg_write_process_memory(0x3241AD44, &HEX17, sizeof(HEX17));
			sys_dbg_write_process_memory(0x3241ABF4, &HEX18, sizeof(HEX18));
			sys_dbg_write_process_memory(0x3241AAA4, &HEX19, sizeof(HEX19));
			sys_dbg_write_process_memory(0x3241A954, &HEX20, sizeof(HEX20));
			sys_dbg_write_process_memory(0x3241A804, &HEX21, sizeof(HEX21));
			sys_dbg_write_process_memory(0x3241A6B4, &HEX22, sizeof(HEX22));
			sys_dbg_write_process_memory(0x3241A564, &HEX23, sizeof(HEX23));
			sys_dbg_write_process_memory(0x3241A414, &HEX24, sizeof(HEX24));
			sys_dbg_write_process_memory(0x3241A2C4, &HEX25, sizeof(HEX25));
			sys_dbg_write_process_memory(0x3241A174, &HEX26, sizeof(HEX26));
			sys_dbg_write_process_memory(0x3241A024, &HEX27, sizeof(HEX27));
			sys_dbg_write_process_memory(0x32419ED4, &HEX28, sizeof(HEX28));
			sys_dbg_write_process_memory(0x32419D84, &HEX29, sizeof(HEX29));
			sys_dbg_write_process_memory(0x324199F4, &HEX30, sizeof(HEX30));
			sys_dbg_write_process_memory(0x324198A4, &HEX31, sizeof(HEX31));
			sys_dbg_write_process_memory(0x32419754, &HEX32, sizeof(HEX32));
			sys_dbg_write_process_memory(0x32419604, &HEX33, sizeof(HEX33));
			sys_dbg_write_process_memory(0x324194B4, &HEX34, sizeof(HEX34));
			sys_dbg_write_process_memory(0x32419364, &HEX35, sizeof(HEX35));
			sys_dbg_write_process_memory(0x32419214, &HEX36, sizeof(HEX36));
			sys_dbg_write_process_memory(0x324190C4, &HEX37, sizeof(HEX37));
			sys_dbg_write_process_memory(0x32418F74, &HEX38, sizeof(HEX38));

			sys_dbg_write_process_memory_ps3mapi(0x3241B6B4, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x3241B7A4, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x3241B894, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory_ps3mapi(0x3241B984, &HEX3, sizeof(HEX3));
			sys_dbg_write_process_memory_ps3mapi(0x3241BA74, &HEX4, sizeof(HEX4));
			sys_dbg_write_process_memory_ps3mapi(0x3241BB64, &HEX5, sizeof(HEX5));
			sys_dbg_write_process_memory_ps3mapi(0x3241BC54, &HEX6, sizeof(HEX6));
			sys_dbg_write_process_memory_ps3mapi(0x3241BD44, &HEX7, sizeof(HEX7));
			sys_dbg_write_process_memory_ps3mapi(0x3241BE34, &HEX8, sizeof(HEX8));
			sys_dbg_write_process_memory_ps3mapi(0x3241BF24, &HEX9, sizeof(HEX9));
			sys_dbg_write_process_memory_ps3mapi(0x3241C014, &HEX10, sizeof(HEX10));
			sys_dbg_write_process_memory_ps3mapi(0x3241C104, &HEX11, sizeof(HEX11));
			sys_dbg_write_process_memory_ps3mapi(0x3241B3D4, &HEX12, sizeof(HEX12));
			sys_dbg_write_process_memory_ps3mapi(0x3241B284, &HEX13, sizeof(HEX13));
			sys_dbg_write_process_memory_ps3mapi(0x3241B134, &HEX14, sizeof(HEX14));
			sys_dbg_write_process_memory_ps3mapi(0x3241AFE4, &HEX15, sizeof(HEX15));
			sys_dbg_write_process_memory_ps3mapi(0x3241AE94, &HEX16, sizeof(HEX16));
			sys_dbg_write_process_memory_ps3mapi(0x3241AD44, &HEX17, sizeof(HEX17));
			sys_dbg_write_process_memory_ps3mapi(0x3241ABF4, &HEX18, sizeof(HEX18));
			sys_dbg_write_process_memory_ps3mapi(0x3241AAA4, &HEX19, sizeof(HEX19));
			sys_dbg_write_process_memory_ps3mapi(0x3241A954, &HEX20, sizeof(HEX20));
			sys_dbg_write_process_memory_ps3mapi(0x3241A804, &HEX21, sizeof(HEX21));
			sys_dbg_write_process_memory_ps3mapi(0x3241A6B4, &HEX22, sizeof(HEX22));
			sys_dbg_write_process_memory_ps3mapi(0x3241A564, &HEX23, sizeof(HEX23));
			sys_dbg_write_process_memory_ps3mapi(0x3241A414, &HEX24, sizeof(HEX24));
			sys_dbg_write_process_memory_ps3mapi(0x3241A2C4, &HEX25, sizeof(HEX25));
			sys_dbg_write_process_memory_ps3mapi(0x3241A174, &HEX26, sizeof(HEX26));
			sys_dbg_write_process_memory_ps3mapi(0x3241A024, &HEX27, sizeof(HEX27));
			sys_dbg_write_process_memory_ps3mapi(0x32419ED4, &HEX28, sizeof(HEX28));
			sys_dbg_write_process_memory_ps3mapi(0x32419D84, &HEX29, sizeof(HEX29));
			sys_dbg_write_process_memory_ps3mapi(0x324199F4, &HEX30, sizeof(HEX30));
			sys_dbg_write_process_memory_ps3mapi(0x324198A4, &HEX31, sizeof(HEX31));
			sys_dbg_write_process_memory_ps3mapi(0x32419754, &HEX32, sizeof(HEX32));
			sys_dbg_write_process_memory_ps3mapi(0x32419604, &HEX33, sizeof(HEX33));
			sys_dbg_write_process_memory_ps3mapi(0x324194B4, &HEX34, sizeof(HEX34));
			sys_dbg_write_process_memory_ps3mapi(0x32419364, &HEX35, sizeof(HEX35));
			sys_dbg_write_process_memory_ps3mapi(0x32419214, &HEX36, sizeof(HEX36));
			sys_dbg_write_process_memory_ps3mapi(0x324190C4, &HEX37, sizeof(HEX37));
			sys_dbg_write_process_memory_ps3mapi(0x32418F74, &HEX38, sizeof(HEX38));
		}
		else
		{

		}
	}
	void BARRIER(bool toggle)
	{
		//barrier
		if (toggle)
		{
			char HEX[] = { 0x32, 0x1D, 0x70, 0x00 };
			sys_dbg_write_process_memory(0x3241BB64, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x3241BB64, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x32, 0x1E, 0x64, 0xF0 };
			sys_dbg_write_process_memory(0x3241BB64, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x3241BB64, &HEX, sizeof(HEX));
		}
	}
	void SKY_RAINBOW(bool toggle)
	{
		if (toggle)
		{
	
		}
		else
		{
		
		}
	}
	void OPTIMIZE_CHUNKS_LOAD(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x40, 0x30, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00B21C60, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00B21C60, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x40, 0xD7, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00B21C60, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00B21C60, &HEX, sizeof(HEX));


		}
	}
	void FOV_WITHOUT_HAND(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x68 };
			sys_dbg_write_process_memory(0x00987502, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00987502, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x08 };
			sys_dbg_write_process_memory(0x00987502, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00987502, &MOD1, sizeof(MOD1));
		}
	}
	void STOP_WALK_ANIM(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x00, 0x00, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x007D8B0C, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x007D8B0C, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x4F, 0x80, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x007D8B0C, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x007D8B0C, &HEX, sizeof(HEX));


		}
	}
	void NIGHT_VISON(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x7F };
			sys_dbg_write_process_memory(0x00A9A6C8, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A9A6C8, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x3F };
			sys_dbg_write_process_memory(0x00A9A6C8, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A9A6C8, &MOD1, sizeof(MOD1));
		}
	}
	void BETTER_TIME(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x0F };
			sys_dbg_write_process_memory(0x00A9A6DC, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00A9A6DC, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x3F };
			sys_dbg_write_process_memory(0x00A9A6DC, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00A9A6DC, &HEX, sizeof(HEX));
		}
	}
	void WALLHACK(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x3F, 0x00 };
			sys_dbg_write_process_memory(0x00A98F50, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A98F50, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x3D, 0x8C };
			sys_dbg_write_process_memory(0x00A98F50, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A98F50, &MOD1, sizeof(MOD1));
		}
	}
	void XRAY_VISON(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0xFC, 0x80, 0x30, 0x90 };
			sys_dbg_write_process_memory(0x00A99154, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A99154, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0xFC, 0x60, 0x30, 0x90 };
			sys_dbg_write_process_memory(0x00A99154, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A99154, &MOD1, sizeof(MOD1));
		}
	}
	void HORROR_VISION(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x4F, 0x80, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00A9A6C8, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A9A6C8, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x3F, 0x80, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00A9A6C8, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A9A6C8, &MOD1, sizeof(MOD1));
		}
	}
	void GHOST_TEXTURE(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x02 };
			sys_dbg_write_process_memory(0x30012913, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x30012913, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x07 };
			sys_dbg_write_process_memory(0x30012913, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x30012913, &MOD1, sizeof(MOD1));
		}
	}
	void PLASTIC_TEXTURE(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x01 };
			sys_dbg_write_process_memory(0x30012913, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x30012913, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x07 };
			sys_dbg_write_process_memory(0x30012913, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x30012913, &MOD1, sizeof(MOD1));
		}
	}
	void MORE_LIGHT(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x4F, 0xFF };
			sys_dbg_write_process_memory(0x00A9A6D8, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A9A6D8, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x3F, 0xC0 };
			sys_dbg_write_process_memory(0x00A9A6D8, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A9A6D8, &MOD1, sizeof(MOD1));
		}
	}
	void FLAT_BLOCKS(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x01 };
			sys_dbg_write_process_memory(0x000924FF, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x000924FF, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x00 };
			sys_dbg_write_process_memory(0x000924FF, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x000924FF, &MOD1, sizeof(MOD1));
		}
	}
	void VIBRATE_WALK(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x40 };
			sys_dbg_write_process_memory(0x004A3D99, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x004A3D99, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x20 };
			sys_dbg_write_process_memory(0x004A3D99, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x004A3D99, &MOD1, sizeof(MOD1));
		}
	}
	void CHANGE_FOV(int toggle)
	{
		if (toggle == 0)
		{
			char HEX[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x014C670C, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x014C670C, &HEX, sizeof(HEX));
		}

		if (toggle == 1)
		{
			char HEX1[] = { 0x3F, 0x60 };
			sys_dbg_write_process_memory(0x014C670C, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x014C670C, &HEX1, sizeof(HEX1));
		}


		if (toggle == 2)
		{
			char HEX2[] = { 0x3F, 0x50 };
			sys_dbg_write_process_memory(0x014C670C, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory_ps3mapi(0x014C670C, &HEX2, sizeof(HEX2));
		}
		if (toggle == 3)
		{
			char HEX3[] = { 0x3F, 0x40 };
			sys_dbg_write_process_memory(0x014C670C, &HEX3, sizeof(HEX3));
			sys_dbg_write_process_memory_ps3mapi(0x014C670C, &HEX3, sizeof(HEX3));
		}

		if (toggle == 4)
		{
			char HEX4[] = { 0x3F, 0x30 };
			sys_dbg_write_process_memory(0x014C670C, &HEX4, sizeof(HEX4));
			sys_dbg_write_process_memory_ps3mapi(0x014C670C, &HEX4, sizeof(HEX4));
		}

		if (toggle == 5)
		{
			char HEX5[] = { 0x3F, 0x20 };
			sys_dbg_write_process_memory(0x014C670C, &HEX5, sizeof(HEX5));
			sys_dbg_write_process_memory_ps3mapi(0x014C670C, &HEX5, sizeof(HEX5));
		}

		if (toggle == 6)
		{
			char HEX6[] = { 0x3F, 0x10 };
			sys_dbg_write_process_memory(0x014C670C, &HEX6, sizeof(HEX6));
			sys_dbg_write_process_memory_ps3mapi(0x014C670C, &HEX6, sizeof(HEX6));
		}
	}
	void CAMERA_LEFT(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x40 };
			sys_dbg_write_process_memory(0x00A991AC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A991AC, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x41 };
			sys_dbg_write_process_memory(0x00A991AC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A991AC, &MOD1, sizeof(MOD1));
		}
	}
	void CAMERA_RIGHT(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x40 };
			sys_dbg_write_process_memory(0x00A99050, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A99050, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x41 };
			sys_dbg_write_process_memory(0x00A99050, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A99050, &MOD1, sizeof(MOD1));
		}
	}
	void FOOT_STEP_SLOW(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x2F, 0x19 };
			sys_dbg_write_process_memory(0x002267F0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x002267F0, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x3F, 0x19 };
			sys_dbg_write_process_memory(0x002267F0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x002267F0, &MOD1, sizeof(MOD1));
		}
	}
	void SKINS_DEBUG(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x03 };
			sys_dbg_write_process_memory(0x30012AB3, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x30012AB3, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x04 };
			sys_dbg_write_process_memory(0x30012AB3, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x30012AB3, &MOD1, sizeof(MOD1));
		}
	}
	void SHADOW_SKINS(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x2F };
			sys_dbg_write_process_memory(0x003AD388, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003AD388, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x3F };
			sys_dbg_write_process_memory(0x003AD388, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003AD388, &MOD1, sizeof(MOD1));
		}
	}
	void ANIMATION_RUN(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0xBF, 0x80 };
			sys_dbg_write_process_memory(0x003ACEF4, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003ACEF4, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x003ACEF4, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003ACEF4, &MOD1, sizeof(MOD1));
		}
	}
	void SMOKE_LOBBY(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x01 };
			sys_dbg_write_process_memory(0x00B24177, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00B24177, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x00 };
			sys_dbg_write_process_memory(0x00B24177, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00B24177, &MOD1, sizeof(MOD1));
		}
	}
	void SKINS_RED_PLAYERS(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x41 };
			sys_dbg_write_process_memory(0x00AD5B60, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AD5B60, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x40 };
			sys_dbg_write_process_memory(0x00AD5B60, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AD5B60, &MOD1, sizeof(MOD1));
		}
	}
	void BLACK_FOG(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x28 };
			sys_dbg_write_process_memory(0x00AA1B76, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AA1B76, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x08 };
			sys_dbg_write_process_memory(0x00AA1B76, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AA1B76, &MOD1, sizeof(MOD1));
		}
	}
	void FREE_CAM(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x40 };
			sys_dbg_write_process_memory(0x00A98A95, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A98A95, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x30 };
			sys_dbg_write_process_memory(0x00A98A95, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A98A95, &MOD1, sizeof(MOD1));
		}
	}
	void REMOVE_HAND(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x38, 0x60, 0x00, 0x01 };
			sys_dbg_write_process_memory(0x00AF10A8, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AF10A8, &MOD1, sizeof(MOD1));;
		}
		else
		{
			char MOD1[] = { 0x38, 0x60, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00AF10A8, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AF10A8, &MOD1, sizeof(MOD1));
		}
	}
	void HIT_DAMAGE_RED(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0xD0 };
			sys_dbg_write_process_memory(0x00AD5B7A, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AD5B7A, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0xC0 };
			sys_dbg_write_process_memory(0x00AD5B7A, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AD5B7A, &MOD1, sizeof(MOD1));
		}
	}
	void DISABLE_FOG(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0xFF, 0x00 };
			sys_dbg_write_process_memory(0x003A3FF0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003A3FF0, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x003A3FF0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003A3FF0, &MOD1, sizeof(MOD1));
		}
	}
	void ENTITY_TO_BABY(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x01 };
			sys_dbg_write_process_memory(0x0039F52F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0039F52F, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x00 };
			sys_dbg_write_process_memory(0x0039F52F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0039F52F, &MOD1, sizeof(MOD1));
		}
	}
	void REMOVE_DETAILED_SKINS(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x38, 0x60, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x004B2468, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x004B2468, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x38, 0x60, 0x00, 0x01 };
			sys_dbg_write_process_memory(0x004B2468, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x004B2468, &MOD1, sizeof(MOD1));
		}
	}
	void AIM_ON_3TH_PERSON(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x4E, 0x80, 0x00, 0x20 };
			sys_dbg_write_process_memory(0x0090FA30, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0090FA30, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0xF8, 0x21, 0xF5, 0x41 };
			sys_dbg_write_process_memory(0x0090FA30, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0090FA30, &MOD1, sizeof(MOD1));
		}
	}
	void RENDER_ENTITY(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x48, 0xFF, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x0022CE40, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0022CE40, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x40, 0x48, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x0022CE40, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0022CE40, &MOD1, sizeof(MOD1));
		}
	}
	void ROTATION_HEAD(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0xC3 };
			char MOD2[] = { 0x43 };
			sys_dbg_write_process_memory(0x00224FD4, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory(0x00224FD8, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory_ps3mapi(0x00224FD4, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00224FD8, &MOD2, sizeof(MOD2));
		}
		else
		{
			char MOD1[] = { 0xC2 };
			char MOD2[] = { 0x42 };
			sys_dbg_write_process_memory(0x00224FD4, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory(0x00224FD8, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory_ps3mapi(0x00224FD4, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00224FD8, &MOD2, sizeof(MOD2));
		}
	}
	void ROTATION_BODY(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x4E, 0x80, 0x00, 0x20 };
			sys_dbg_write_process_memory(0x003AF338, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003AF338, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0xF8, 0x21, 0xFF, 0x71 };
			sys_dbg_write_process_memory(0x003AF338, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003AF338, &MOD1, sizeof(MOD1));
		}
	}
	void TEXTURE_TO_BLACK(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x40 };
			sys_dbg_write_process_memory(0x00A73854, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A73854, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x41 };
			sys_dbg_write_process_memory(0x00A73854, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A73854, &MOD1, sizeof(MOD1));
		}
	}
	void ENTITY_BODY_LIGHT(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x40 };
			sys_dbg_write_process_memory(0x00AD66C0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AD66C0, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x41 };
			sys_dbg_write_process_memory(0x00AD66C0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AD66C0, &MOD1, sizeof(MOD1));
		}
	}
	void NETHER_VISION(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x40 };
			sys_dbg_write_process_memory(0x00B018D0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00B018D0, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x41 };
			sys_dbg_write_process_memory(0x00B018D0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00B018D0, &MOD1, sizeof(MOD1));
		}
	}
	void PARTICLES_HIT_SPAM(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x00 };
			sys_dbg_write_process_memory(0x00B520F7, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00B520F7, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x01 };
			sys_dbg_write_process_memory(0x00B520F7, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00B520F7, &MOD1, sizeof(MOD1));
		}
	}

	void ROBLOX_ANIMATION(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0xC3 };
			sys_dbg_write_process_memory(0x002341D0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x002341D0, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0xC0 };
			sys_dbg_write_process_memory(0x002341D0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x002341D0, &MOD1, sizeof(MOD1));
		}
	}
	void ENTITY_ELYTRA(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x4E, 0x80, 0x00, 0x20 };
			sys_dbg_write_process_memory(0x003B3008, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003B3008, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0xF8, 0x21, 0xFF, 0x91 };
			sys_dbg_write_process_memory(0x003B3008, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003B3008, &MOD1, sizeof(MOD1));
		}
	}
	void MOVE_HEAD_NO_BODY(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x4E, 0x80, 0x00, 0x20 };
			sys_dbg_write_process_memory(0x003AF338, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003AF338, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0xF8, 0x21, 0xFF, 0x71 };
			sys_dbg_write_process_memory(0x003AF338, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003AF338, &MOD1, sizeof(MOD1));
		}
	}
	void STOP_ANIMATION(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x4E, 0x80, 0x00, 0x20 };
			sys_dbg_write_process_memory(0x003ACF00, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003ACF00, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0xF8, 0x21, 0xFF, 0x71 };
			sys_dbg_write_process_memory(0x003ACF00, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x003ACF00, &MOD1, sizeof(MOD1));
		}
	}
	void GIANT_GAMEPLAY(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x40 };
			sys_dbg_write_process_memory(0x00A98EBC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A98EBC, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x41 };
			sys_dbg_write_process_memory(0x00A98EBC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00A98EBC, &MOD1, sizeof(MOD1));
		}
	}
	void REAL_JUMP_ANIM(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0xBF };
			sys_dbg_write_process_memory(0x014C6728, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x014C6728, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x3F };
			sys_dbg_write_process_memory(0x014C6728, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x014C6728, &MOD1, sizeof(MOD1));
		}
	}
	void DISABLE_PLAYERS(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x48 };
			sys_dbg_write_process_memory(0x001D3BF2, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x001D3BF2, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x08 };
			sys_dbg_write_process_memory(0x001D3BF2, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x001D3BF2, &MOD1, sizeof(MOD1));
		}
	}

	void SMALL_TEXT(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x48 };
			sys_dbg_write_process_memory(0x0079E326, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0079E326, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x08 };
			sys_dbg_write_process_memory(0x0079E326, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0079E326, &MOD1, sizeof(MOD1));
		}
	}
	void ARMS_BROKEN(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x48 };
			sys_dbg_write_process_memory(0x00AD6172, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AD6172, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x08 };
			sys_dbg_write_process_memory(0x00AD6172, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AD6172, &MOD1, sizeof(MOD1));
		}
	}
	void CAMERA_DOWN(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0xFC, 0x02, 0x10 };
			sys_dbg_write_process_memory(0x004B1CE0, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x004B1CE0, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0xFC, 0x01, 0x10 };
			sys_dbg_write_process_memory(0x004B1CE0, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x004B1CE0, &HEX, sizeof(HEX));
		}
	}
	void CAMERA_DOWN_R3(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0xFC, 0x00, 0xF8, 0x90 };
			sys_dbg_write_process_memory(0x004B1D60, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x004B1D60, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0xFC, 0x20, 0xF8, 0x90 };
			sys_dbg_write_process_memory(0x004B1D60, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x004B1D60, &HEX, sizeof(HEX));
		}
	}
	void NAME_OVER_HEAD_V2(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0xFF, 0xC0, 0xE0, 0x90 };
			sys_dbg_write_process_memory(0x00AD8110, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AD8110, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0xFF, 0xC0, 0x10, 0x90 };
			sys_dbg_write_process_memory(0x00AD8110, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AD8110, &HEX, sizeof(HEX));
		}
	}
	void JUMP_IN_SKY(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x00011ADC, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00011ADC, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x00011ADC, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00011ADC, &HEX, sizeof(HEX));
		}
	}
	void CAN_CRAFT(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x01 };
			char MOD4[] = { 0x4E, 0x80, 0x00, 0x20 };
			char MOD3[] = { 0x01 };
			char MOD2[] = { 0x01 };

			sys_dbg_write_process_memory(0x00AED18F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory(0x0098871F, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory(0x007D75A3, &MOD3, sizeof(MOD3));
			sys_dbg_write_process_memory(0x007D767C, &MOD4, sizeof(MOD4));
			sys_dbg_write_process_memory_ps3mapi(0x00AED18F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0098871F, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory_ps3mapi(0x007D75A3, &MOD3, sizeof(MOD3));
			sys_dbg_write_process_memory_ps3mapi(0x007D767C, &MOD4, sizeof(MOD4));
		}
		else
		{
			char MOD1[] = { 0x00 };
			char MOD2[] = { 0x00 };
			char MOD3[] = { 0x00 };
			char MOD4[] = { 0xF8, 0x21, 0xFF, 0x81 };

			sys_dbg_write_process_memory(0x00AED18F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory(0x0098871F, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory(0x007D75A3, &MOD3, sizeof(MOD3));
			sys_dbg_write_process_memory(0x007D767C, &MOD4, sizeof(MOD4));
			sys_dbg_write_process_memory_ps3mapi(0x00AED18F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0098871F, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory_ps3mapi(0x007D75A3, &MOD3, sizeof(MOD3));
			sys_dbg_write_process_memory_ps3mapi(0x007D767C, &MOD4, sizeof(MOD4));
		}
	}

	void CAN_PLACE_BLOCKS(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x01 };
			sys_dbg_write_process_memory(0x007D75A3, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x007D75A3, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x00 };
			sys_dbg_write_process_memory(0x007D75A3, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x007D75A3, &HEX, sizeof(HEX));
		}
	}

	void CAN_SEE_SPECTATOR(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x4E, 0x80, 0x00, 0x20 };
			sys_dbg_write_process_memory(0x007D86A0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007D86A0, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0xF8, 0x21, 0xFF, 0x81 };
			sys_dbg_write_process_memory(0x007D86A0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007D86A0, &MOD1, sizeof(MOD1));
		}
	}

	void PLAYERS_ARE_STARVED(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x4E, 0x80, 0x00, 0x20 };
			sys_dbg_write_process_memory(0x007D7AA0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007D7AA0, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0xF8, 0x21, 0xFF, 0x71 };
			sys_dbg_write_process_memory(0x007D7AA0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007D7AA0, &MOD1, sizeof(MOD1));
		}
	}

	void ALLOW_PORTALS(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x38, 0x60, 0x00, 0x00 };
			sys_dbg_write_process_memory(0x007DC3BC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007DC3BC, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x38, 0x60, 0x00, 0x01 };
			sys_dbg_write_process_memory(0x007DC3BC, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007DC3BC, &MOD1, sizeof(MOD1));
		}
	}

	void TNT_CAN_DESTROY(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x4E, 0x80, 0x00, 0x20 };
			sys_dbg_write_process_memory(0x007D8FB8, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007D8FB8, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0xF8, 0x21, 0xFF, 0x81 };
			sys_dbg_write_process_memory(0x007D8FB8, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007D8FB8, &MOD1, sizeof(MOD1));
		}
	}

	void MAX_PLAYERS_IN_SMALL_MAPS(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x4E, 0x80, 0x00, 0x20 };
			sys_dbg_write_process_memory(0x007D7984, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007D7984, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0xF8, 0x21, 0xFF, 0x81 };
			sys_dbg_write_process_memory(0x007D7984, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007D7984, &MOD1, sizeof(MOD1));
		}
	}

	void CREATIVE_INVENTORY(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x01 };
			sys_dbg_write_process_memory(0x00AED18F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AED18F, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x00 };
			sys_dbg_write_process_memory(0x00AED18F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00AED18F, &MOD1, sizeof(MOD1));
		}
	}

	void CAN_DESTROY_BLOCKS(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x01 };
			sys_dbg_write_process_memory(0x007D75FF, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007D75FF, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x00 };
			sys_dbg_write_process_memory(0x007D75FF, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007D75FF, &MOD1, sizeof(MOD1));
		}
	}

	void GAMEMODE_TO_SURVIVAL(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x4E, 0x80, 0x00, 0x20 };
			sys_dbg_write_process_memory(0x007D88C0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007D88C0, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0xF8, 0x21, 0xFF, 0x81 };
			sys_dbg_write_process_memory(0x007D88C0, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x007D88C0, &MOD1, sizeof(MOD1));
		}
	}
	void LABY_MODE(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0xBF, 0x0F };
			write_process(0x00AD14EC, &MOD, sizeof(MOD));

			char MOD1[] = { 0xBF, 0x23 };
			write_process(0x00AD0274, &MOD1, sizeof(MOD1));

			char MOD2[] = { 0x4C };
			write_process(0x00AD8158, &MOD2, sizeof(MOD2));

			char MOD3[] = { 0x40, 0x82 };
			write_process(0x00B01DEC, &MOD3, sizeof(MOD3));

			char MOD4[] = { 0x40 };
			write_process(0x003097C8, &MOD4, sizeof(MOD4));

			char MOD5[] = { 0x40 };
			write_process(0x003097B8, &MOD5, sizeof(MOD5));

			char MOD6[] = { 0x38, 0x80, 0x00, 0x01 };
			write_process(0x0090B5F0, &MOD6, sizeof(MOD6));

			char MOD7[] = { 0x3F, 0xFF };
			write_process(0x00AD5A5C, &MOD7, sizeof(MOD7));

			char MOD8[] = { 0x40 };
			write_process(0x00227BDC, &MOD8, sizeof(MOD8));
		}
		else
		{
			char MOD[] = { 0x3F, 0x0F };
			write_process(0x00AD14EC, &MOD, sizeof(MOD));

			char MOD1[] = { 0x3F, 0x23 };
			write_process(0x00AD0274, &MOD1, sizeof(MOD1));

			char MOD2[] = { 0x2C };
			write_process(0x00AD8158, &MOD2, sizeof(MOD2));

			char MOD3[] = { 0x41, 0x82 };
			write_process(0x00B01DEC, &MOD3, sizeof(MOD3));

			char MOD4[] = { 0x41 };
			write_process(0x003097C8, &MOD4, sizeof(MOD4));

			char MOD5[] = { 0x41 };
			write_process(0x003097B8, &MOD5, sizeof(MOD5));

			char MOD6[] = { 0x38, 0x80, 0x00, 0x00 };
			write_process(0x0090B5F0, &MOD6, sizeof(MOD6));

			char MOD7[] = { 0x3F, 0x80 };
			write_process(0x00AD5A5C, &MOD7, sizeof(MOD7));

			char MOD8[] = { 0x41 };
			write_process(0x00227BDC, &MOD8, sizeof(MOD8));
		}
	}

	void WEATHER_DARK_STORM(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x3F, 0xFF };
			sys_dbg_write_process_memory(0x00393E34, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00393E34, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x00393E34, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00393E34, &MOD, sizeof(MOD));
		}
	}

	void WEATHER_RAINBOW_STORM(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x4F, 0x80 };
			sys_dbg_write_process_memory(0x00393E34, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00393E34, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x00393E34, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00393E34, &MOD, sizeof(MOD));
		}
	}

	void WEATHER_RAIN_TO_SNOW(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x7E };
			sys_dbg_write_process_memory(0x01310954, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x01310954, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0x3E };
			sys_dbg_write_process_memory(0x01310954, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x01310954, &MOD, sizeof(MOD));
		}
	}

	void WEATHER_RAINBOW_WITH_STORM(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x7E };
			char MOD1[] = { 0x4F };

			sys_dbg_write_process_memory(0x01310954, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory(0x00393E34, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x01310954, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00393E34, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD[] = { 0x3E };
			char MOD1[] = { 0x3F };

			sys_dbg_write_process_memory(0x01310954, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory(0x00393E34, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x01310954, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x00393E34, &MOD1, sizeof(MOD1));
		}
	}

	void WEATHER_FLASH_SKY(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0xFF };
			sys_dbg_write_process_memory(0x00393E34, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00393E34, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x3F };
			sys_dbg_write_process_memory(0x00393E34, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00393E34, &MOD1, sizeof(MOD1));
		}
	}

	void WEATHER_LIGHTNINGBOLD_V1(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x01 };
			sys_dbg_write_process_memory(0x0098871F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0098871F, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x00 };
			sys_dbg_write_process_memory(0x0098871F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0098871F, &MOD1, sizeof(MOD1));
		}
	}

	void WEATHER_LIGHTNINGBOLD_V2(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x01 };
			char MOD2[] = { 0xFF };

			sys_dbg_write_process_memory(0x0098871F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory(0x00393E34, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory_ps3mapi(0x0098871F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00393E34, &MOD2, sizeof(MOD2));
		}
		else
		{
			char MOD1[] = { 0x00 };
			char MOD2[] = { 0x3F };

			sys_dbg_write_process_memory(0x0098871F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory(0x00393E34, &MOD2, sizeof(MOD2));
			sys_dbg_write_process_memory_ps3mapi(0x0098871F, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00393E34, &MOD2, sizeof(MOD2));
		}
	}
	void WHITE_LINE(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x3F, 0xFF };
			sys_dbg_write_process_memory(0x00B25990, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00B25990, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX1[] = { 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00B25990, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B25990, &HEX1, sizeof(HEX1));

			char HEX2[] = { 0x3E, 0xCC };
			sys_dbg_write_process_memory(0x00B25994, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory_ps3mapi(0x00B25994, &HEX2, sizeof(HEX2));


			char HEX3[] = { 0x40, 0x00 };
			sys_dbg_write_process_memory(0x00B25998, &HEX3, sizeof(HEX3));
			sys_dbg_write_process_memory_ps3mapi(0x00B25998, &HEX3, sizeof(HEX3));


			char HEX4[] = { 0x3F, 0x60 };
			sys_dbg_write_process_memory(0x00B259A0, &HEX4, sizeof(HEX4));
			sys_dbg_write_process_memory_ps3mapi(0x00B259A0, &HEX4, sizeof(HEX4));


			char HEX5[] = { 0xFC, 0x40 };
			sys_dbg_write_process_memory(0x00B25A58, &HEX5, sizeof(HEX5));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A58, &HEX5, sizeof(HEX5));


			char HEX6[] = { 0x08 };
			sys_dbg_write_process_memory(0x00B25A5E, &HEX6, sizeof(HEX6));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A5E, &HEX6, sizeof(HEX6));
		}
	}
	void BLACK_LINE(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x4E };
			sys_dbg_write_process_memory(0x00B25994, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00B25994, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX1[] = { 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00B25990, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B25990, &HEX1, sizeof(HEX1));

			char HEX2[] = { 0x3E, 0xCC };
			sys_dbg_write_process_memory(0x00B25994, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory_ps3mapi(0x00B25994, &HEX2, sizeof(HEX2));


			char HEX3[] = { 0x40, 0x00 };
			sys_dbg_write_process_memory(0x00B25998, &HEX3, sizeof(HEX3));
			sys_dbg_write_process_memory_ps3mapi(0x00B25998, &HEX3, sizeof(HEX3));


			char HEX4[] = { 0x3F, 0x60 };
			sys_dbg_write_process_memory(0x00B259A0, &HEX4, sizeof(HEX4));
			sys_dbg_write_process_memory_ps3mapi(0x00B259A0, &HEX4, sizeof(HEX4));


			char HEX5[] = { 0xFC, 0x40 };
			sys_dbg_write_process_memory(0x00B25A58, &HEX5, sizeof(HEX5));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A58, &HEX5, sizeof(HEX5));


			char HEX6[] = { 0x08 };
			sys_dbg_write_process_memory(0x00B25A5E, &HEX6, sizeof(HEX6));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A5E, &HEX6, sizeof(HEX6));
		}
	}
	void BLUE_LINE(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x48 };
			sys_dbg_write_process_memory(0x00B25A5E, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A5E, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX1[] = { 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00B25990, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B25990, &HEX1, sizeof(HEX1));

			char HEX2[] = { 0x3E, 0xCC };
			sys_dbg_write_process_memory(0x00B25994, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory_ps3mapi(0x00B25994, &HEX2, sizeof(HEX2));


			char HEX3[] = { 0x40, 0x00 };
			sys_dbg_write_process_memory(0x00B25998, &HEX3, sizeof(HEX3));
			sys_dbg_write_process_memory_ps3mapi(0x00B25998, &HEX3, sizeof(HEX3));


			char HEX4[] = { 0x3F, 0x60 };
			sys_dbg_write_process_memory(0x00B259A0, &HEX4, sizeof(HEX4));
			sys_dbg_write_process_memory_ps3mapi(0x00B259A0, &HEX4, sizeof(HEX4));


			char HEX5[] = { 0xFC, 0x40 };
			sys_dbg_write_process_memory(0x00B25A58, &HEX5, sizeof(HEX5));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A58, &HEX5, sizeof(HEX5));


			char HEX6[] = { 0x08 };
			sys_dbg_write_process_memory(0x00B25A5E, &HEX6, sizeof(HEX6));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A5E, &HEX6, sizeof(HEX6));
		}
	}
	void PINK_LINE(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x49 };
			sys_dbg_write_process_memory(0x00B25A5E, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A5E, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX1[] = { 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00B25990, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B25990, &HEX1, sizeof(HEX1));

			char HEX2[] = { 0x3E, 0xCC };
			sys_dbg_write_process_memory(0x00B25994, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory_ps3mapi(0x00B25994, &HEX2, sizeof(HEX2));


			char HEX3[] = { 0x40, 0x00 };
			sys_dbg_write_process_memory(0x00B25998, &HEX3, sizeof(HEX3));
			sys_dbg_write_process_memory_ps3mapi(0x00B25998, &HEX3, sizeof(HEX3));


			char HEX4[] = { 0x3F, 0x60 };
			sys_dbg_write_process_memory(0x00B259A0, &HEX4, sizeof(HEX4));
			sys_dbg_write_process_memory_ps3mapi(0x00B259A0, &HEX4, sizeof(HEX4));


			char HEX5[] = { 0xFC, 0x40 };
			sys_dbg_write_process_memory(0x00B25A58, &HEX5, sizeof(HEX5));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A58, &HEX5, sizeof(HEX5));


			char HEX6[] = { 0x08 };
			sys_dbg_write_process_memory(0x00B25A5E, &HEX6, sizeof(HEX6));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A5E, &HEX6, sizeof(HEX6));
		}
	}
	void DRAGON_EGGS_SPAWNER(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x30, 0x99, 0xE7, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C };
			sys_dbg_write_process_memory(0x32418D18, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x32418D18, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0x30, 0x99, 0xD3, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E };
			sys_dbg_write_process_memory(0x32418D18, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x32418D18, &MOD, sizeof(MOD));
		}
	}

	void GOLEM_EGGS_SPAWNER(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x30, 0x99, 0xF6, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E };
			sys_dbg_write_process_memory(0x32418D18, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x32418D18, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0x30, 0x99, 0xD3, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E };
			sys_dbg_write_process_memory(0x32418D18, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x32418D18, &MOD, sizeof(MOD));
		}
	}

	void WITHER_EGGS_SPAWNER(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x77, 0x00, 0x69, 0x00, 0x74, 0x00, 0x68, 0x00, 0x65, 0x00, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06 };
			sys_dbg_write_process_memory(0x32418A79, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x32418A79, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0x73, 0x00, 0x68, 0x00, 0x75, 0x00, 0x6C, 0x00, 0x6B, 0x00, 0x65, 0x00, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07 };
			sys_dbg_write_process_memory(0x32418A79, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x32418A79, &MOD, sizeof(MOD));
		}
	}
	void HUD_MINI_GAME(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x00AD8480, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AD8480, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x00AD8480, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AD8480, &HEX, sizeof(HEX));
		}
	}
	void PARTICLES_FLY(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x0F };
			sys_dbg_write_process_memory(0x00B52100, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00B52100, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x3F };
			sys_dbg_write_process_memory(0x00B52100, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x00B52100, &MOD1, sizeof(MOD1));
		}
	}
	void SKY_PINK(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x42, 0xC0 };
			sys_dbg_write_process_memory(0x00410734, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00410734, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x40, 0xC0 };
			sys_dbg_write_process_memory(0x00410734, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00410734, &HEX, sizeof(HEX));

			char HEX1[] = { 0x3F, 0x80 };
			sys_dbg_write_process_memory(0x00410738, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00410738, &HEX1, sizeof(HEX1));
		}
	}
	void ALL_PLAYERS_CHANGE_HAND(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x30, 0x01, 0x87, 0xF0 };
			sys_dbg_write_process_memory(0x0151F2F0, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x0151F2F0, &MOD, sizeof(MOD));
		}
		else
		{
			char MOD[] = { 0x30, 0x01, 0x87, 0xF8 };
			sys_dbg_write_process_memory(0x0151F2F0, &MOD, sizeof(MOD));
			sys_dbg_write_process_memory_ps3mapi(0x0151F2F0, &MOD, sizeof(MOD));
		}
	}
	void PHASE_MODE(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0xC5 };
			char HEX1[] = { 0x00, 0x00, 0x00, 0x00 };
			char HEX2[] = { 0x44 };
			char HEX3[] = { 0x7F };
			sys_dbg_write_process_memory(0x00AFB448, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory(0x013029BC, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory(0x0022FDC4, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory(0x00B01778, &HEX3, sizeof(HEX3));
			sys_dbg_write_process_memory_ps3mapi(0x00AFB448, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x013029BC, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x0022FDC4, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory_ps3mapi(0x00B01778, &HEX3, sizeof(HEX3));

		}
		else
		{
			char HEX[] = { 0x3F };
			char HEX1[] = { 0x3F, 0xE6, 0x66, 0x66 };
			char HEX2[] = { 0x3F };
			char HEX3[] = { 0x3F };
			sys_dbg_write_process_memory(0x00AFB448, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory(0x013029BC, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory(0x0022FDC4, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory(0x00B01778, &HEX3, sizeof(HEX3));
			sys_dbg_write_process_memory_ps3mapi(0x00AFB448, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x013029BC, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x0022FDC4, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory_ps3mapi(0x00B01778, &HEX3, sizeof(HEX3));
		}
	}
	void HUD_LOADING(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x01 };
			sys_dbg_write_process_memory(0x014CE214, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x014CE214, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x00 };
			sys_dbg_write_process_memory(0x014CE214, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x014CE214, &MOD1, sizeof(MOD1));
		}
	}
	void InventoryCreativeTumble(bool toggle)
	{
		if (toggle)
		{
			*(int*)0x00AD8480 = 0x41820024;
			*(int*)0x0098871C = 0x38600001;
			*(int*)0x002F0348 = 0x38800001;
			*(int*)0x002F0398 = 0x38800000;
		}
		else
		{
			*(int*)0x00AD8480 = 0x40820024;
			*(int*)0x0098871C = 0x38600000;
			*(int*)0x002F0348 = 0x38800000;
			*(int*)0x002F0398 = 0x38800001;
		}
	}
	void ITEMS_2TH_HAND(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x32, 0x1E };
			sys_dbg_write_process_memory(0x014C93F0, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x014C93F0, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x32, 0x20 };
			sys_dbg_write_process_memory(0x014C93F0, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x014C93F0, &HEX, sizeof(HEX));
		}
	}
	void GET_IDS_PLAYERS_ON_HEAD(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x01 };
			sys_dbg_write_process_memory(0x004B5DF3, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x004B5DF3, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x00 };
			sys_dbg_write_process_memory(0x004B5DF3, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x004B5DF3, &HEX, sizeof(HEX));
		}
	}
	void ENABLE_SPECIAL_BLOCK(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x01 };
			sys_dbg_write_process_memory(0x00218A4F, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00218A4F, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x00 };
			sys_dbg_write_process_memory(0x00218A4F, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00218A4F, &HEX, sizeof(HEX));
		}
	}
	void BARRIER_TEST(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x01 };
			write_process(0x321D7000, &MOD, sizeof(MOD));
		}
		else
		{
			
		}
	}
	void BARRIER_TEST_TO_ICE(bool toggle)
	{
		if (toggle)
		{
			char MOD[] = { 0x32, 0x19, 0x93, 0xC0 };
			write_process(0x014C8C84, &MOD, sizeof(MOD));
		}
		else
		{

		}
	}
	void ANTI_KICK_PREMIUM(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x40 };
			sys_dbg_write_process_memory(0x00AEE434, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AEE434, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x41 };
			sys_dbg_write_process_memory(0x00AEE434, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00AEE434, &HEX, sizeof(HEX));
		}
	}
	void LOBBY_MESSAGES_SPAM(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x48 };
			sys_dbg_write_process_memory(0x003A4A36, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003A4A36, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x08 };
			sys_dbg_write_process_memory(0x003A4A36, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x003A4A36, &HEX, sizeof(HEX));
		}
	}
	void GREEN_LINE(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x7E };
			sys_dbg_write_process_memory(0x00B25A59, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A59, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX1[] = { 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00B25990, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B25990, &HEX1, sizeof(HEX1));

			char HEX2[] = { 0x3E, 0xCC };
			sys_dbg_write_process_memory(0x00B25994, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory_ps3mapi(0x00B25994, &HEX2, sizeof(HEX2));


			char HEX3[] = { 0x40, 0x00 };
			sys_dbg_write_process_memory(0x00B25998, &HEX3, sizeof(HEX3));
			sys_dbg_write_process_memory_ps3mapi(0x00B25998, &HEX3, sizeof(HEX3));


			char HEX4[] = { 0x3F, 0x60 };
			sys_dbg_write_process_memory(0x00B259A0, &HEX4, sizeof(HEX4));
			sys_dbg_write_process_memory_ps3mapi(0x00B259A0, &HEX4, sizeof(HEX4));


			char HEX5[] = { 0xFC, 0x40 };
			sys_dbg_write_process_memory(0x00B25A58, &HEX5, sizeof(HEX5));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A58, &HEX5, sizeof(HEX5));


			char HEX6[] = { 0x08 };
			sys_dbg_write_process_memory(0x00B25A5E, &HEX6, sizeof(HEX6));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A5E, &HEX6, sizeof(HEX6));
		}
	}
	void GET_SPECTATOR_GAMEMODE(bool toggle)
	{
		if (toggle)
		{
			char HEX[] = { 0x32, 0x3A };
			sys_dbg_write_process_memory(0x014C9048, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x014C9048, &HEX, sizeof(HEX));
		}
		else
		{
			char HEX[] = { 0x32, 0x39 };
			sys_dbg_write_process_memory(0x014C9048, &HEX, sizeof(HEX));
			sys_dbg_write_process_memory_ps3mapi(0x014C9048, &HEX, sizeof(HEX));
		}
	}
	void BIG_LINE(int toggle)
	{
		if (toggle == 0)
		{
			char HEX1[] = { 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00B25990, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B25990, &HEX1, sizeof(HEX1));

			char HEX2[] = { 0x3E, 0xCC };
			sys_dbg_write_process_memory(0x00B25994, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory_ps3mapi(0x00B25994, &HEX2, sizeof(HEX2));


			char HEX3[] = { 0x40, 0x00 };
			sys_dbg_write_process_memory(0x00B25998, &HEX3, sizeof(HEX3));
			sys_dbg_write_process_memory_ps3mapi(0x00B25998, &HEX3, sizeof(HEX3));


			char HEX4[] = { 0x3F, 0x60 };
			sys_dbg_write_process_memory(0x00B259A0, &HEX4, sizeof(HEX4));
			sys_dbg_write_process_memory_ps3mapi(0x00B259A0, &HEX4, sizeof(HEX4));


			char HEX5[] = { 0xFC, 0x40 };
			sys_dbg_write_process_memory(0x00B25A58, &HEX5, sizeof(HEX5));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A58, &HEX5, sizeof(HEX5));


			char HEX6[] = { 0x08 };
			sys_dbg_write_process_memory(0x00B25A5E, &HEX6, sizeof(HEX6));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A5E, &HEX6, sizeof(HEX6));
		}

		if (toggle == 1)
		{
			char HEX1[] = { 0x41 };
			sys_dbg_write_process_memory(0x00B25998, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B25998, &HEX1, sizeof(HEX1));
		}


		if (toggle == 2)
		{
			char HEX1[] = { 0x42 };
			sys_dbg_write_process_memory(0x00B25998, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B25998, &HEX1, sizeof(HEX1));
		}

		if (toggle == 3)
		{
			char HEX1[] = { 0x60 };
			sys_dbg_write_process_memory(0x00B25998, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B25998, &HEX1, sizeof(HEX1));
		}
	}
	void BOX_LINE(int toggle)
	{
		if (toggle == 0)
		{
			char HEX1[] = { 0x00, 0x00 };
			sys_dbg_write_process_memory(0x00B25990, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B25990, &HEX1, sizeof(HEX1));

			char HEX2[] = { 0x3E, 0xCC };
			sys_dbg_write_process_memory(0x00B25994, &HEX2, sizeof(HEX2));
			sys_dbg_write_process_memory_ps3mapi(0x00B25994, &HEX2, sizeof(HEX2));


			char HEX3[] = { 0x40, 0x00 };
			sys_dbg_write_process_memory(0x00B25998, &HEX3, sizeof(HEX3));
			sys_dbg_write_process_memory_ps3mapi(0x00B25998, &HEX3, sizeof(HEX3));


			char HEX4[] = { 0x3F, 0x60 };
			sys_dbg_write_process_memory(0x00B259A0, &HEX4, sizeof(HEX4));
			sys_dbg_write_process_memory_ps3mapi(0x00B259A0, &HEX4, sizeof(HEX4));


			char HEX5[] = { 0xFC, 0x40 };
			sys_dbg_write_process_memory(0x00B25A58, &HEX5, sizeof(HEX5));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A58, &HEX5, sizeof(HEX5));


			char HEX6[] = { 0x08 };
			sys_dbg_write_process_memory(0x00B25A5E, &HEX6, sizeof(HEX6));
			sys_dbg_write_process_memory_ps3mapi(0x00B25A5E, &HEX6, sizeof(HEX6));
		}

		if (toggle == 1)
		{
			char HEX1[] = { 0xA0 };
			sys_dbg_write_process_memory(0x00B259A0, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B259A0, &HEX1, sizeof(HEX1));
		}

		if (toggle == 2)
		{
			char HEX1[] = { 0xB0 };
			sys_dbg_write_process_memory(0x00B259A0, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B259A0, &HEX1, sizeof(HEX1));
		}

		if (toggle == 3)
		{
			char HEX1[] = { 0xD0 };
			sys_dbg_write_process_memory(0x00B259A0, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B259A0, &HEX1, sizeof(HEX1));
		}

		if (toggle == 4)
		{
			char HEX1[] = { 0xFF };
			sys_dbg_write_process_memory(0x00B259A0, &HEX1, sizeof(HEX1));
			sys_dbg_write_process_memory_ps3mapi(0x00B259A0, &HEX1, sizeof(HEX1));
		}
	}


	void TELEPORT_TO_LOBBY()
	{
		JUMP_IN_SKY(true);
		AUTO_JUMP(true);
		sleep(1000);
		Modules::setLocation(-343, 57, -341);
		JUMP_IN_SKY(false);
		AUTO_JUMP(false);
		MULTI_JUMP(true);
		DrawTextWithRect(L"TP To Lobby", 160, 40, color(MC_Color::White));
	}

	void TELEPORT_TO_COVE()
	{
		if (TeleportCove)
		{
			JUMP_IN_SKY(true);
			AUTO_JUMP(true);
			sleep(1000);
			Modules::setLocation(219, 65, -220);
			JUMP_IN_SKY(false);
			AUTO_JUMP(false);
			MULTI_JUMP(true);
			DrawTextWithRect(L"TP To Cove", 160, 40, color(MC_Color::White));
		}
	}

	void TELEPORT_TO_CAVERN()
	{
		JUMP_IN_SKY(true);
		AUTO_JUMP(true);
		sleep(1000);
		Modules::setLocation(-222, 66, 287);
		JUMP_IN_SKY(false);
		AUTO_JUMP(false);
		MULTI_JUMP(true);
		DrawTextWithRect(L"TP To Cavern", 160, 40, color(MC_Color::White));
	}

	void TELEPORT_TO_CRUCIBLE()
	{
		JUMP_IN_SKY(true);
		AUTO_JUMP(true);
		sleep(1000);
		Modules::setLocation(317, 76, 301);
		JUMP_IN_SKY(false);
		AUTO_JUMP(false);
		MULTI_JUMP(true);
		DrawTextWithRect(L"TP To Crucible", 160, 40, color(MC_Color::White));
	}
}
#pragma endregion

namespace Options
{
	char* getName()
	{
		if (*(int*)0x3000ABE4 == 0x00000000)
			return (char*)NyTekCFW::ReadString(0x3000ABA4);
		else
			return (char*)NyTekCFW::ReadString(0x3000AD34);
	}

	char* PLR_PSN()
	{
		if (*(int*)0x30F46AD8 == 0xFFFFFFFF)
		{
			PLR_NAME = "N/A    ";
			PLR_REGION = "N/A    ";
		}
		else
		{
			if (*(int*)0x30F46AC4 == 0xFFFFFFFF)
			{
				PLR_NAME = "N/A    ";
				PLR_REGION = "N/A    ";
			}
			else
			{
				PLR_NAME = PS3Lib::ReadString(0x30F46AC4);
				PLR_REGION = PS3Lib::ReadString(0x30F46AD8);
			}
		}

		strcpy((char*)0x3000AF0A, PLR_NAME); //unique ID

		DrawRectangle(15, 70, 90, 24, MC_Color::BlackTheme);
		DrawTextC(PLR_NAME, 20, 74, color(MC_Color::White));
		DrawTextC(PLR_REGION, 20, 84, color(MC_Color::White));
	
	
	
	}
	
	void getTeleport()
	{
		CoordX = (int)mc->theMinecraft->cMultiplayerLocalPlayer->posX;
		CoordY = (int)mc->theMinecraft->cMultiplayerLocalPlayer->posY;
		CoordZ = (int)mc->theMinecraft->cMultiplayerLocalPlayer->posZ;
	}
	
	void setTeleport(double X, double Y, double Z)
	{
		mc->theMinecraft->cMultiplayerLocalPlayer->SetPosition(X + 0.5, Y + 1 + 0.5, Z + 0.5);
	}
	
	void ShowPSN()
	{
		if (TogglePSN)
		{
			char* name;
			name = getName();

			DrawTextDebugPlayer(L"PSN: ", 19, 36, MC_Color::BlackTheme, MC_Color::White, false);
			DrawTextCharWithRectangle(name, 40, 36, MC_Color::BlackTheme, MC_Color::White, false);
		}
	}

	void ShowGametime()
	{
		if (ToggleGametime)
		{
			int milliseconds, seconds, minutes, hours;
			milliseconds = mc->gameTime; seconds = (milliseconds / 60); minutes = seconds / 60; hours = minutes / 60;
			int gametime[3] = { int(hours % 24), int(minutes % 60), int(seconds % 60) };
			DrawsnprintfText("Gametime: %ih:%imin:%isec", gametime, 19, 46, true);
		}
	}

	void ShowPosition()
	{
		if (TogglePosition)
		{
			int position[3] = { mc->theMinecraft->cMultiplayerLocalPlayer->LocationX, mc->theMinecraft->cMultiplayerLocalPlayer->LocationY, mc->theMinecraft->cMultiplayerLocalPlayer->LocationZ };
			DrawsnprintfText("Position: %i, %i, %i", position, 19, 56, true);
		}
	}

	void ShowChunks()
	{
		if (ToggleChunks)
		{
			int getChunks[3] = { (int)mc->theMinecraft->cMultiplayerLocalPlayer->chunkCoordX + 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->chunkCoordY + 1, (int)mc->theMinecraft->cMultiplayerLocalPlayer->chunkCoordZ + 1 };
			DrawsnprintfText("Chunks: %i, %i, %i", getChunks, 19, 66, true);
		}
	}

	void ShowResolution()
	{
		if (ToggleResolution)
		{
			int getResolution[2] = { mc->theMinecraft->displayWidth, mc->theMinecraft->displayHeight };
			DrawsnprintfText("Resolution: %ix%i", getResolution, 19, 76, true);
		}
	}

	void ShowPing()
	{
		if (TogglePing)
		{
			int getPing[] = { mc->FPS };
			DrawsnprintfText("Ping: %i ms", getPing, 19, 86, true);
		}
	}

	void ShowDebugPlayer()
	{
		if (ToggleDebugPlayer)
		{
			if (mc->theMinecraft->cMultiplayerLocalPlayer->isInWeb == true)
			{
				DrawTextDebugPlayer(L"[In Web]", 19, 96, MC_Color::BlackTheme, MC_Color::White, true);
			}
			if (mc->theMinecraft->cMultiplayerLocalPlayer->IsSprinting())
			{
				DrawTextDebugPlayer(L"[Sprinting]", 19, 96, MC_Color::BlackTheme, MC_Color::White, true);
			}
			else if (mc->theMinecraft->cMultiplayerLocalPlayer->IsSneaking())
			{
				DrawTextDebugPlayer(L"[Sneaking]", 19, 96, MC_Color::BlackTheme, MC_Color::White, true);
			}
			else if (mc->theMinecraft->cMultiplayerLocalPlayer->IsSpectator())
			{
				DrawTextDebugPlayer(L"[Spectator]", 19, 96, MC_Color::BlackTheme, MC_Color::White, true);
			}
			else if (mc->theMinecraft->cMultiplayerLocalPlayer->IsBurning())
			{
				DrawTextDebugPlayer(L"[Burning]", 19, 96, MC_Color::BlackTheme, MC_Color::White, true);
			}
			else if (mc->theMinecraft->cMultiplayerLocalPlayer->isInWater())
			{
				DrawTextDebugPlayer(L"[In Water]", 19, 96, MC_Color::BlackTheme, MC_Color::White, true);
			}
			else if (mc->theMinecraft->cMultiplayerLocalPlayer->fallDistance > 0)
			{
				DrawTextDebugPlayer(L"[Falling]", 19, 96, MC_Color::BlackTheme, MC_Color::White, true);
			}
			else if (mc->theMinecraft->cMultiplayerLocalPlayer->onGround == true)
			{
				DrawTextDebugPlayer(L"[On Ground]", 19, 96, MC_Color::BlackTheme, MC_Color::White, true);
			}
			else if (mc->theMinecraft->cMultiplayerLocalPlayer->isDead == true)
			{
				DrawTextDebugPlayer(L"[Is Dead]", 19, 96, MC_Color::BlackTheme, MC_Color::White, true);
			}
		}
	}
	void ShowKeystrokes()
	{
		if (ToggleKeystrokes)
		{
			bool KeyPressedUP, KeyPressedDOWN, KeyPressedLEFT, KeyPressedRIGHT, KeyPressedSPACE;
			char* keystrokes_text[] = { "W    ", "S    ", "A    ", "D    " };

			if (Buttons::IsMCButtonPressed(Buttons::JOYSTICK_L3_UP))
				KeyPressedUP = true; else KeyPressedUP = false;

			if (Buttons::IsMCButtonPressed(Buttons::JOYSTICK_L3_DOWN))
				KeyPressedDOWN = true; else KeyPressedDOWN = false;

			if (Buttons::IsMCButtonPressed(Buttons::JOYSTICK_L3_LEFT))
				KeyPressedLEFT = true; else KeyPressedLEFT = false;

			if (Buttons::IsMCButtonPressed(Buttons::JOYSTICK_L3_RIGHT))
				KeyPressedRIGHT = true; else KeyPressedRIGHT = false;

			if (Buttons::IsMCButtonPressed(Buttons::X))
				KeyPressedSPACE = true; else KeyPressedSPACE = false;

			int* KeyUPColor = KeyPressedUP ? Rainbow : MC_Color::LightPurple;
			int* KeyDOWNColor = KeyPressedDOWN ? Rainbow : MC_Color::LightPurple;
			int* KeyLEFTColor = KeyPressedLEFT ? Rainbow : MC_Color::LightPurple;
			int* KeyRIGHTColor = KeyPressedRIGHT ? Rainbow : MC_Color::LightPurple;
			int* KeySPACEColor = KeyPressedSPACE ? Rainbow : MC_Color::LightPurple;

			int* keystrokesHudColor2[] = { KeyUPColor, KeyDOWNColor, KeyLEFTColor, KeyRIGHTColor, KeySPACEColor, MC_Color::White };

			for (byte a = 0; a < 6; a++)
				DrawRectangleBorder(keystrokesBase_x + keystrokesHudX[a], keystrokesBase_y + keystrokesHudY[a], HudW[a], HudH[a], keystrokesHudColor1[a], keystrokesHudColor2[a], 1);

			for (byte b = 0; b < 4; b++)
				DrawTextC(keystrokes_text[b], keystrokesBase_x + keystrokes_TextX[b], keystrokesBase_y + keystrokes_TextY[b], color(keystrokes_TextColor[b]));
		}
	}
	
	void KAura()
	{
		if (ToggleKAura)
		{
			char* PLR_PSN();

			DrawTextDebugPlayer(L"[Kaura V.01]  -  |  Target:", 230, 254, MC_Color::BlackTheme, MC_Color::White, true);
			DrawTextCharWithRectangle(PLR_NAME, 339, 254, MC_Color::BlackTheme, MC_Color::White, false);
			
			if (PLR_NAME == "AzeY-_-YT_-")
			{
				DrawTextCharWithRectangle("AzeY is here !", 37, 314, MC_Color::BlackTheme, MC_Color::White, false);
			}
		}
	}
	
	void Bedrock_Hotbar(bool toggle)
	{
		if (toggle)
		{
			char MOD1[] = { 0x40 };
			sys_dbg_write_process_memory(0x0090FB6C, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0090FB6C, &MOD1, sizeof(MOD1));
		}
		else
		{
			char MOD1[] = { 0x20 };
			sys_dbg_write_process_memory(0x0090FB6C, &MOD1, sizeof(MOD1));
			sys_dbg_write_process_memory_ps3mapi(0x0090FB6C, &MOD1, sizeof(MOD1));
		}
	}
	
	void BEDROCK_UI(bool toggle)
	{
		if (toggle)
		{
		*(int*)0x31E7879C = 0x42800000;
		*(int*)0x31E787A0 = 0x44158000;
		*(int*)0x31F4D3D0 = 0x42B00000;
		*(int*)0x31E788CC = 0x44850000;
		*(int*)0x00A891D0 = 0xC1505C29;
		*(int*)0x31F4D2A0 = 0x42540000;
		*(int*)0x31F4D170 = 0x42540000;
		*(int*)0x31F4D500 = 0x42940000;
		*(int*)0x31E78A4C = 0x44848000;
		*(int*)0x31E78A50 = 0x44158000;
		*(int*)0x31E78B7C = 0x44848000;
		*(int*)0x31E78B80 = 0x44078000;
	    }
		else
		{

		}
	}
}