#include "stdafx.h"
#include "Item.h"
#include "Player.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Item::Item()
{
	

	//モデルを読み込む。
	m_modelRender.Init("Assets/modelData/item/item.tkm");

	//physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	
	
	//プレイヤーのオブジェクトを探して持ってくる。
	player= FindGO<Player>("player");

	//効果音の読み込み
	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/itemSE.wav");

	//大きさの変更
	m_modelRender.SetScale({ 50.0f,50.0f,50.0f });
}

Item::~Item() {

}

void Item::Update()
{
	Move();

	
	
	//プレイヤーからスイカに向かうベクトルを計算。
	Vector3 diff =  player->m_position - m_position;
	//ベクトルの長さが100.0fより小さかったら。
	if (diff.Length() <= 100.0f)
	{
		//カウントを+1する
		player->m_itemCount += 1;

		//効果音の処理
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(4);
		se->SetVolume(3.5f);
		se->Play(false);

		//自身を削除する
		DeleteGO(this);

	}

	//絵描きさんの更新処理。
	m_modelRender.Update();
}

void Item::Move()
{
	m_modelRender.SetPosition(m_position);
}

void Item::Render(RenderContext& rc)
{
	//Itemを描画する。
	m_modelRender.Draw(rc);
}