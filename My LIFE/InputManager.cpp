#include "InputManager.h"
#include "DxLib.h"
#include <iostream>
#define MAX_KEY_BUFFER 256

InputManager::InputManager()
{
	// 初期化
	for (int i = 0; i < MAX_KEY_BUFFER; ++i) {
		m_key[i]._state = State::None;
		m_key[i]._count = NULL;
		m_buffer[i] = NULL;
	}
}


InputManager::~InputManager()
{
	// 終了処理
	for (int i = 0; i < MAX_KEY_BUFFER; ++i) {
		m_key[i]._state = State::None;
		m_key[i]._count = NULL;
		m_buffer[i] = NULL;
	}
}

//　インスタンスオブジェクト取得処理
InputManager& InputManager::Instance() {
	static InputManager instance;
	return instance;
}

//　インスタンスポインタオブジェクト取得処理
InputManager* InputManager::InstancePtr() {
	return &Instance();
}

// 更新処理
void InputManager::Update() {
	GetHitKeyStateAll(m_buffer);

	for (int i = 0; i < MAX_KEY_BUFFER; ++i) {
		if (m_buffer[i] > 0) {

			// 状態の切り替え
			if (m_key[i]._state == State::None)
				m_key[i]._state = State::Down;
			else if (m_key[i]._state == State::Down)
				m_key[i]._state = State::Press;

			// 押されているフレーム数をカウント
			if (m_key[i]._state != State::None)
				m_key[i]._count += 1;
		}
		else {
			// キー入力がないときは何か入力があったらreleaseにしてから
			// 何もない状態に戻す
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

// キーオブジェクト取得処理
InputManager::Key InputManager::GetKeyOf(int type) {
	return m_key[type];
}