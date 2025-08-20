#pragma once

class Player;
class Item;
extern Item* item;
class Item:public IGameObject
{
public:
	Item();
	~Item();
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& renderContext);
	//移動処理
	void Move();

	//float collisionRadius = 100.0f;//当たり判定の半径（調整可）

	//ここからメンバ変数。
	ModelRender m_modelRender;
	Vector3 m_position;
	Vector3 firstPosition;//最初の座標。
	Player* player;//プレイヤー
	//PhysicsStaticObject physicsStaticObject;
};

