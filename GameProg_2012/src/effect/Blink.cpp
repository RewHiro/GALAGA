#include "Blink.h"
#include "../utility/Random.h"
#include <limits>


//�@MEMO
//�@�R���X�g���N�^
//�@������State�Ƃ���enumclass��錾���Aconst�C���q��t����ƃG����

//�@state:�I�u�W�F�N�g�̏�Ԃ�����
//�@blink_time:�_�ł��鎞��
//�@start_count:�X�^�[�g�̎���
//�@transparency_stop_time:�������I������
CBlink::CBlink(Object::State &state, const int blink_time, const unsigned long start_count, const int transparency_stop_time) :
BLINK_TIME(blink_time),
TRANSPARENCY_STOP_TIME(transparency_stop_time),
m_state(state),
m_count(start_count),
m_transparency_count(0)
{
}

//�@�X�V
void CBlink::Update(){
	if (m_state == Object::State::NONE)return;
	m_count++;
	TransitionOfState();
	CountReset();
}

//�@�J�E���g�����Z�b�g
void CBlink::CountReset(){
	if ((std::numeric_limits<unsigned long>::max)() - 10 > m_count)return;
	m_count = 0;
}

//�@��Ԃ̑J��
void CBlink::TransitionOfState(){
	Transparent();
	ChanegeOfTransparent();
}

//�@�����ɂȂ鏈��
void CBlink::ChanegeOfTransparent(){
	if (m_state != Object::State::LIVE)return;
	if (m_count % BLINK_TIME == 0){
		m_state = Object::State::TRANSPARENCY;
	}
}

//�@��Ԃ�߂�
void CBlink::ReturnState(){
	if (m_transparency_count != TRANSPARENCY_STOP_TIME)return;
	m_state = Object::State::LIVE;
	m_transparency_count = 0;
}

//�@�������̏���
void CBlink::Transparent(){
	if (m_state != Object::State::TRANSPARENCY)return;
	m_transparency_count++;
	ReturnState();
}