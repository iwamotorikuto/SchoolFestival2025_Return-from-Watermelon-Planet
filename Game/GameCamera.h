#pragma once
class Player;
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start();
	void Update();
	//プレイヤー。
	Player* m_player;
	Vector3 m_toCameraPos;
	GameCamera* m_GameCamera;
};

