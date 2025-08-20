#pragma once

//クラス宣言。
class Player;

//エネミー。
class Enemy : public IGameObject
{
public:
	//エネミーステート。
	enum EnEnemyState {
		enEnemyState_Idle,
		enEnemyState_Chase,
		enEnemyState_Attack,
	};
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();
	void Rotation();
	void Render(RenderContext& rc);

	//座標を設定する。
	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}

	//座標を取得する。
	const Vector3& GetPosition() const
	{
		return m_position;
	}

	//HPを設定する。
	///<param name="hp">HP。</param>
	void SetHP(const int HP)
	{
		m_hp = HP;
	}

	//回転を設定する。
	void SetRotation(const Quaternion& rotation)
	{
		m_rotation = rotation;
	}

	//大きさを設定する。
	void SetScale(const Vector3& scale)
	{
		m_scale = scale;
	}
private:
	///追跡処理。
	void Chase();
	///回転処理。
	void Rotaion();
	///攻撃処理
	void Attack();
	//プレイヤーを探索する。
	///<returns>プレイヤーが見つからなかったらtrue。
	const bool SearchPlayer() const;
	//攻撃用当たり判定コリジョンを作成する。
	void MakeAttackCollision();
	///アニメーションの再生。
	void PlayAnimation();
	///アニメーションイベント用の関数。
	///<param name="clipName>アニメーションの名前。</param>
	///<param name="eventName>アニメーションイベントのキーの名前。</param>
	void OnAnimationEvent(const wchar_t* clipName, const wchar_t* eventName);
	///各ステートの遷移処理。
	void ManageState();
	///共通のステート遷移処理。
	void ProcessCommonStateTransition();
	///待機ステートの遷移処理。
	void ProcessIdleStateTransition();
	///歩きステートの遷移処理。
	void ProcessWalkStateTransition();
	///走りステートの遷移処理。
	void PracessRunStateTransition();
	///追跡ステートの背遷移処理。
	void ProcessChaseStateTransition();
	///攻撃ステートの遷移処理。
	void ProcessAttackStateTransition();
	///魔法攻撃ステートの遷移処理。
	void ProcessMagicAttackStateTransition();
	///被ダメージステートの遷移処理。
	void PracessReceiveDamageStateTranition();
	///攻撃できる距離かどうか調べる。
	///<return>攻撃できるならtrue。</returns>
	const bool IsCanAttack() const;

	enum EnAnimationClip {
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Run,
		enAnimationClip_Attack,
		enAnimationClip_Damage,
		enAnimationClip_Num,
	};
	AnimationClip m_animationClips[enAnimationClip_Num];
	ModelRender m_modelRender;
	Vector3 m_position;
	Vector3 m_moveSpeed;
	Vector3 m_forward = Vector3::AxisZ;
	Quaternion m_rotation;
	Vector3 m_scale = Vector3::One;
	CharacterController m_charaCon;
	EnEnemyState m_enemyState = enEnemyState_Idle;
	bool m_isUnderAttack = false;
	int m_hp = 0;
	Player* m_player = nullptr;
	float m_chaseTimer = 0.0f;
	float m_idleTimer = 0.0f;
};

