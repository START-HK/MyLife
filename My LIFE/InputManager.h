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
		None,	// ‰½‚à‚È‚¢ó‘Ô
		Down,	// ‰Ÿ‚³‚ê‚½‚Ìó‘Ô
		Press,	// ‰Ÿ‚³‚ê‚Ä‚¢‚é‚Æ‚«
		Release,// —£‚³‚ê‚½

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