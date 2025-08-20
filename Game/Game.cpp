#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "Item.h"
#include "Title.h"
#include "explain.h"
#include "Gameover.h"
#include "GameResult.h"
#include "sound/soundEngine.h"
#include "MovingFloor.h"
#include "Enemy.h"

Game::Game()
{
	//プレイヤーのオブジェクトを作る。
	m_player = NewGO<Player>(0, "player");

	//ゲームカメラのオブジェクトを作る。
	m_gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//背景のオブジェクトを作る。
	m_backGround = NewGO<BackGround>(0);

	Item* item1 = NewGO<Item>(0, "item");
	item1->m_position = { 0.0f,-400.0f,-25.0f };
	item1->firstPosition = item1->m_position;

	Item* item2 = NewGO<Item>(0, "item");
	item2->m_position = { 1900.0f,-2050.0f,2100.0f };
	item2->firstPosition = item2->m_position;

	Item* item3 = NewGO<Item>(0, "item");
	item3->m_position = { 1050.0f,-900.0f,-150.0f };
	item3->firstPosition = item3->m_position;

	Item* item4 = NewGO<Item>(0, "item");
	item4->m_position = { -1850.0f,1950.0f,4200.0f };
	item4->firstPosition = item4->m_position;

	Item* item5 = NewGO<Item>(0, "item");
	item5->m_position = { -2250.0f,-1500.0f,-25.0f };
	item5->firstPosition = item5->m_position;

	Item* item6 = NewGO<Item>(0, "item");
	item6->m_position = { -2450.0f,-1500.0f,-25.0f };
	item6->firstPosition = item6->m_position;

	Item* item7 = NewGO<Item>(0, "item");
	item7->m_position = { -2650.0f,-1500.0f,-25.0f };
	item7->firstPosition = item7->m_position;

	//ゲーム中のBGMを読み込む。
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/game_bgm.wav");
	
	//ゲーム中のBGMを再生する。
	m_gameBGM = NewGO<SoundSource>(0);
	m_gameBGM->Init(1);
	m_gameBGM->Play(true);


	//NewGOの引数で、Update関数の処理順番を設定する。
	//動く床→プレイヤーの順番にする。
	m_movingFloor = NewGO<MovingFloor>(0, "movingFloor");
	m_movingFloor->SetPosition(Vector3(0.0f, 10.0f, 500.0f));

	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	
}


//デストラクタ
Game::~Game()
{
	//プレイヤーを削除する。
	DeleteGO(m_player);
	//ゲームカメラを削除する。
	DeleteGO(m_gameCamera);
	//ゲーム中のBGMを削除する。
	DeleteGO(m_gameBGM);
	//背景を削除する。
	DeleteGO(m_backGround);
	
}


void Game::Update()
{
	//制限時間の表示
    wchar_t Timertext[256];
    //桁数の指定
	swprintf_s(Timertext, 256, L"%4.2f秒", (float)Timer);

	m_fontRender.SetText(Timertext);
	m_fontRender.SetPosition({ 735.0f,450.0f,0.0f });

	////制限時間
	Timer -= g_gameTime->GetFrameDeltaTime();
	if (Timer <= 1.0f) {
		NewGO<Gameover>(0, "gameover");
	    DeleteGO(this);
	}
}

void Game::Render(RenderContext& rc)
{
	m_fontRender.Draw(rc);

	if (m_player->m_itemCount >= 5)
	{
		NewGO<GameResult>(0, "gameresult");
		DeleteGO(this);
	}
}






