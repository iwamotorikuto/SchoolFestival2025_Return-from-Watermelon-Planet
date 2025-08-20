#pragma once
class explain:public IGameObject
{
public:
	explain();
	~explain();

	void Update();
	void Render(RenderContext& rc);

	//ƒƒ“ƒo•Ï”
	SoundSource* explainBGM;//BGM

	SpriteRender spriteRender;

};

