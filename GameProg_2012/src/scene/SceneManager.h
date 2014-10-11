#pragma once
#include "../Uncopyable.h"
#include <memory>

//=====================================
//シーンクラス
//=====================================

class CScene : Uncopyable{
public:
	CScene() = default;
	~CScene() = default;

	void virtual Update() = 0;
	void virtual Draw() = 0;

};

//=====================================
//シーン管理クラス
//=====================================

class CSceneManager : private Uncopyable{
public:

	//　シーンの種類
	enum class Scene{
		TITLE,
		STAGE,
		RESULT
	};


	~CSceneManager();

	//　インスタンスの取得
	static CSceneManager &GetInstacnce(){
		static CSceneManager instance;
		return instance;
	}

	//　更新
	void Update();

	//　描画
	void Draw();

	static const int WIDTH = 600;		//　画面の横サイズ
	static const int HEIGHT = 800;		//　画面の縦サイズ

private:
	CSceneManager();
	enum class State;					//　状態の種類
	static Scene m_now_scene;			//　現在のシーン
	Scene m_old_scene;					//　遷移する前のシーン
	State m_state;						//　現在の状態
	std::unique_ptr<CScene>m_scene;		//　シーンのインスタンス

	//　遷移処理
	void Transition();

	//　状態を初期化する
	void InitializeTheState();

	//　遷移したいシーンを渡す関数
	static void SelectScene(Scene next_scene);

	enum class State{
		INIT,
		UPDATE
	};
};