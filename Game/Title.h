#pragma once

//タイトル。
class Title:public IGameObject
{
public:
	Title();
	~Title();
	//更新処理。
	void Update();
	//描画関数。
	void Render(RenderContext& rc);
	//スプライトレンダー。
	SpriteRender m_spriteRender;
	SoundSource* m_titleBGM;
};

