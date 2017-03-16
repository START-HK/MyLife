#include "InputManager.h"
#include "DxLib.h"
#include <iostream>
#define MAX_KEY_BUFFER 256

InputManager::InputManager()
{
	// ������
	for (int i = 0; i < MAX_KEY_BUFFER; ++i) {
		m_key[i]._state = State::None;
		m_key[i]._count = NULL;
		m_buffer[i] = NULL;
	}
}


InputManager::~InputManager()
{
	// �I������
	for (int i = 0; i < MAX_KEY_BUFFER; ++i) {
		m_key[i]._state = State::None;
		m_key[i]._count = NULL;
		m_buffer[i] = NULL;
	}
}

//�@�C���X�^���X�I�u�W�F�N�g�擾����
InputManager& InputManager::Instance() {
	static InputManager instance;
	return instance;
}

//�@�C���X�^���X�|�C���^�I�u�W�F�N�g�擾����
InputManager* InputManager::InstancePtr() {
	return &Instance();
}

// �X�V����
void InputManager::Update() {
	GetHitKeyStateAll(m_buffer);

	for (int i = 0; i < MAX_KEY_BUFFER; ++i) {
		if (m_buffer[i] > 0) {

			// ��Ԃ̐؂�ւ�
			if (m_key[i]._state == State::None)
				m_key[i]._state = State::Down;
			else if (m_key[i]._state == State::Down)
				m_key[i]._state = State::Press;

			// ������Ă���t���[�������J�E���g
			if (m_key[i]._state != State::None)
				m_key[i]._count += 1;
		}
		else {
			// �L�[���͂��Ȃ��Ƃ��͉������͂���������release�ɂ��Ă���
			// �����Ȃ���Ԃɖ߂�
			if (m_key[i]._state == State::Release) {
				m_key[i]._state = State::None;
				m_key[i]._count = NULL;
			}
			else
				if (m_key[i]._state != State::None)
					m_key[i]._state = State::Release;

		}
	}

}

// �L�[�I�u�W�F�N�g�擾����
InputManager::Key InputManager::GetKeyOf(int type) {
	return m_key[type];
}