#pragma once

int getOption()
{
	if (optionPress)
	{
		optionPress = false;
		return CurrentOpt;
	}
	else return -1;
}

void RenderClosePage()
{
	if (returnPress)
	{
		returnPress = false;
		CurrentOpt = 0;
		if (CurrentMenu == MainMenu)
			Closed = true;
		else if (CurrentMenu == InGameMenu)
			CurrentMenu = MainMenu;
		else if (CurrentMenu == HostOptions)
			CurrentMenu = InGameMenu;
		else if (CurrentMenu == HostOptions2)
			CurrentMenu = HostOptions;
		else if (CurrentMenu == NoHostOptions)
			CurrentMenu = InGameMenu;
		else if (CurrentMenu == NoHostOptions2)
			CurrentMenu = NoHostOptions;
		else if (CurrentMenu == FunnyOptions)
			CurrentMenu = InGameMenu;
		else if (CurrentMenu == MiniGamesMenu)
			CurrentMenu = InGameMenu;
		else if (CurrentMenu == MiniGamesMenu2)
			CurrentMenu = MiniGamesMenu;
		else if (CurrentMenu == WeatherMenu)
			CurrentMenu = InGameMenu;
		else if (CurrentMenu == VisualMenu)
			CurrentMenu = MainMenu;
		else if (CurrentMenu == ShowOptions)
			CurrentMenu = VisualMenu;
		else if (CurrentMenu == KeySettings)
			CurrentMenu = ShowOptions;
		else if (CurrentMenu == SelectionOptions)
			CurrentMenu = VisualMenu;
		else if (CurrentMenu == VisualMenu2)
			CurrentMenu = VisualMenu;
		else if (CurrentMenu == TeleportMenu)
			CurrentMenu = MainMenu;
		else if (CurrentMenu == ModulesMenu)
			CurrentMenu = MainMenu;
		else if (CurrentMenu == SettingsMenu)
			CurrentMenu = MainMenu;
		else if (CurrentMenu == CreditsMenu)
			CurrentMenu = MainMenu;
		else if (CurrentMenu == AzeYCredits)
			CurrentMenu = CreditsMenu;
		else if (CurrentMenu == MisakiCredits)
			CurrentMenu = CreditsMenu;
		else if (CurrentMenu == EternalCredits)
			CurrentMenu = CreditsMenu;
		else if (CurrentMenu == SaphiroCredits)
			CurrentMenu = CreditsMenu;
		else if (CurrentMenu == DevMenu)
			CurrentMenu = MainMenu;
	}
}

void RenderSubMenu()
{
	RenderClosePage();
	Controller();

	if (Opened)
	{
		switch (CurrentMenu)
		{
#pragma region "Main Menu"
		case(MainMenu):
			MaxSubOptions = 7;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddOptionToggle(L"In-Game Utility");
			Menu::AddOptionToggle(L"Visual Utility");
			Menu::AddOptionToggle(L"Teleport Utility");
			Menu::AddOptionToggle(L"Client Modules");
			Menu::AddOptionToggle(L"Client Settings");
			Menu::AddOptionToggle(L"Client Credits");
			Menu::AddOptionToggle(L"Developers Utility");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddDescOption(L"");
			Menu::AddOption(L"");
			switch (getOption()) {
			case(0): CurrentMenu = InGameMenu; break;
			case(1): CurrentMenu = VisualMenu; break;
			case(2): CurrentMenu = TeleportMenu; break;
			case(3): CurrentMenu = ModulesMenu; break;
			case(4): CurrentMenu = SettingsMenu; break;
			case(5): CurrentMenu = CreditsMenu; break;
			case(6): CurrentMenu = DevMenu; break;
			}
			break;
#pragma endregion

#pragma region "InGameMenu Page"

		case(InGameMenu):
			MaxSubOptions = 5;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddSubOption(L"Host Cheats");
			Menu::AddSubOption(L"No-Host Cheats");
			Menu::AddSubOption(L"Funny Cheats");
			Menu::AddSubOption(L"Mini-Game Cheats");
			Menu::AddSubOption(L"Weather Cheats");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddOption(L"");
			Menu::AddDescOption(L"");
			Menu::AddOption(L"");
			switch (getOption()) {
			case(0): openSubmenu(eMenus::HostOptions); break;
			case(1): openSubmenu(eMenus::NoHostOptions); break;
			case(2): openSubmenu(eMenus::FunnyOptions); break;
			case(3): openSubmenu(eMenus::MiniGamesMenu); break;
			case(4): openSubmenu(eMenus::WeatherMenu); break;
			}
			break;

#pragma endregion

#pragma region "Host Pages"

		case(HostOptions):
			MaxSubOptions = 25;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddBoolOption(L"God Mode", !GodMode);
			Menu::AddBoolOption(L"Instant Damage", !InstantDamage);
			Menu::AddBoolOption(L"No Damage Hit", !NoDamageHit);
			Menu::AddBoolOption(L"Knockback", !Knockback);
			Menu::AddBoolOption(L"Anti Knockback", !NoKnockback);
			Menu::AddBoolOption(L"Potions Flying", !PotionFlying);
			Menu::AddBoolOption(L"Potions Go Down", !PotionGravity);
			Menu::AddBoolOption(L"Inf Pickup Items", !InfiniteItems);
			Menu::AddBoolOption(L"Max Pickup Items", !MaxPickupItems);
			Menu::AddBoolOption(L"Infinite Blocks", !InfiniteBlocks);
			Menu::AddBoolOption(L"Damage In Water", !BurnInWater);
			Menu::AddBoolOption(L"Infinite Oxygen", !InfiniteOxygen);
			Menu::AddBoolOption(L"Mobs Ignore Me", !MobsIgnoreMe);
			Menu::AddBoolOption(L"Disable Portals", !DisablePortals);
			Menu::AddBoolOption(L"Freeze Entity", !FreezeAllEntity);
			Menu::AddBoolOption(L"Items On Head", !ItemsOnHead);
			Menu::AddBoolOption(L"Entity God Mode", !EntityGodMode);
			Menu::AddBoolOption(L"Fast Bow", !FastBow);
			Menu::AddBoolOption(L"TNT Nuclear", !TNTNuclear);
			Menu::AddBoolOption(L"Disable Totem", !DisableTotem);
			Menu::AddBoolOption(L"Stop Boat", !StopBoat);
			Menu::AddBoolOption(L"No Web", !NoWeb);
			Menu::AddBoolOption(L"No Spawn Mobs", !NoSpawnMobs);
			Menu::AddBoolOption(L"No Entity TP", !NoEntityTP);
			Menu::AddSubOption(L"Next Page");
			switch (getOption()) {
			case(0) : GodMode = !GodMode; Offsets::GOD_MODE(GodMode); break;
			case(1) : InstantDamage = !InstantDamage; Offsets::INSTANT_DAMAGE(InstantDamage); break;
			case(2) : NoDamageHit = !NoDamageHit; Offsets::NO_DAMAGE_HIT(NoDamageHit); break;
			case(3) : Knockback = !Knockback; Offsets::KNOCKBACK(Knockback); break;
			case(4) : NoKnockback = !NoKnockback; Offsets::ANTI_KNOCKBACK(NoKnockback); break;
			case(5) : PotionFlying = !PotionFlying; Offsets::POTIONS_FLYING(PotionFlying); break;
			case(6) : PotionGravity = !PotionGravity; Offsets::POTIONS_NO_GRAVITY(PotionGravity); break;
			case(7) : InfiniteItems = !InfiniteItems; Offsets::INFINITE_PICKUP_ITEMS(InfiniteItems); break;
			case(8) : MaxPickupItems = !MaxPickupItems; Offsets::MAX_PICKUP_ITEMS(MaxPickupItems); break;
			case(9) : InfiniteBlocks = !InfiniteBlocks; Offsets::INFINITE_BLOCKS(InfiniteBlocks); break;
			case(10): BurnInWater = !BurnInWater; Offsets::BURN_IN_WATER(BurnInWater); break;
			case(11): InfiniteOxygen = !InfiniteOxygen; Offsets::INFINITE_OXYGEN(InfiniteOxygen); break;
			case(12): MobsIgnoreMe = !MobsIgnoreMe; Offsets::MOBS_IGNORE_ME(MobsIgnoreMe); break;
			case(13): DisablePortals = !DisablePortals; Offsets::DISABLE_PORTALS(DisablePortals); break;
			case(14): FreezeAllEntity = !FreezeAllEntity; Offsets::FREEZE_ALL_ENTITY(FreezeAllEntity); break;
			case(15): ItemsOnHead = !ItemsOnHead; Offsets::ITEMS_ON_HEAD(ItemsOnHead); break;
			case(16): EntityGodMode = !EntityGodMode; Offsets::ENTITY_GOD_MODE(EntityGodMode); break;
			case(17): FastBow = !FastBow; Offsets::FAST_BOW(FastBow); break;
			case(18): TNTNuclear = !TNTNuclear; Offsets::TNT_NUCLEAR(TNTNuclear); break;
			case(19): DisableTotem = !DisableTotem; Offsets::DISABLE_TOTEM(DisableTotem); break;
			case(20): StopBoat = !StopBoat; Offsets::STOP_BOAT(StopBoat); break;
			case(21): NoWeb = !NoWeb; Offsets::NO_WEB(NoWeb); break;
			case(22): NoSpawnMobs = !NoSpawnMobs; Offsets::DISABLE_SPAWN_MOBS(NoSpawnMobs); break;
			case(23): NoEntityTP = !NoEntityTP; Offsets::STOP_ENDERMAN_TP(NoEntityTP); break;
			case(24): openSubmenu(eMenus::HostOptions2); break;
			}
			break;

		case(HostOptions2):
			MaxSubOptions = 12;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddBoolOption(L"Lock GameMode", !LockGameMode);
			Menu::AddBoolOption(L"Lock Weather", !LockWeather);
			Menu::AddBoolOption(L"Drop Far Items", !DropFarItems);
			Menu::AddBoolOption(L"Plrs Fast Mine", !AllPlayersFastMine);
			Menu::AddBoolOption(L"Plrs Cant Mine", !AllPlayersCantMine);
			Menu::AddBoolOption(L"Plrs Cant Run", !AllPlayersCantRun);
			Menu::AddBoolOption(L"Plrs Speed", !AllPlayersSpeed);
			Menu::AddBoolOption(L"Plrs Super Run", !AllPlayersSuperRun);
			Menu::AddBoolOption(L"Plrs Cant Join", !PlayersCantJoin);
			Menu::AddBoolOption(L"Plrs Change Hand", !PlayersChangeHand);
			Menu::AddBoolOption(L"Plrs Suffocate", !AllPlayersSuffocate);
			Menu::AddBoolOption(L"Plrs In Fire", !AllPlayersInFire);
			switch (getOption()) {
			case(0) : LockGameMode = !LockGameMode; Offsets::LOCK_GAMEMODE(LockGameMode); break;
			case(1) : LockWeather = !LockWeather; Offsets::LOCK_WEATHER(LockWeather); break;
			case(2) : DropFarItems = !DropFarItems; Offsets::DROP_ITEMS_FAR(DropFarItems); break;
			case(3) : AllPlayersFastMine = !AllPlayersFastMine; Offsets::ALL_PLAYERS_FAST_MINE(AllPlayersFastMine); break;
			case(4) : AllPlayersCantMine = !AllPlayersCantMine; Offsets::ALL_PLAYERS_CANNOT_MINE(AllPlayersCantMine); break;
			case(5) : AllPlayersCantRun = !AllPlayersCantRun; Offsets::ALL_PLAYERS_CANT_RUN(AllPlayersCantRun); break;
			case(6) : AllPlayersSpeed = !AllPlayersSpeed; Offsets::ALL_PLAYERS_SUPER_SPEED(AllPlayersSpeed); break;
			case(7) : AllPlayersSuperRun = !AllPlayersSuperRun; Offsets::ALL_PLAYERS_SUPER_RUN(AllPlayersSuperRun); break;
			case(8) : PlayersCantJoin = !PlayersCantJoin; Offsets::ALL_PLAYERS_CANT_JOIN_THE_WORLD(PlayersCantJoin); break;
			case(9) : PlayersChangeHand = !PlayersChangeHand; Offsets::ALL_PLAYERS_CHANGE_HAND(PlayersChangeHand); break;
			case(10): AllPlayersSuffocate = !AllPlayersSuffocate; Offsets::ALL_PLAYERS_SUFFOCATE(AllPlayersSuffocate); break;
			case(11): AllPlayersInFire = !AllPlayersInFire; Offsets::ALL_PLAYERS_IN_FIRE(AllPlayersInFire); break;
			}
			break;

#pragma endregion

#pragma region "Non Host Pages"

		case(NoHostOptions):
			MaxSubOptions = 25;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddBoolOption(L"Super Speed", !SuperSpeed);
			Menu::AddBoolOption(L"Multi Jump", !MultiJump);
			Menu::AddBoolOption(L"Instant Hit", !InstantHit);
			Menu::AddBoolOption(L"Reach Attack", !ReachAttack);
			Menu::AddBoolOption(L"Kill Aura", !KillAura);
			Menu::AddBoolOption(L"Full Aura", !FullAura);
			Menu::AddBoolOption(L"Can Fly", !CanFly);
			Menu::AddBoolOption(L"No Colission", !NoColission);
			Menu::AddBoolOption(L"Swim Fly", !SwimFly);
			Menu::AddBoolOption(L"Fast Build", !FastBuild);
			Menu::AddBoolOption(L"Instant Mine", !InstantMine);
			Menu::AddBoolOption(L"Infinite Craft", !InfiniteCraft);
			Menu::AddBoolOption(L"Name Over Head", !NameOverHead);
			Menu::AddBoolOption(L"Name On Head V2", !NameOverHeadV2);
			Menu::AddBoolOption(L"Auto Sprint", !AutoSprint);
			Menu::AddBoolOption(L"Remove Hurt Cam", !HurtCam);
			Menu::AddBoolOption(L"Show Armor", !ShowArmor);
			Menu::AddBoolOption(L"Unfair Attack", !UnfairAttack);
			Menu::AddBoolOption(L"Hitbox BETA", !HitboxBETA);
			Menu::AddBoolOption(L"Big Velocity", !BigVelocity);
			Menu::AddBoolOption(L"No Velocity", !NoVelocity);
			Menu::AddBoolOption(L"ESP Players", !ESPPlayers);
			Menu::AddBoolOption(L"Gravity Moon", !GravityMoon);
			Menu::AddBoolOption(L"Water SlowDown", !WaterSlowDown);
			Menu::AddSubOption(L"Next Page");
			switch (getOption()) {
			case(0): SuperSpeed = !SuperSpeed; Offsets::SUPER_SPEED(SuperSpeed); break;
			case(1): MultiJump = !MultiJump; Offsets::MULTI_JUMP(MultiJump); break;
			case(2): InstantHit = !InstantHit; Offsets::INSTANT_HIT(InstantHit); break;
			case(3): ReachAttack = !ReachAttack; Offsets::REACH_ATTACK(ReachAttack); break;
			case(4): KillAura = !KillAura; Offsets::KILL_AURA(KillAura); break;
			case(5): FullAura = !FullAura; Offsets::FULL_AURA(FullAura); break;
			case(6): CanFly = !CanFly; Offsets::CAN_FLY(CanFly); break;
			case(7): NoColission = !NoColission; Offsets::NO_COLISSION(NoColission); break;
			case(8): SwimFly = !SwimFly; Offsets::SWIM_FLY(SwimFly); break;
			case(9): FastBuild = !FastBuild; Offsets::FAST_BUILD(FastBuild); break;
			case(10): InstantMine = !InstantMine; Offsets::INSTANT_MINE(InstantMine); break;
			case(11): InfiniteCraft = !InfiniteCraft; Offsets::INFINITE_CRAFT(InfiniteCraft); break;
			case(12): NameOverHead = !NameOverHead; Offsets::NAME_OVER_HEAD(NameOverHead); break;
			case(13): NameOverHeadV2 = !NameOverHeadV2; Offsets::NAME_OVER_HEAD_V2(NameOverHeadV2); break;
			case(14): AutoSprint = !AutoSprint; Offsets::AUTO_SPRINT(AutoSprint); break;
			case(15): HurtCam = !HurtCam; Offsets::REMOVE_HURT_CAM(HurtCam); break;
			case(16): ShowArmor = !ShowArmor; Offsets::SHOW_ARMOR(ShowArmor); break;
			case(17): UnfairAttack = !UnfairAttack; Offsets::UNFAIR_ATTACK(UnfairAttack); break;
			case(18): HitboxBETA = !HitboxBETA; Offsets::HITBOX_BETA(HitboxBETA); break;
			case(19): BigVelocity = !BigVelocity; Offsets::BIG_VELOCITY(BigVelocity); break;
			case(20): NoVelocity = !NoVelocity; Offsets::NO_VELOCITY(NoVelocity); break;
			case(21): ESPPlayers = !ESPPlayers; Offsets::ESP_PLAYERS(ESPPlayers); break;
			case(22): GravityMoon = !GravityMoon; Offsets::GRAVITY_MOON(GravityMoon); break;
			case(23): WaterSlowDown = !WaterSlowDown; Offsets::WATER_SLOWDOWN(WaterSlowDown); break;
			case(24): openSubmenu(eMenus::NoHostOptions2); break;
			}
			break;

		case(NoHostOptions2):
			MaxSubOptions = 13;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddBoolOption(L"Items IDs", !ItemsIds);
			Menu::AddBoolOption(L"Jump For Build", !JumpForBuild);
			Menu::AddBoolOption(L"Jump In Lava", !JumpInLava);
			Menu::AddBoolOption(L"Pos Place Block", !PosPlaceBlock);
			Menu::AddBoolOption(L"ESP Chests", !ESPChests);
			Menu::AddBoolOption(L"Sensibility Fast", !SensibilityFast);
			Menu::AddBoolOption(L"Auto Walk", !WalkAlone);
			Menu::AddBoolOption(L"Auto Jump", !AutoJump);
			Menu::AddBoolOption(L"Auto View", !AutoChangeView);
			Menu::AddBoolOption(L"Auto Crouch", !AutoCrouch);
			Menu::AddBoolOption(L"Auto Mine", !AutoMine);
			Menu::AddBoolOption(L"Auto Hit", !AutoHit);
			Menu::AddBoolOption(L"Auto Build", !AutoBuild);
			Menu::AddBoolOption(L"Press X For Hit", !PressXForHit);
			switch (getOption()) {
			case(0): ItemsIds = !ItemsIds; Offsets::ITEMS_IDS(ItemsIds); break;
			case(1): JumpForBuild = !JumpForBuild; Offsets::JUMP_FOR_BUILD(JumpForBuild); break;
			case(2): JumpInLava = !JumpInLava; Offsets::JUMP_IN_LAVA(JumpInLava); break;
			case(3): PosPlaceBlock = !PosPlaceBlock; Offsets::POSITION_PLACE_BLOCK(PosPlaceBlock); break;
			case(4): ESPChests = !ESPChests; Offsets::ESP_CHESTS(ESPChests); break;
			case(5): SensibilityFast = !SensibilityFast; Offsets::SENSIBILITY_FAST(SensibilityFast); break;
			case(6): WalkAlone = !WalkAlone; Offsets::WALK_ALONE(WalkAlone); break;
			case(7): AutoJump = !AutoJump; Offsets::AUTO_JUMP(AutoJump); break;
			case(8): AutoChangeView = !AutoChangeView; Offsets::AUTO_CHANGE_VIEW(AutoChangeView); break;
			case(9): AutoCrouch = !AutoCrouch; Offsets::AUTO_CROUCH(AutoCrouch); break;
			case(10): AutoMine = !AutoMine; Offsets::AUTO_MINE(AutoMine); break;
			case(11): AutoHit = !AutoHit; Offsets::AUTO_HIT(AutoHit); break;
			case(12): AutoBuild = !AutoBuild; Offsets::AUTO_BUILD(AutoBuild); break;
			case(13): PressXForHit = !PressXForHit; Offsets::PRESS_X_FOR_HIT(PressXForHit); break;
			}
			break;

#pragma endregion

#pragma region "Funny Pages"

		case(FunnyOptions):
			MaxSubOptions = 21;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddBoolOption(L"Scaffold", !Scaffold);
			Menu::AddBoolOption(L"Day & Night", !DayNight);
			Menu::AddBoolOption(L"Crouch Mov", !AlwaysCrouch);
			Menu::AddBoolOption(L"Levitation", !Levitation);
			Menu::AddBoolOption(L"Spider Man", !AutoLadder);
			Menu::AddBoolOption(L"Air To Water", !AirToWater);
			Menu::AddBoolOption(L"TNT Flying", !TNTFlying);
			Menu::AddBoolOption(L"Creeper Nuclear", !CreeperNuclear);
			Menu::AddBoolOption(L"Creeper Fire", !CreeperFire);
			Menu::AddBoolOption(L"Get Special Items", !SpecialItems);
			Menu::AddBoolOption(L"Vibrate Walk", !VibrateWalk);
			Menu::AddBoolOption(L"Step Fast", !FootStepSlow);
			Menu::AddBoolOption(L"Elytra Entity", !Elytra);
			Menu::AddBoolOption(L"Move Head", !MoveHeadNoBody);
			Menu::AddBoolOption(L"Disable Players", !DisablePlayers);
			Menu::AddBoolOption(L"Small Text", !SmallText);
			Menu::AddBoolOption(L"Arms Broken", !ArmsBroken);
			Menu::AddBoolOption(L"Laby Mode", !LabyMode);
			Menu::AddBoolOption(L"Dragon Eggs Spawner", !DragonEggSpawner);
			Menu::AddBoolOption(L"Golem Eggs Spawner", !GolemEggSpawner);
			Menu::AddBoolOption(L"Wither Eggs Spawner", !WitherEggSpawner);
			DrawTextWithRect(L"Before using Get Special Items read instruction!", 160, 40, color(MC_Color::White));
			DrawTextWithRect(L"You need the original MediaPS3.arc", 160, 50, color(MC_Color::White));
			DrawTextWithRect(L"Set your PS3 language to English (United State)", 160, 60, color(MC_Color::White));
			DrawTextWithRect(L"Go after in Miscellaneous category, and enjoy :D", 160, 70, color(MC_Color::White));
			DrawTextWithRect(L"PS: Custom Eggs Spawner is same", 160, 80, color(MC_Color::White));
			switch (getOption()) {
			case(0): Scaffold = !Scaffold; Offsets::SCAFFOLD_BETA(Scaffold); break;
			case(1): DayNight = !DayNight; Offsets::DAY_NIGHT(DayNight); break;
			case(2): AlwaysCrouch = !AlwaysCrouch; Offsets::ALWAYS_CROUCH(AlwaysCrouch); break;
			case(3): Levitation = !Levitation; Offsets::LEVITATION(Levitation); break;
			case(4): AutoLadder = !AutoLadder; Offsets::AUTO_LADDER(AutoLadder); break;
			case(5): AirToWater = !AirToWater; Offsets::AIR_TO_WATER(AirToWater); break;
			case(6): TNTFlying = !TNTFlying; Offsets::TNT_FLYING(TNTFlying); break;
			case(7): CreeperNuclear = !CreeperNuclear; Offsets::CREEPER_NUCLEAR(CreeperNuclear); break;
			case(8): CreeperFire = !CreeperFire; Offsets::CREEPER_FIRE(CreeperFire); break;
			case(9): SpecialItems = !SpecialItems; Offsets::SPECIAL_ITEMS(SpecialItems); break;
			case(10): VibrateWalk = !VibrateWalk; Offsets::VIBRATE_WALK(VibrateWalk); break;
			case(11): FootStepSlow = !FootStepSlow; Offsets::FOOT_STEP_SLOW(FootStepSlow); break;
			case(12): Elytra = !Elytra; Offsets::ENTITY_ELYTRA(Elytra); break;
			case(13): MoveHeadNoBody = !MoveHeadNoBody; Offsets::MOVE_HEAD_NO_BODY(MoveHeadNoBody); break;
			case(14): DisablePlayers = !DisablePlayers; Offsets::DISABLE_PLAYERS(DisablePlayers); break;
			case(15): SmallText = !SmallText; Offsets::SMALL_TEXT(SmallText); break;
			case(16): ArmsBroken = !ArmsBroken; Offsets::ARMS_BROKEN(ArmsBroken); break;
			case(17): LabyMode = !LabyMode; Offsets::LABY_MODE(LabyMode); break;
			case(18): DragonEggSpawner = !DragonEggSpawner; Offsets::DRAGON_EGGS_SPAWNER(DragonEggSpawner); break;
			case(19): GolemEggSpawner = !GolemEggSpawner; Offsets::GOLEM_EGGS_SPAWNER(GolemEggSpawner); break;
			case(20): WitherEggSpawner = !WitherEggSpawner; Offsets::WITHER_EGGS_SPAWNER(WitherEggSpawner); break;
			}
			break;

#pragma endregion

#pragma region "Mini-Games Pages"

		case(MiniGamesMenu):
			MaxSubOptions = 12;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddBoolOption(L"Can Craft", !CanCraft);
			Menu::AddBoolOption(L"Can Place Block", !CanPlaceBlocks);
			Menu::AddBoolOption(L"See Spectator", !CanSeeSpectator);
			Menu::AddBoolOption(L"Plrs Starved", !PlayersAreStarved);
			Menu::AddBoolOption(L"Allow Portals", !AllowPortals);
			Menu::AddBoolOption(L"Tnt Can Destroy", !TntCanDestroyBlocks);
			Menu::AddBoolOption(L"Max In Small Map", !MaxPlayersSmallMap);
			Menu::AddBoolOption(L"Crea Inv Lobby", !CreativeInventory);
			Menu::AddBoolOption(L"Destroy Block", !CanDestroyBlocks);
			Menu::AddBoolOption(L"Game Survival", !GameModeToSurvival);
			Menu::AddBoolOption(L"Inv Crea Tumble", !InventoryCreaTumbleActive);
			Menu::AddSubOption(L"Teleport Location");
			switch (getOption()) {
			case(0) : CanCraft = !CanCraft; Offsets::CAN_CRAFT(CanCraft); break;
			case(1) : CanPlaceBlocks = !CanPlaceBlocks; Offsets::CAN_PLACE_BLOCKS(CanPlaceBlocks); break;
			case(2) : CanSeeSpectator = !CanSeeSpectator; Offsets::CAN_SEE_SPECTATOR(CanSeeSpectator); break;
			case(3) : PlayersAreStarved = !PlayersAreStarved; Offsets::PLAYERS_ARE_STARVED(PlayersAreStarved); break;
			case(4) : AllowPortals = !AllowPortals; Offsets::ALLOW_PORTALS(AllowPortals); break;
			case(5) : TntCanDestroyBlocks = !TntCanDestroyBlocks; Offsets::TNT_CAN_DESTROY(TntCanDestroyBlocks); break;
			case(6) : MaxPlayersSmallMap = !MaxPlayersSmallMap; Offsets::MAX_PLAYERS_IN_SMALL_MAPS(MaxPlayersSmallMap); break;
			case(7) : CreativeInventory = !CreativeInventory; Offsets::CREATIVE_INVENTORY(CreativeInventory); break;
			case(8) : CanDestroyBlocks = !CanDestroyBlocks; Offsets::CAN_DESTROY_BLOCKS(CanDestroyBlocks); break;
			case(9) : GameModeToSurvival = !GameModeToSurvival; Offsets::GAMEMODE_TO_SURVIVAL(GameModeToSurvival); break;
			case(10): InventoryCreaTumbleActive = !InventoryCreaTumbleActive; Offsets::InventoryCreativeTumble(InventoryCreaTumbleActive); break;
			case(11): openSubmenu(eMenus::MiniGamesMenu2); break;
			}
			break;

		case(MiniGamesMenu2):
			MaxSubOptions = 4;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddBoolOption(L"TP To Lobby", !TeleportLobby);
			Menu::AddBoolOption(L"TP To Cavern", !TeleportCavern);
			Menu::AddOption(L"TP To Cove");
			Menu::AddOption(L"TP To Crucible");
			switch (getOption()) {
			case(0): TeleportLobby = !TeleportLobby; Offsets::TELEPORT_TO_LOBBY; break;
			case(1): TeleportCavern = !TeleportCavern; Offsets::TELEPORT_TO_CAVERN; break;
			case(2): TeleportCove = !TeleportCove; Offsets::TELEPORT_TO_COVE; break;
			case(3): TeleportCrucible = !TeleportCrucible; Offsets::TELEPORT_TO_CRUCIBLE; break;
			}
			break;

#pragma endregion

#pragma region "Weather Pages"

		case(WeatherMenu):
			MaxSubOptions = 7;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddBoolOption(L"Dark Storm", !DarkStorm);
			Menu::AddBoolOption(L"Rainbow Storm", !RainbowStorm);
			Menu::AddBoolOption(L"Rain To Snow", !RainToSnow);
			Menu::AddBoolOption(L"Rain With Snow", !RainbowWithSnow);
			Menu::AddBoolOption(L"Flash Sky", !FlashSky);
			Menu::AddBoolOption(L"LightningBold V1", !LightningBoldV1);
			Menu::AddBoolOption(L"LightningBold V2", !LightningBoldV2);
			switch (getOption()) {
			case(0): DarkStorm = !DarkStorm; Offsets::WEATHER_DARK_STORM(DarkStorm); break;
			case(1): RainbowStorm = !RainbowStorm; Offsets::WEATHER_RAINBOW_STORM(RainbowStorm); break;
			case(2): RainToSnow = !RainToSnow; Offsets::WEATHER_RAIN_TO_SNOW(RainToSnow); break;
			case(3): RainbowWithSnow = !RainbowWithSnow; Offsets::WEATHER_RAINBOW_WITH_STORM(RainbowWithSnow); break;
			case(4): FlashSky = !FlashSky; Offsets::WEATHER_FLASH_SKY(FlashSky); break;
			case(5): LightningBoldV1 = !LightningBoldV1; Offsets::WEATHER_LIGHTNINGBOLD_V1(LightningBoldV1); break;
			case(6): LightningBoldV2 = !LightningBoldV2; Offsets::WEATHER_LIGHTNINGBOLD_V2(LightningBoldV2); break;
			}
			break;
				
#pragma endregion

#pragma region "Visual Pages"

		case(VisualMenu):
			MaxSubOptions = 25;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddSubOption(L"Show Options");
			Menu::AddSubOption(L"Selection Options");
			Menu::AddBoolOption(L"Custom Sky BETA", !CustomSky);
			Menu::AddBoolOption(L"Stars In Sky", !StarsSky);
			Menu::AddBoolOption(L"Bedrock Hotbar", !BedrockHotbar);
			Menu::AddBoolOption(L"Optimize Chunks", !OptimizedChunks);
			Menu::AddBoolOption(L"FOV No Hand", !FOVNoHand);
			Menu::AddBoolOption(L"Night Vision", !NightVision);
			Menu::AddBoolOption(L"Better Time", !BetterTime);
			Menu::AddBoolOption(L"Wallhack", !WallHack);
			Menu::AddBoolOption(L"Xray Vision", !XrayVision);
			Menu::AddBoolOption(L"Horror Vision", !HorrorView);
			Menu::AddBoolOption(L"Ghost Texture", !GhostPlastic);
			Menu::AddBoolOption(L"Plastic Texture", !PlasticTexture);
			Menu::AddBoolOption(L"Black Fog", !BlackFog);
			Menu::AddBoolOption(L"Shaders", !MoreLight);
			Menu::AddBoolOption(L"Camera Left", !CameraLeft);
			Menu::AddBoolOption(L"Camera Right", !CameraRight);
			Menu::AddBoolOption(L"Entity To Baby", !EntityBaby);
			Menu::AddBoolOption(L"Entity Light", !EntityBodyLight);
			Menu::AddBoolOption(L"Blue Sky", !BestSky);
			Menu::AddBoolOption(L"Pink Sky", !PinkSky);
			Menu::AddBoolOption(L"Particles Fly", !ParticlesFly);
			Menu::AddBoolOption(L"Smoke Lobby", !SmokeLobby);
			Menu::AddSubOption(L"Next Page");
			DrawTextWithRect(L"Before using Custom Sky BETA read instruction!", 160, 40, color(MC_Color::White));
			DrawTextWithRect(L"You need put/replace a sun.png", 160, 50, color(MC_Color::White));
			DrawTextWithRect(L"Don't put a high size or you will crash", 160, 60, color(MC_Color::White));
			DrawTextWithRect(L"Enjoy your sky :D", 160, 70, color(MC_Color::White));
			switch (getOption()) {
			case(0) : openSubmenu(eMenus::ShowOptions); break;
			case(1) : openSubmenu(eMenus::SelectionOptions); break;
			case(2) : CustomSky = !CustomSky; Offsets::CUSTOM_SKY(CustomSky); break;
			case(3) : StarsSky = !StarsSky; Offsets::STARS_IN_SKY(StarsSky); break;
			case(4) : BedrockHotbar = !BedrockHotbar; Options::Bedrock_Hotbar(BedrockHotbar); break;
			case(5) : OptimizedChunks = !OptimizedChunks; Offsets::OPTIMIZE_CHUNKS_LOAD(OptimizedChunks); break;
			case(6) : FOVNoHand = !FOVNoHand; Offsets::FOV_WITHOUT_HAND(FOVNoHand); break;
			case(7) : NightVision = !NightVision; Offsets::NIGHT_VISON(NightVision); break;
			case(8) : BetterTime = !BetterTime; Offsets::BETTER_TIME(BetterTime); break;
			case(9) : WallHack = !WallHack; Offsets::WALLHACK(WallHack); break;
			case(10): XrayVision = !XrayVision; Offsets::XRAY_VISON(XrayVision); break;
			case(11): HorrorView = !HorrorView; Offsets::HORROR_VISION(HorrorView); break;
			case(12): GhostPlastic = !GhostPlastic; Offsets::GHOST_TEXTURE(GhostPlastic); break;
			case(13): PlasticTexture = !PlasticTexture; Offsets::PLASTIC_TEXTURE(PlasticTexture); break;
			case(14): BlackFog = !BlackFog; Offsets::BLACK_FOG(BlackFog); break;
			case(15): MoreLight = !MoreLight; Offsets::MORE_LIGHT(MoreLight); break;
			case(16): CameraLeft = !CameraLeft; Offsets::CAMERA_LEFT(CameraLeft); break;
			case(17): CameraRight = !CameraRight; Offsets::CAMERA_RIGHT(CameraRight); break;
			case(18): EntityBaby = !EntityBaby; Offsets::ENTITY_TO_BABY(EntityBaby); break;
			case(19): EntityBodyLight = !EntityBodyLight; Offsets::ENTITY_BODY_LIGHT(EntityBodyLight); break;
			case(20): BestSky = !BestSky; Offsets::BEST_SKY(BestSky); break;
			case(21): PinkSky = !PinkSky; Offsets::SKY_PINK(PinkSky); break;
			case(22): ParticlesFly = !ParticlesFly; Offsets::PARTICLES_FLY(ParticlesFly); break;
			case(23): SmokeLobby = !SmokeLobby; Offsets::SMOKE_LOBBY(SmokeLobby); break;
			case(24): openSubmenu(eMenus::VisualMenu2); break;
			}
			break;

		case(ShowOptions):
			MaxSubOptions = 9;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddBoolOption(L"Show PSN", !TogglePSN);
			Menu::AddBoolOption(L"Show Gametime", !ToggleGametime);
			Menu::AddBoolOption(L"Show Position", !TogglePosition);
			Menu::AddBoolOption(L"Show Chunks", !ToggleChunks);
			Menu::AddBoolOption(L"Show Resolution", !ToggleResolution);
			Menu::AddBoolOption(L"Show Ping", !TogglePing);
			Menu::AddBoolOption(L"Show Debug Player", !ToggleDebugPlayer);
			Menu::AddBoolOption(L"Show Keystrokes", !ToggleKeystrokes);
			Menu::AddSubOption(L"Keystrokes Settings");
			switch (getOption()) {
			case(0): TogglePSN = !TogglePSN; break;
			case(1): ToggleGametime = !ToggleGametime; break;
			case(2): TogglePosition = !TogglePosition; break;
			case(3): ToggleChunks = !ToggleChunks; break;
			case(4): ToggleResolution = !ToggleResolution; break;
			case(5): TogglePing = !TogglePing; break;
			case(6): ToggleDebugPlayer = !ToggleDebugPlayer; break;
			case(7): ToggleKeystrokes = !ToggleKeystrokes; break;
			case(8): openSubmenu(eMenus::KeySettings); break;
			}
			break;

		case(KeySettings):
			MaxSubOptions = 4;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddOptionToggle(L"KeystrokesX +");
			Menu::AddOptionToggle(L"KeystrokesX -");
			Menu::AddOptionToggle(L"KeystrokesY +");
			Menu::AddOptionToggle(L"KeystrokesY -");
			switch (getOption()) {
			case(0): keystrokesBase_x += 1; break;
			case(1): keystrokesBase_x -= 1; break;
			case(2): keystrokesBase_y -= 1; break;
			case(3): keystrokesBase_y += 1; break;
			}
			break;

		case(SelectionOptions):
			MaxSubOptions = 6;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddBoolOption(L"White Line Selection", !WhiteLine);
			Menu::AddBoolOption(L"Black Line Selection", !BlackLine);
			Menu::AddBoolOption(L"Blue Line Selection", !BlueLine);
			Menu::AddBoolOption(L"Green Line Selection", !GreenLine);
			Menu::AddIntOptionSlow(L"Big Selection", 0, 0, 3, BigLine);
			Menu::AddIntOptionSlow(L"Box Selection", 0, 0, 4, BoxLine);
			switch (getOption()) {
			case(0): WhiteLine = !WhiteLine; Offsets::WHITE_LINE(WhiteLine); break;
			case(1): BlackLine = !BlackLine; Offsets::BLACK_LINE(BlackLine); break;
			case(2): BlueLine = !BlueLine; Offsets::BLUE_LINE(BlueLine); break;
			case(3): GreenLine = !GreenLine; Offsets::GREEN_LINE(GreenLine); break;
			case(4): Offsets::BIG_LINE(BigLine); break;
			case(5): Offsets::BOX_LINE(BoxLine); break;
			}
			break;
		
		
		case(VisualMenu2):
			MaxSubOptions = 25;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddIntOptionSlow(L"Change FOV", 0, 0, 6, ValueFOV);
			Menu::AddBoolOption(L"Aim 3Th Person", !AimOn3thPerson);
			Menu::AddBoolOption(L"Skins Debug", !SkinsDebug);
			Menu::AddBoolOption(L"Camera Down", !CameraDown);
			Menu::AddBoolOption(L"Camera Down R3", !CameraDownR3);
			Menu::AddBoolOption(L"Skins Red", !SkinsPlayersRed);
			Menu::AddBoolOption(L"Flat Blocks", !FlatBlocks);
			Menu::AddBoolOption(L"Free Cam", !FreeCam);
			Menu::AddBoolOption(L"Remove Hand", !RemoveHand);
			Menu::AddBoolOption(L"Hit Damage Red", !HitDamageRed);
			Menu::AddBoolOption(L"Disable Fog", !DisableFog);
			Menu::AddBoolOption(L"No Detailed Skins", !NoDetailedSkins);
			Menu::AddBoolOption(L"Render Entity", !RenderEntity);
			Menu::AddBoolOption(L"360 Rotate Head", !RotationCam);
			Menu::AddBoolOption(L"Rotation Body", !RotationBody);
			Menu::AddBoolOption(L"Texture To Black", !TextureToBlack);
			Menu::AddBoolOption(L"Nether Vision", !NetherVision);
			Menu::AddBoolOption(L"Hit Spam", !ParticlesHitSpam);
			Menu::AddBoolOption(L"Roblox Animation", !RobloxAnimation);
			Menu::AddBoolOption(L"Stop Animation", !StopAnimation);
			Menu::AddBoolOption(L"Giant Gameplay", !GiantGameplay);
			Menu::AddBoolOption(L"Shadow Skins", !ShadowSkins);
			Menu::AddBoolOption(L"Real Jump Anim", !RealJumpAnim);
			Menu::AddBoolOption(L"Hud Mini Game", !RemoveInventoryHud);
			Menu::AddBoolOption(L"Animation Run", !AnimationRun);
			switch (getOption()) {
			case(0) : Offsets::CHANGE_FOV(ValueFOV); break;
			case(1) : AimOn3thPerson = !AimOn3thPerson; Offsets::AIM_ON_3TH_PERSON(AimOn3thPerson); break;
			case(2) : SkinsDebug = !SkinsDebug; Offsets::SKINS_DEBUG(SkinsDebug); break;
			case(3) : CameraDown = !CameraDown; Offsets::CAMERA_DOWN(CameraDown); break;
			case(4) : CameraDownR3 = !CameraDownR3; Offsets::CAMERA_DOWN_R3(CameraDownR3); break;
			case(5) : SkinsPlayersRed = !SkinsPlayersRed; Offsets::SKINS_RED_PLAYERS(SkinsPlayersRed); break;
			case(6) : FlatBlocks = !FlatBlocks; Offsets::FLAT_BLOCKS(FlatBlocks); break;
			case(7) : FreeCam = !FreeCam; Offsets::FREE_CAM(FreeCam); break;
			case(8) : RemoveHand = !RemoveHand; Offsets::REMOVE_HAND(RemoveHand); break;
			case(9) : HitDamageRed = !HitDamageRed; Offsets::HIT_DAMAGE_RED(HitDamageRed); break;
			case(10): DisableFog = !DisableFog; Offsets::DISABLE_FOG(DisableFog); break;
			case(11): NoDetailedSkins = !NoDetailedSkins; Offsets::REMOVE_DETAILED_SKINS(NoDetailedSkins); break;
			case(12): RenderEntity = !RenderEntity; Offsets::RENDER_ENTITY(RenderEntity); break;
			case(13): RotationCam = !RotationCam; Offsets::ROTATION_HEAD(RotationCam); break;
			case(14): RotationBody = !RotationBody; Offsets::ROTATION_BODY(RotationBody); break;
			case(15): TextureToBlack = !TextureToBlack; Offsets::TEXTURE_TO_BLACK(TextureToBlack); break;
			case(16): NetherVision = !NetherVision; Offsets::NETHER_VISION(NetherVision); break;
			case(17): ParticlesHitSpam = !ParticlesHitSpam; Offsets::PARTICLES_HIT_SPAM(ParticlesHitSpam); break;
			case(18): RobloxAnimation = !RobloxAnimation; Offsets::ROBLOX_ANIMATION(RobloxAnimation); break;
			case(19): StopAnimation = !StopAnimation; Offsets::STOP_ANIMATION(StopAnimation); break;
			case(20): GiantGameplay = !GiantGameplay; Offsets::GIANT_GAMEPLAY(GiantGameplay); break;
			case(21): ShadowSkins = !ShadowSkins; Offsets::SHADOW_SKINS(ShadowSkins); break;
			case(22): RealJumpAnim = !RealJumpAnim; Offsets::REAL_JUMP_ANIM(RealJumpAnim); break;
			case(23): RemoveInventoryHud = !RemoveInventoryHud; Offsets::HUD_MINI_GAME(RemoveInventoryHud); break;
			case(24): AnimationRun = !AnimationRun; Offsets::ANIMATION_RUN(AnimationRun); break;
			}
			break;

#pragma endregion

#pragma region "Modules Pages"

		case(ModulesMenu):
			MaxSubOptions = 6;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddBoolOption(L"Zoom Mode", !Zoom);
			Menu::AddBoolOption(L"TP Aura", !TPAura);
			Menu::AddBoolOption(L"Phase V1", !PhaseV1);
			Menu::AddBoolOption(L"Auto Toss", !AutoTossItems);
			Menu::AddBoolOption(L"Refresh Game", !HudLoading);
			Menu::AddOption(L"No Clip");
			switch (getOption()) {
			case(0): Zoom = !Zoom; break; //logs::debugMessage(L"          Press R3 for Zoom.", MC_Color::Lime); break;
			case(1): TPAura = !TPAura; break; //Modules::TP_Aura; logs::debugMessage(L"          TP to target and attack him.", MC_Color::DarkPurple); break;
			case(2): PhaseV1 = !PhaseV1; Offsets::PHASE_MODE(PhaseV1); break;
			case(3): AutoTossItems = !AutoTossItems; Modules::AutoToss; break; //logs::debugMessage(L"          Press R1 for Auto Toss items on slot.", MC_Color::Orange); break;
			case(4): HudLoading = !HudLoading; Offsets::HUD_LOADING(HudLoading); break;
			case(5): mc->theMinecraft->cMultiplayerLocalPlayer->noClip = true; logs::debugMessage(L"          You need die for disable this option!", MC_Color::White); break;
			}
			break;

#pragma endregion

#pragma region "Teleport Pages"

		case(TeleportMenu):
			MaxSubOptions = 5;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::AddIntOption(L"CoordX", 0, -430, 450, CoordX);
			Menu::AddIntOption(L"CoordY", 1, -999, 510, CoordY);
			Menu::AddIntOption(L"CoordZ", 2, -430, 450, CoordZ);
			Menu::AddOption(L"Save Current Coord");
			Menu::AddOption(L"Set Teleport");
			GetTeleportXYZ();
			switch (getOption()) {
			case(3): Options::getTeleport(); logs::debugMessage(L"          Coordinates has been saved.", MC_Color::Blue); break;
			case(4): Options::setTeleport(CoordX, CoordY, CoordZ); logs::debugMessage(L"          You has been teleported.", MC_Color::Green); break;
			}
			break;

#pragma endregion

#pragma region "Settings Pages"

		case(SettingsMenu):
			MaxSubOptions = 5;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddOptionToggle(L"MenuX +");
			Menu::AddOptionToggle(L"MenuX -");
			Menu::AddOptionToggle(L"MenuY +");
			Menu::AddOptionToggle(L"MenuY -");
			Menu::AddBoolOption(L"Show Title SPRX", !ToggleTitleSPRX);
			switch (getOption()) {
			case(0): MenuX += 1; break;
			case(1): MenuX -= 1; break;
			case(2): MenuY += 1; break;
			case(3): MenuY -= 1; break;
			case(4): ToggleTitleSPRX = !ToggleTitleSPRX; break;
			}
			break;

#pragma endregion

#pragma region "Credits Pages"

		case(CreditsMenu):
			MaxSubOptions = 4;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddSubOption(L"AzeY      (Client Creator)");
			Menu::AddSubOption(L"Misakiii           (SPRX Base)");
			Menu::AddSubOption(L"EternalModz     (Helper)");
			Menu::AddSubOption(L"SaphirO               (Helper)");
			switch (getOption()) {
			case(0): openSubmenu(eMenus::AzeYCredits); break;
			case(1): openSubmenu(eMenus::MisakiCredits); break;
			case(2): openSubmenu(eMenus::EternalCredits); break;
			case(3): openSubmenu(eMenus::SaphiroCredits); break;
			}
			break;


		case(AzeYCredits):
			MaxSubOptions = 4;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddOption(L"YouTube:   AzeY");
			Menu::AddOption(L"Discord:   azeylebg");
			Menu::AddOption(L"GitHub:   AzeYDev");
			Menu::AddOption(L"PSN:   AzeY-_-YT_-");
			break;

		case(MisakiCredits):
			MaxSubOptions = 3;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddOption(L"YouTube:   Misakiii");
			Menu::AddOption(L"Discord:   misaki57");
			Menu::AddOption(L"GitHub:   Miisaakii");
			break;

		case(EternalCredits):
			MaxSubOptions = 3;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddOption(L"YouTube:  EternalModz");
			Menu::AddOption(L"Discord:  eternalmodz");
			Menu::AddOption(L"GitHub:  EternalModz");
			break;

		case(SaphiroCredits):
			MaxSubOptions = 3;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddOption(L"YouTube:  SaphirO46");
			Menu::AddOption(L"Discord:  saphiro__");
			Menu::AddOption(L"GitHub:  SaphirO46");
			break;


#pragma endregion

#pragma region "DEV Pages"

		case(DevMenu):
			MaxSubOptions = 10;
			Menu::AddTitle(L"Kagura Client V2");
			Menu::Description(L"");
			Menu::AddBoolOption(L"Bedrock UI", !BedrockUI);
			Menu::AddBoolOption(L"Barrier Block Inv", !Barrier);
			Menu::AddBoolOption(L"Get Players IDs on Head", !IDsOnHead);
			Menu::AddBoolOption(L"Enable Special Block test", !EnableSpecialBlock);
			Menu::AddBoolOption(L"Barrier test", !BarrierTest);
			Menu::AddBoolOption(L"Barrier test to Ice", !BarrierTestToIce);
			Menu::AddBoolOption(L"Anti Kick Premium", !AntiKickPremium);
			Menu::AddBoolOption(L"Lobby Messages Spam", !LobbyMessagesSpam);
			Menu::AddBoolOption(L"Get Spectator Mode", !GetSpectatorMode);
			Menu::AddBoolOption(L"Kaura V.01 BETA", !ToggleKAura);
			switch (getOption()) {
			case(0): BedrockUI = !BedrockUI; Options::BEDROCK_UI(BedrockUI); break;
			case(1): Barrier = !Barrier; Offsets::BARRIER(Barrier); break;
			case(2): IDsOnHead = !IDsOnHead; Offsets::GET_IDS_PLAYERS_ON_HEAD(IDsOnHead); break;
			case(3): EnableSpecialBlock = !EnableSpecialBlock; Offsets::ENABLE_SPECIAL_BLOCK(EnableSpecialBlock); break;
			case(4): BarrierTest = !BarrierTest; Offsets::BARRIER_TEST(BarrierTest); break;
			case(5): BarrierTestToIce = !BarrierTestToIce; Offsets::BARRIER_TEST_TO_ICE(BarrierTestToIce); break;
			case(6): AntiKickPremium = !AntiKickPremium; Offsets::ANTI_KICK_PREMIUM(AntiKickPremium); break;
			case(7): LobbyMessagesSpam = !LobbyMessagesSpam; Offsets::LOBBY_MESSAGES_SPAM(LobbyMessagesSpam); break;
			case(8): GetSpectatorMode = !GetSpectatorMode; Offsets::GET_SPECTATOR_GAMEMODE(GetSpectatorMode); break;
			case(9): ToggleKAura = !ToggleKAura; break;
			}
			break;
		}
	}
}
#pragma endregion