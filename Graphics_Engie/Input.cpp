#include "Input.h"

Input::Input()
{
}

Input* Input::Instance()
{
	static Input* instance = new Input;
	return instance;
}

bool Input::IsXClicked() const
{
	return m_isXClicked;
}

bool Input::IsKeyPressed() const
{
	return m_keyDown;
}

char Input::GetKeyUp() const
{
	return m_keyUp;
}

char Input::GetKeyDown() const
{
	return m_keyUp;
}

bool Input::IsMouseLeftClicked() const
{
	return m_isLeftButtonClicked;
}

bool Input::IsMouseRightClicked() const
{
	return m_isRightButtonClicked;
}

bool Input::IsMouseMiddleClicked() const
{
	return m_isMiddleButtonClicked;
}

int Input::GetMousePositionX() const
{
	return m_mousePositionX;
}

int Input::GetMousePositionY() const
{
	return m_mousePositionY;
}

int Input::GetMouseMotionX() const
{
	return m_mouseMotionX;
}

int Input::GetMouseMotionY() const
{
	return m_mouseMotionY;
}

void Input::Update()
{
	SDL_Event events;

	while(SDL_PollEvent(&events))
	{
		if(events.type == SDL_KEYDOWN)
		{
			m_keyDown = true;
			std::cout << "A key was pressed\n";
		}
	}


}
