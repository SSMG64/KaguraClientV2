#pragma once

namespace logs
{
	Color BLACK_OPACITY{ 15, 15, 15, 200 };
	typedef int64_t _QWORD;
	signed char logs_count = -1;
	uint64_t get_time_now()
	{
		return sys_time_get_system_time() / 1000;
	}
	struct timer_fade
	{
		wchar_t* message;
		int color[3];
		_QWORD start_time;
		_QWORD end_time;
		int duration;
	};
	timer_fade logs[12];

	void debugMessage(wchar_t* logsmsg = L"", int* color = MC_Color::White, int duration = 10000)//10sec
	{
		for (byte a = 11; a > 0; a--)
		{
			logs[a].message = logs[a - 1].message;
			logs[a].color[0] = logs[a - 1].color[0];
			logs[a].color[1] = logs[a - 1].color[1];
			logs[a].color[2] = logs[a - 1].color[2];
			logs[a].color[3] = 0xFF;
			logs[a].start_time = logs[a - 1].start_time;
			logs[a].end_time = logs[a - 1].end_time;
		}
		logs[0].message = logsmsg;
		logs[0].color[0] = color[0];
		logs[0].color[1] = color[1];
		logs[0].color[2] = color[2];
		logs[0].start_time = get_time_now();
		logs[0].end_time = logs[0].start_time + duration;
		if (logs_count < 11)
			logs_count++;
	}

	void draw_logs()
	{
		if (logs[0].message != NULL)
		{
			if (logs_count > -1)
			{
				Color BLACK_OPACITY{ 15, 15, 15, 210 };
				DrawRectangleAlpha(0, 257, 190, 246 - (10 * logs_count), BLACK_OPACITY);
			}

			for (byte a = 0; a < logs_count + 1; a++)
			{
				DrawText(logs[a].message, 5, 248 - ((a * 10)), color(logs[a].color));
				if (get_time_now() >= logs[a].end_time)
				{
					logs[a].message = L"";
					logs_count--;
				}
			}
		}
	}
}

namespace Menu
{
	void TitleSPRX(const wchar_t* title)
	{
		if (ToggleTitleSPRX)
			DrawTextWithRectangle(title, 19, 10, MC_Color::BlackTheme, true);
	}
	void Scrollbar()
	{
		int RAINBOW[3] = { RainbowRED1, RainbowGREEN1, RainbowBLUE1 };
		DrawRectangle(MenuX + 508, MenuY + 58 + (10 * CurrentOpt), 132, 10, RAINBOW);
	}

	void AddHuds()
	{
		int RAINBOW[3] = { RainbowRED1, RainbowGREEN1, RainbowBLUE1 };
		DrawRectangleBorder(MenuX + 508, MenuY + 23, 132, 299, MC_Color::BlackTheme, RAINBOW, 2);
	}

	void AddTitle(const wchar_t* title)
	{
		int RAINBOW[3] = { RainbowRED1, RainbowGREEN1, RainbowBLUE1 };
		AddHuds();
		Scrollbar();

		int width = Font_width(title);
		DrawRectangle(MenuX + 543, MenuY + 34, 1, 11, RAINBOW);
		DrawRectangle(MenuX + 543, MenuY + 45, width + 6, 1, RAINBOW);
		DrawTextWithShadow(title, MenuX + 547, MenuY + 35, color(MC_Color::LightPurple));
	}

	void AddOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		DrawText(L"     ", MenuX + 630, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		MaxOption += 1;
	}
	void AddOptionToggle(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		DrawText(L">     ", MenuX + 630, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		MaxOption += 1;
	}
	void AddDescOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		DrawText(L"Made By AzeY with <3     ", MenuX + 533, MenuY + 60 + (10 * MaxOption), color(MC_Color::LightPurple));
		MaxOption += 1;
	}

	void AddInstructionOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		DrawText(L"Back: O  Scroll: UP / DOWN  Select: X     ", MenuX + 515, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		MaxOption += 1;
	}

	void AddInfoOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		DrawText(L"Custom Sky & Bedrock Hotbar     ", MenuX + 511, MenuY + 60 + (10 * MaxOption), color(MC_Color::Red));
		MaxOption += 1;
	}

	void AddInfoOption2(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		DrawText(L"Can't be desactivate     ", MenuX + 530, MenuY + 60 + (10 * MaxOption), color(MC_Color::Red));
		MaxOption += 1;
	}

	void AddSubOption(const wchar_t* option)
	{
		DrawText(option, MenuX + 513, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		DrawText(L">     ", MenuX + 630, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		MaxOption += 1;
	}

	void Description(const wchar_t* description)
	{
		DrawText(description, MenuX + 510, MenuY + 60, color(MC_Color::White));
		int index[] = { CurrentOpt + 1, MaxSubOptions };
		DrawsnprintfText("%i/%i     ", index, MenuX + 613, MenuY + 50, false);
	}

	void AddBoolOption(const wchar_t* option, bool toggle)
	{
		int* insideColor = toggle ? MC_Color::Red : MC_Color::Green;
		int outsideColor[3] = { 32, 32, 32 };
		DrawText(option, MenuX + 513, MenuY + 60 + (10 * MaxOption), color(MC_Color::White));
		DrawRectangleBorder(MenuX + 630, MenuY + 61 + (10 * MaxOption), 5, 5, insideColor, outsideColor, 1);
		MaxOption += 1;
	}
	void AddIntOption(const wchar_t* option, int currentopt, int min, int max, int& IntOption)
	{
		int value = { IntOption };
		DrawText(option, 513 + MenuX, 60 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));

		if (CurrentOpt == currentopt)
		{
			if (Buttons::IsMCButtonPressed(Buttons::LEFT))
			{
				if (frameTime(2, 1, false))
				{
					if (IntOption < min + 1)
						IntOption = max;
					else
						IntOption = IntOption - 1;
				}
			}
			if (Buttons::IsMCButtonPressed(Buttons::RIGHT))
			{
				if (frameTime(2, 1, false))
				{
					if (IntOption > max - 1)
						IntOption = min;
					else
						IntOption = IntOption + 1;
				}
			}
		}

		if (value > 99)
			DrawSnprintf("< %i >    ", value, 600 + MenuX + menuLenght, 60 + MenuY + (SpaceBetweenText * MaxOption));
		else
			DrawSnprintf("< %i >    ", value, 600 + MenuX + menuLenght, 60 + MenuY + (SpaceBetweenText * MaxOption));
		MaxOption += 1;
	}
	void AddIntOptionSlow(const wchar_t* option, int currentopt, int min, int max, int& IntOption)
	{
		int value = { IntOption };
		DrawText(option, 513 + MenuX, 60 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));

		if (CurrentOpt == currentopt)
		{
			if (Buttons::IsMCButtonPressed(Buttons::LEFT))
			{
				if (frameTime(5, 1, false))
				{
					if (IntOption < min + 1)
						IntOption = max;
					else
						IntOption = IntOption - 1;
				}
			}
			if (Buttons::IsMCButtonPressed(Buttons::RIGHT))
			{
				if (frameTime(5, 1, false))
				{
					if (IntOption > max - 1)
						IntOption = min;
					else
						IntOption = IntOption + 1;
				}
			}
		}

		if (value > 99)
			DrawSnprintf("< %i >    ", value, 610 + MenuX + menuLenght, 60 + MenuY + (SpaceBetweenText * MaxOption));
		else
			DrawSnprintf("< %i >    ", value, 610 + MenuX + menuLenght, 60 + MenuY + (SpaceBetweenText * MaxOption));
		MaxOption += 1;
	}
	void AddIntOptionDCV4(const wchar_t* opt, int def, int IntOptions)
	{
		if (Menu::Scrollbar)
		{
			DrawText(opt, 513 + MenuX, 60 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		}
		else
		{
			DrawText(opt, 513 + MenuX, 60 + MenuY + (SpaceBetweenText * MaxOption), color(MC_Color::White));
		}

		if (IntOptions > 99)
		{
			if (!Menu::Scrollbar)
			{
				DrawRectangle(AddOptX, (MaxOption == CurrentOpt) ? AddOptY - 2 + (10 * MaxOption) : AddOptY - 2, 1, 10, (MaxOption == CurrentOpt) ? MC_Color::Black : MC_Color::Black);
				DrawRectangle(AddOptX, AddOptY + 8 + (10 * MaxOption), bgW + menulenght - 6, 1, (MaxOption == CurrentOpt) ? MC_Color::Black : MC_Color::Black);
			}

			if (IntOptions == def)
			{
				DrawText(L"< Default >    ", CheckBoxX - 56 + menulenght, CheckBoxY + (10 * MaxOption), color(MC_Color::White));
			}
		}
		else
		{
			if (!Menu::Scrollbar)
			{
				DrawRectangle(AddOptX, (MaxOption == CurrentOpt) ? AddOptY - 2 + (10 * MaxOption) : AddOptY - 2, 1, 10, (MaxOption == CurrentOpt) ? MC_Color::Black : MC_Color::Black);
				DrawRectangle(AddOptX, AddOptY + 8 + (10 * MaxOption), bgW + menulenght - 6, 1, (MaxOption == CurrentOpt) ? MC_Color::Black : MC_Color::Black);
			}
			if (IntOptions == def)
			{
				DrawText(L"< Default >    ", CheckBoxX - 56 + menulenght, CheckBoxY + (10 * MaxOption), color(MC_Color::White));
			}
		}
		MaxOption += 1;
	}
	char* ThemeColors = "DEFAULT";
}