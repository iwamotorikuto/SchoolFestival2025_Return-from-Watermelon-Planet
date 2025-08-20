#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "explain.h"
#include "sound/SoundEngine.h"

Title::Title()
{
	//画像を読み込む。
	m_spriteRender.Init("Assets/sprite/suika.DDS", 1920.0f, 1080.0f);

	//タイトルのBGMを読み込む。
	g_soundEngine->ResistWaveFileBank(7, "Assets/sound/title_space.wav");

	//タイトルのBGMを再生する。
	m_titleBGM = NewGO<SoundSource>(0);
	m_titleBGM->Init(7);
	m_titleBGM->Play(true);
	//効果音
	g_soundEngine->ResistWaveFileBank(6, "Assets/sound/SE.wav");

}

Title::~Title()
{
    //タイトルのBGMを削除する。
	DeleteGO(m_titleBGM);
}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//効果音の再生
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(6);
		se->Play(false);
		NewGO<explain>(0);
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	//画像を描画する。
	m_spriteRender.Draw(rc);
}
