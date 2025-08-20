#pragma once

//背景。
class BackGround:public IGameObject
{
public:
	BackGround();
	~BackGround();

	//描画関数。
	void Render(RenderContext& rc);

	//モデルレンダー。
	ModelRender m_modelRender;
	PhysicsStaticObject m_physicsStaticObject;
};

