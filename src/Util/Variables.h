#pragma once

enum eMenus
{
	MainMenu, InGameMenu, HostOptions, HostOptions2, NoHostOptions, NoHostOptions2, FunnyOptions, VisualMenu, TeleportMenu, ModulesMenu, SettingsMenu, CreditsMenu, AzeYCredits, MisakiCredits, EternalCredits 
	,SaphiroCredits ,VisualMenu2, MiniGamesMenu, MiniGamesMenu2, DevMenu, ShowOptions, KeySettings, WeatherMenu, SelectionOptions
};

namespace MC_Color
{
	int DarkRed[3] = { 170, 0, 0 };
	int Red[3] = { 255, 85, 85 };
	int Gold[3] = { 255, 170, 0 };
	int Yellow[3] = { 255, 255, 85 };
	int Orange[3] = { 255, 143, 16 };
	int Cyan[3] = { 16, 233, 255 };
	int DarkGreen[3] = { 0, 170, 0 };
	int Green[3] = { 85, 255, 85 };
	int Lime[3] = { 0, 255, 15 };
	int Aqua[3] = { 85, 255, 255 };
	int DarkAqua[3] = { 0, 170, 170 };
	int DarkBlue[3] = { 0, 0, 170 };
	int Blue[3] = { 85, 85, 255 };
	int LightPurple[3] = { 255, 85, 255 };
	int DarkPurple[3] = { 170, 0, 170 };
	int White[3] = { 255, 255, 255 };
	int Gray[3] = { 170, 170, 170 };
	int DarkGray[3] = { 85, 85, 85 };
	int Black[3] = { 0, 0, 0 };
	int BlackTheme[3] = { 32, 32, 32 };
	int DescColor[4] = { 10, 10, 10, 50 };
};


char* checkTxt = "";
wchar_t charA2wcharA_[1000];

int MenuX = -41, MenuY = 6;

//Scroller
bool gotTime[1000], keyPressed[100], freeFirst[100], resetWait[100], resetWait2[100], lockFirst[100];
int getTime[1000], firstWaitTime = 15, waitTime = 5, scrollTick = 0, timeMath[1000], scroll = 0;

//menu
int CurrentMenu, CurrentOpt, MaxOption, MaxSubOptions, optionPress, returnPress, SpaceBetweenText = 13;
bool Opened, Closed;
int MenuColorAlpha = 255, MenuColorAlphaTitle = 255, MenuColorAlphaDescription = 255;
int SavePosition, AnimationSpeed = 10;
int SaveMenuX, speedSlider = 10, menuLenght = 5;

//Host Options
bool GodMode = false;
bool InstantDamage = false;
bool NoDamageHit = false;
bool Knockback = false;
bool NoKnockback = false;
bool PotionFlying = false;
bool PotionGravity = false;
bool InfiniteItems = false;
bool MaxPickupItems = false;
bool InfiniteBlocks = false;
bool BurnInWater = false;
bool RemoveFire = false;
bool InfiniteOxygen = false;
bool MobsIgnoreMe = false;
bool DisablePortals = false;
bool FreezeAllEntity = false;
bool ItemsOnHead = false;
bool EntityGodMode = false;
bool FastBow = false;
bool TNTNuclear = false;
bool DisableTotem = false;
bool StopBoat = false;
bool NoWeb = false;
bool DropFarItems = false;
bool LockGameMode = false;
bool LockWeather = false;
bool NoSpawnMobs = false;
bool NoEntityTP = false;
bool AllPlayersFastMine = false;
bool AllPlayersCantMine = false;
bool AllPlayersCantRun = false;
bool AllPlayersSpeed = false;
bool AllPlayersSuperRun = false;
bool PlayersCantJoin = false;
bool PlayersChangeHand = false;
bool AllPlayersSuffocate = false;
bool AllPlayersInFire = false;


//No Host Options
bool SuperSpeed = false;
bool MultiJump = false;
bool InstantHit = false;
bool ReachAttack = false;
bool KillAura = false;
bool FullAura = false;
bool CanFly = false;
bool NoColission = false;
bool SwimFly = false;
bool FastBuild = false;
bool InstantMine = false;
bool InfiniteCraft = false;
bool NameOverHead = false;
bool NameOverHeadV2 = false;
bool AutoSprint = false;
bool HurtCam = false;
bool ShowArmor = false;
bool UnfairAttack = false;
bool HitboxBETA = false;
bool BigVelocity = false;
bool NoVelocity = false;
bool ESPPlayers = false;
bool GravityMoon = false;
bool WaterSlowDown = false;
bool JumpInLava = false;
bool PosPlaceBlock = false;

//No Host Options 2
bool ItemsIds = false;
bool JumpForBuild = false;
bool ESPChests = false;
bool SensibilityFast = false;
bool WalkAlone = false;
bool AutoJump = false;
bool AutoChangeView = false;
bool AutoCrouch = false;
bool AutoMine = false;
bool AutoHit = false;
bool AutoBuild = false;
bool PressXForHit = false;

//FunnyOptions
bool Scaffold = false;
bool DayNight = false;
bool AlwaysCrouch = false;
bool Levitation = false;
bool AutoLadder = false;
bool AirToWater = false;
bool TNTFlying = false;
bool CreeperNuclear = false;
bool CreeperFire = false;
bool SpecialItems = false;
bool PlayersInfos = true;
bool VibrateWalk = false;
bool FootStepSlow = false;
bool Elytra = false;
bool MoveHeadNoBody = false;
bool DisablePlayers = false;
bool SmallText = false;
bool ArmsBroken = false;
bool LabyMode = false;
bool DragonEggSpawner = false;
bool GolemEggSpawner = false;
bool WitherEggSpawner = false;

//Mini Game Options
bool CanCraft = false;
bool CanPlaceBlocks = false;
bool CanSeeSpectator = false;
bool PlayersAreStarved = false;
bool AllowPortals = false;
bool TntCanDestroyBlocks = false;
bool MaxPlayersSmallMap = false;
bool CreativeInventory = false;
bool CanDestroyBlocks = false;
bool GameModeToSurvival = false;
bool InventoryCreaTumbleActive = false;
bool InventoryCreaTumble = false;
bool TPMiniGame = false;

//Mini Game Options 2
bool TeleportLobby = false;
bool TeleportCavern = false;
bool TeleportCove = false;
bool TeleportCrucible = false;

//Weather Options
bool DarkStorm = false;
bool RainbowStorm = false;
bool RainToSnow = false;
bool RainbowWithSnow = false;
bool FlashSky = false;
bool LightningBoldV1 = false;
bool LightningBoldV2 = false;

//VisualMenu
bool TogglePSN, TogglePosition, ToggleGametime, ToggleChunks, ToggleResolution, TogglePing, ToggleDebugPlayer, ToggleKeystrokes, ToggleKAura;
bool CustomSky = false;
bool BestSky = false;
bool PinkSky = false;
bool StarsSky = false;
bool BedrockHotbar = false;
bool OptimizedChunks = false;
bool FOVNoHand = false;
bool NightVision = false;
bool BetterTime = false;
bool WallHack = false;
bool XrayVision = false;
bool HorrorView = false;
bool GhostPlastic = false;
bool PlasticTexture = false;
bool MoreLight = false;
bool FlatBlocks = false;
bool CameraLeft = false;
bool CameraRight = false;
bool ParticlesFly = false;
bool AnimationRun = false;
bool SmokeLobby = false;

//VisualMenu2
int ValueFOV = 0;
bool SkinsDebug = false;
bool ShadowSkins = false;
bool SkinsPlayersRed = false;
bool BlackFog = false;
bool FreeCam = false;
bool RemoveHand = false;
bool HitDamageRed = false;
bool DisableFog = false;
bool EntityBaby = false;
bool NoDetailedSkins = false;
bool AimOn3thPerson = false;
bool RenderEntity = false;
bool RotationCam = false;
bool RotationBody = false;
bool TextureToBlack = false;
bool EntityBodyLight = false;
bool NetherVision = false;
bool ParticlesHitSpam = false;
bool RobloxAnimation = false;
bool StopAnimation = false;
bool GiantGameplay = false;
bool RealJumpAnim = false;
bool CameraDown = false;
bool CameraDownR3 = false;
bool RemoveInventoryHud = false;

//SelectionOptions
bool WhiteLine = false;
bool BlackLine = false;
bool BlueLine = false;
bool GreenLine = false;
int BigLine = 0;
int BoxLine = 0;

//ModulesMenu
bool Zoom = false;
bool TPAura = false;
bool PhaseV1 = false;
bool AutoTossItems = false;
bool HudLoading = false;
bool NoClip = false;

//SettingsMenu
bool ToggleTitleSPRX = true;

//DevMenu
bool BedrockUI = false;
bool Barrier = false;
bool IDsOnHead = false;
bool EnableSpecialBlock = false;
bool BarrierTest = false;
bool BarrierTestToIce = false;
bool AntiKickPremium = false;
bool LobbyMessagesSpam = false;
bool GetSpectatorMode = false;

//Rainbow color
int MenuColourTime = 0, RainbowTime = 0, RainbowRED1, RainbowGREEN1, RainbowBLUE1, RainbowRED2, RainbowGREEN2, RainbowBLUE2,  RainbowColor[3];
int Rainbow[3] = { RainbowRED1, RainbowGREEN1, RainbowBLUE1 };

//Keystrokes
int keystrokesBase_x = 0, keystrokesBase_y = 0;
int keystrokes_TextX[] = { 60,60,42,78 }, keystrokes_TextY[] = { 254,272,272,272 };
int* keystrokes_TextColor[] = { MC_Color::White, MC_Color::White, MC_Color::White, MC_Color::White };
int keystrokesHudX[] = { 55,55,37,73,37,40 }, keystrokesHudY[] = { 250,268,268,268,288,294 }, HudW[] = { 15,15,15,15,51,45 }, HudH[] = { 15,15,15,15,10,0 };
int* keystrokesHudColor1[] = { MC_Color::BlackTheme, MC_Color::BlackTheme, MC_Color::BlackTheme, MC_Color::BlackTheme, MC_Color::BlackTheme, MC_Color::BlackTheme };

//Teleport options
int CoordX = 0;
int CoordY = 0;
int CoordZ = 0;

//TP Aura
double TargetposX;
double TargetposY;
double TargetposZ;

int lastMenus[20];
int lastMenuCount = 0;

//Utility
char* PLR_NAME;
char* PLR_REGION;
int AntiVoidX;
int AntiVoidY;
int AntiVoidZ;
bool debug_entity_alive;

//Menu pos and select DCV4
int menulenght = 50;
int TitleTextX = 448;
int TitleTextY = 53;
int DebugLineStartX = 0;
int DebugLineStartY = 0;
int DebugLineEndX = 0;
int DebugLineEndY = 0;
int subMax = 0;
int textX = 468;
int textY = 63;
int AddOptX = 464;
int AddOptY = 75;
int textI = 9;
int bgX = 458;
int bgY = 73;
int bgW = 95;
int bgH = 11;
int CheckBoxX = 556;
int CheckBoxY = 70;