#pragma once


class GameResult : public IGameObject
{
public:
	GameResult();
	~GameResult();
	void Update();
	void Render(RenderContext& rc);

	SpriteRender spriteRender;
	SoundSource* GameClearBGM;

};

