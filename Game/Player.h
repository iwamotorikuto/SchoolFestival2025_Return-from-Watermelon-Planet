#pragma once

//クラス宣言。
class Collision;
class Game;

class Player :public IGameObject
{
public:
	Player();
	~Player();
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);
	//移動処理。
	void Move();
	//回転処理。
	void Rotation();
	//ステート管理。
	void ManageState();
	//アニメーション再生。
	void PlayAnimation();

	const Vector3 GetPosition() const
	{
		return m_position;
	}

	void AddMoveSpeed(const Vector3 addMoveSpeed)
	{
		m_moveSpeed += addMoveSpeed;
	}

	CharacterController& GetCharacterController()
	{
		return m_characterController;
	}

	//ここからメンバ変数。
	ModelRender m_modelRender; //モデルレンダー。
	Vector3 m_position;
	enum EnAnimationClip {//アニメーション。
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num,
	};
	AnimationClip m_animationClips[enAnimationClip_Num];//アニメーションクリップ。
	CharacterController m_characterController;          //キャラクターコントローラー。
	Vector3 m_moveSpeed;//移動速度。
	Quaternion	m_rotation; //クォータニオン。
	int m_playerState = 0;
	int m_itemCount = 0;//集めたスイカの数をカウントする。
	int JumpCount = 0; 
	int m_hp = 10;
};