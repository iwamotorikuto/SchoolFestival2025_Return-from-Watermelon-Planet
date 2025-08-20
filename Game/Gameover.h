#pragma once


class Title;
class explain;
class Gameover:public IGameObject
{
public:
	Gameover();
	~Gameover();

	void Update();
	void Render(RenderContext& rc);

	SpriteRender spriteRender;
	SoundSource* gameoverBGM;

	Title* title;

};

