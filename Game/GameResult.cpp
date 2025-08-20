#include "stdafx.h"
#include "GameResult.h"
#include "Title.h"
#include "Player.h"
#include "Game.h"
#include "Item.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

GameResult::GameResult()
{
	spriteRender.Init("Assets/Gameclear/Gameclear.DDS", 1920.0f, 1080.0f);
	//BGM
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/Gameclear.wav");
	GameClearBGM = NewGO<SoundSource>(0);
	GameClearBGM->Init(2);
	GameClearBGM->Play(true);
	//Œø‰Ê‰¹
	g_soundEngine->ResistWaveFileBank(6, "Assets/sound/SE.wav");
}

GameResult::~GameResult()
{
	DeleteGO(GameClearBGM);
}
void GameResult::Update()
{
	if (g_pad[0]->IsTrigger(enButtonB))
	{
		//Œø‰Ê‰¹‚ÌÄ¶
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(6);
		se->Play(false);
		NewGO<Title>(0);
		DeleteGO(this);
	}

}

void GameResult::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}