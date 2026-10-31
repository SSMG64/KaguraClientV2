#include "Minecraft/entity/Entity.h"
#include "Minecraft/entity/player/ServerPlayer.h"
#include "Minecraft/world/entity/DamageSource.h"
#include <string>
#include <vector>
#include "Minecraft/util/AABB.h"
#include "Minecraft/util/Vec2.h"
#include "Minecraft/util/Vec3.h"
#pragma once

void LoopOptions()
{
	Menu::TitleSPRX(L"Kagura Client SPRX");
	Options::ShowPSN();
	Options::ShowGametime();
	Options::ShowPosition();
	Options::ShowChunks();
	Options::ShowResolution();
	Options::ShowPing();
	Options::ShowDebugPlayer();
	Options::ShowKeystrokes();
	Options::KAura();
	Modules::ZoomModule();
	GetInfosLastPlayer();
	DoRainbowColor();
	SlideOpenMenuAnimation();
	SlideCloseMenuAnimation();
	Render();
	logs::draw_logs();
}

#pragma region "ASM"

void gameRender_Stub(uint32_t r3, uint32_t r4)
{
	__nop(); __nop(); __nop(); __nop(); __nop();
}

void RenderScreen_Stub(uint32_t r3, uint32_t r4) {
	__nop(); __nop(); __nop(); __nop(); __nop();
}

void Gui_render_Stub(GuiComponent* gui, double unk) {
	__nop(); __nop(); __nop(); __nop(); __nop();
}

void RenderScreen_Hook(uint32_t r3, uint32_t r4) {
	RenderScreen_Stub(r3, r4);
	mc = (TheMinecraft*)(0x014CF2E4);
	MaxOption = 0;
	DrawText(L"Working", -80, -80, color(MC_Color::White));
	LoopOptions();
}

int asm_SetPresenceDetails_Hook(SceNpBasicPresenceDetails2* pres, uint32_t options)
{
	__nop(); __nop(); __nop(); __nop(); __nop();
}
int sceNpBasicSetPresenceDetails_Hook(SceNpBasicPresenceDetails2* pres, uint32_t options)
{
	strncpy(pres->status, "Using \uF477 Kagura Client V2 SPRX \uF477", 70);

	return asm_SetPresenceDetails_Hook(pres, options);
}

int asm_destroyBlockHook(MultiPlayerGameMode* gamemode, BlockPos* blockPos) // ou (...) si tu veux opti apres  sa depend des fois sa marche des fois non!
{
	__nop(); __nop(); __nop(); __nop(); __nop();
	//__asm("li %r3, 0x332;");
}

void asm_LivingEntity_HurtHook(Entity* entity, EntityDamageSource* entityDamageSource, float damage)
{
	__nop(); __nop(); __nop(); __nop(); __nop();
	//__asm("li %r3, 0x332;");
}

void asm_Player_HurtHook(ServerPlayer* player, DamageSource* damageSource, float damage)
{
	__nop(); __nop(); __nop(); __nop(); __nop();
}

uint32_t asm_LivingEntity_onChangedBlockHook(Entity* entity, BlockPos* pos)
{
	__nop(); __nop(); __nop(); __nop(); __nop();
}

#pragma endregion

void LivingEntity_HurtHook(Entity* entity, EntityDamageSource* entityDamageSource, float damage)
{
	//FUNCTIONS::Player_getAttachPos(entity, 10);
	asm_LivingEntity_HurtHook(entity, entityDamageSource, damage);
}

void Player_actuallyHurtHook(ServerPlayer* player, DamageSource* damageSource, float damage)
{
	if (player->isAlive())
		debug_entity_alive = true;
	else
		debug_entity_alive = false;

	Modules::TP_Aura(player);

	asm_Player_HurtHook(player, damageSource, damage);
}

void InstallHooks()
{
	HookFunctionStart(0x00A89068, *(uint32_t*)(RenderScreen_Hook), *(uint32_t*)(RenderScreen_Stub));
	HookFunctionStart(0x01084270, *(uint32_t*)(sceNpBasicSetPresenceDetails_Hook), *(uint32_t*)(asm_SetPresenceDetails_Hook));
	HookFunctionStart(0x3A7F48, *(uint32_t*)(LivingEntity_HurtHook), *(uint32_t*)(asm_LivingEntity_HurtHook));
	HookFunctionStart(0x4A94B8, *(uint32_t*)(Player_actuallyHurtHook), *(uint32_t*)(asm_Player_HurtHook));
}

void UninstallHooks()
{
	UnHookFunctionStart(0x00AA3360, *(uint32_t*)(RenderScreen_Hook));
	UnHookFunctionStart(0x01084270, *(uint32_t*)(sceNpBasicSetPresenceDetails_Hook));
	UnHookFunctionStart(0x3A7F48, *(uint32_t*)(LivingEntity_HurtHook));
	UnHookFunctionStart(0x4A94B8, *(uint32_t*)(Player_actuallyHurtHook));
}