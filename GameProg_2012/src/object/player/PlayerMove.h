#pragma once
class CPlayerMove
{
public:
	CPlayerMove();

	//�@�X�V
	void Update();

private:

	//�@���ɓ�������
	void Left();

	//�@�E�ɓ�������
	void Right();

	//�@�����Ȃ��Ƃ��̏���
	void Stop();

	float m_velocity;				//�@���x
};

