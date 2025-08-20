#include "stdafx.h"
#include "explain.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"

explain::explain() 
{
	//‰æ‘œ‚Ì“Ç‚İ‚İ
	spriteRender.Init("Assets/explain/explain.DDS", 1920.0f, 1080.0f);

	//BGM
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/title_space.wav");
	explainBGM = NewGO<SoundSource>(0);
	explainBGM->Init(0);
	explainBGM->Play(true);
	//Œø‰Ê‰¹
	g_soundEngine->ResistWaveFileBank(6, "Assets/sound/SE.wav");
}

explain::~explain()
{
	DeleteGO(explainBGM);
}

void explain::Update()
{

	//Aƒ{ƒ^ƒ“‚ğ‰Ÿ‚µ‚½‚Æ‚«‚Ìˆ—
	if (g_pad[0]->IsTrigger(enButtonA)) {
		
		//Œø‰Ê‰¹‚ÌÄ¶
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(6);
		se->Play(false);
		NewGO<Game>(0);
		DeleteGO(this);
	}
}

void explain::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}