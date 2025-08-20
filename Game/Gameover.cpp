#include "stdafx.h"
#include "Gameover.h"
#include "Title.h"
#include "explain.h"
#include "Game.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"



Gameover::Gameover()
{
	//画像処理
	spriteRender.Init("Assets/Gameover/Gameover.DDS", 1920.0f, 1080.0f);

	//BGM
	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/Gameover.wav");
	gameoverBGM = NewGO<SoundSource>(0);
	gameoverBGM ->Init(3);
	gameoverBGM->Play(true);
	//効果音
	g_soundEngine->ResistWaveFileBank(6, "Assets/sound/SE.wav");
}

Gameover::~Gameover()
{
	DeleteGO(gameoverBGM);
}

void Gameover::Update()
{
	//Bボタンの処理
	if (g_pad[0]->IsTrigger(enButtonB)) {
	//タイトル
		//効果音の再生
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(6);
		se->Play(false);
		NewGO<Title>(0);
		DeleteGO(this);
	}

	//Aボタンの処理
	if (g_pad[0]->IsTrigger(enButtonA)) {
		//リトライ
		//効果音の再生
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(6);
		se->Play(false);
		NewGO<Game>(0);
		DeleteGO(this);
	}
}

void Gameover::Render(RenderContext& rc)
{
	//描画処理
	spriteRender.Draw(rc);
}