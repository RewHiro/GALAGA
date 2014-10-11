#pragma once
#include "../Uncopyable.h"
#include <memory>

//=====================================
//�V�[���N���X
//=====================================

class CScene : Uncopyable{
public:
	CScene() = default;
	~CScene() = default;

	void virtual Update() = 0;
	void virtual Draw() = 0;

};

//=====================================
//�V�[���Ǘ��N���X
//=====================================

class CSceneManager : private Uncopyable{
public:

	//�@�V�[���̎��
	enum class Scene{
		TITLE,
		STAGE,
		RESULT
	};


	~CSceneManager();

	//�@�C���X�^���X�̎擾
	static CSceneManager &GetInstacnce(){
		static CSceneManager instance;
		return instance;
	}

	//�@�X�V
	void Update();

	//�@�`��
	void Draw();

	static const int WIDTH = 600;		//�@��ʂ̉��T�C�Y
	static const int HEIGHT = 800;		//�@��ʂ̏c�T�C�Y

private:
	CSceneManager();
	enum class State;					//�@��Ԃ̎��
	static Scene m_now_scene;			//�@���݂̃V�[��
	Scene m_old_scene;					//�@�J�ڂ���O�̃V�[��
	State m_state;						//�@���݂̏��
	std::unique_ptr<CScene>m_scene;		//�@�V�[���̃C���X�^���X

	//�@�J�ڏ���
	void Transition();

	//�@��Ԃ�����������
	void InitializeTheState();

	//�@�J�ڂ������V�[����n���֐�
	static void SelectScene(Scene next_scene);

	enum class State{
		INIT,
		UPDATE
	};
};