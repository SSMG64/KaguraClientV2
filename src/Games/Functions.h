#pragma once

#pragma region "Menu Functions"

typedef union RGB
{
	struct
	{
		union { int red; int R; };
		union { int green; int G; };
		union { int blue; int B; };
	};
	int color[3];
} RGB;

RGB MenuColour1 = { 90, 0, 0 };
RGB MenuColour2 = { 0, 0, 180 };

void DoRainbowColor()
{
	// Vitesse de défilement des couleurs (en millisecondes)
	const int colorChangeDelay = 10;  // 10 millisecondes

	if (RainbowTime < mc->gameTime)
	{
		static int step = 0;
		static int change = 1;

		// Changez progressivement la couleur
		step += change;

		// Inversez la direction du changement à chaque extrémité
		if (step <= 0 || step >= 255)
			change = -change;

		// Définissez la couleur en fonction de l'étape
		RainbowRED1 = (step <= 128) ? (128 + step) : (383 - step);
		RainbowGREEN1 = 0;
		RainbowBLUE1 = (step <= 128) ? 255 : (383 - step);

		// Mettez en pause pour ralentir le changement de couleur
		// avant de changer la couleur suivante
		sleep(colorChangeDelay);

		// Mettez à jour les valeurs des couleurs
		RainbowTime = mc->gameTime;
	}
}

void openSubmenu(int menu)
{
	lastMenus[lastMenuCount] = CurrentMenu;
	lastMenuCount++;
	CurrentOpt = 0;
	CurrentMenu = menu;
}

void SlideOpenMenuAnimation()
{
	if (Opened && !Closed)
	{
		if (MenuX > -41)
		{
			MenuX -= speedSlider;
		}
	}
}

void SlideCloseMenuAnimation()
{
	if (Closed)
	{
		MenuX += speedSlider;

		if (MenuX > 200)
		{
			Opened = false;
			Closed = false;
		}
	}
}

void Controller()
{
	int wI = 0;
	keyPressed[wI] = false;

	if (Buttons::IsMCButtonPressed(Buttons::L1) && Buttons::IsMCButtonPressed(Buttons::UP))
	{
		if (!Opened)
		{
			Opened = true;
			CurrentMenu = MainMenu;
			MenuX = 200;
		}
	}

	if (Opened)
	{
		if (Buttons::IsMCButtonPressed(Buttons::UP))
		{
			if (scrollWait(firstWaitTime, waitTime, wI))
			{
				CurrentOpt = CurrentOpt - 1;
				return;
			}
		}

		if (Buttons::IsMCButtonPressed(Buttons::DOWN))
		{
			if (scrollWait(firstWaitTime, waitTime, wI))
			{
				CurrentOpt = CurrentOpt + 1;
				return;
			}
		}

		int fix = MaxSubOptions;
		fix -= 1;

		if (CurrentOpt > fix)
			CurrentOpt = 0;

		if (CurrentOpt < 0)
			CurrentOpt = fix;

		if (Buttons::IsMCButtonPressed(Buttons::X))
		{
			if (scrollWait(firstWaitTime, waitTime, wI))
			{
				optionPress = true;
				return;
			}
		}

		if (Buttons::IsMCButtonPressed(Buttons::O))
		{
			if (scrollWait(firstWaitTime, waitTime, wI))
			{
				returnPress = true;
				return;
			}
		}

		if (!keyPressed[wI])
		{
			lockFirst[wI] = false;
			freeFirst[wI] = true;
			resetWait[wI] = true;
			resetWait2[wI] = true;
		}
	}
}

void DrawTextWithRect(const wchar_t* text, float x, float y, uint32_t color)
{
	int width = Font_width(text);
	DrawRectangle(x - 3, y - 1, width + 5, 10, MC_Color::BlackTheme);
	DrawText(text, x, y, color);
}

#pragma endregion

#pragma region "Get last player infos"
void GetInfosLastPlayer()
{
	if (PlayersInfos)
	{

		if (*(int*)0x30F46AD8 == 0xFFFFFFFF)
		{
			PLR_NAME = "    ";
			PLR_REGION = "    ";
		}
		else
		{
			if (*(int*)0x30F46AC4 == 0xFFFFFFFF)
			{
				PLR_NAME = "    ";
				PLR_REGION = "    ";
			}
			else
			{
				PLR_NAME = PS3Lib::ReadString(0x30F46AC4);
				PLR_REGION = PS3Lib::ReadString(0x30F46AD8);
			}
		}

		strcpy((char*)0x3000AF0A, PLR_NAME); //unique ID

		if (PLR_NAME == "AzeY-_-YT_-")
		{
			DrawText(L"AzeY is here !", 37, 314, color(MC_Color::LightPurple));
		}
	}
}
#pragma endregion

void ChangeIntOptions(bool page, int currentopt, int min, int max, int& value)
{
	if (page)
	{
		if (CurrentOpt == currentopt)
		{
			if (Buttons::IsMCButtonPressed(Buttons::LEFT))
			{
				if (frameTime(3, 1, false))
				{
					if (value < min + 1)
					{
						value = max;
					}
					else
					{
						value = value - 1;
					}
				}
			}
			else if (Buttons::IsMCButtonPressed(Buttons::RIGHT))
			{
				if (frameTime(3, 1, false))
				{
					if (value > max - 1)
					{
						value = min;
					}
					else
					{
						value = value + 1;
					}
				}
			}
		}
	}
}

void INITIALIZE_START()
{
	sleep(30000);

	strcpy((char*)0x320E8410, "Alone - Kagura Client V2 SPRX");
	strcpy((char*)0x320E89E0, "Multiplayer - Kagura Client V2 SPRX");
	//Show actualy game states = 0x017003D8
}