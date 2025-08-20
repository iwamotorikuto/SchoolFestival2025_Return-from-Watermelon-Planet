#pragma once
#include "sound/SoundSource.h"


class Player;
class GameCamera;
class BackGround;
class Item;
class MovingFloor;

//Gameシーンを管理するクラス。
class Game : public IGameObject
{
public:
	Game();
	~Game();
	void Update();
	void Render(RenderContext& rc);
	
	Player* m_player;
	GameCamera* m_gameCamera;
	BackGround* m_backGround;//背景。
	Item* m_item;
	Vector3 Position;
	SoundSource* m_gameBGM;
	MovingFloor* m_movingFloor;
	
	
	//テキスト表示
	FontRender m_fontRender;

	//時間制限
	float Timer = 300.0f;

	float m_timer;
};

