#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_

class InputManager
{
private:
	InputManager();
	~InputManager();

public:
	enum class State
	{
		None,	// 何もない状態
		Down,	// 押された時の状態
		Press,	// 押されているとき
		Release,// 離された時

	};

	struct Key
	{
		State	_state;
		int		_count;
	};
	

	static InputManager& Instance();
	static InputManager* InstancePtr();
	void Update();

	Key GetKeyOf(int);

private:
	Key m_key[256];
	char  m_buffer[256];

};

#endif