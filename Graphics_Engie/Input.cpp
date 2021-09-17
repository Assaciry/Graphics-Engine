#include "Input.h"

Input::Input()
{
	m_keyDown = '\0';

	m_isXClicked            = false;
	m_isKeyPressed          = false;
	m_isLeftButtonClicked   = false;
	m_isMiddleButtonClicked = false;
	m_isRightButtonClicked  = false;
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
	return m_isKeyPressed;
}

char Input::GetKeyUp() const
{
	return m_keyUp;
}

char Input::GetKeyDown() const
{
	return m_keyDown;
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

	m_mouseMotionX = 0;
	m_mouseMotionY = 0;
	m_mousePositionX = 0;
	m_mousePositionY = 0;

	while(SDL_PollEvent(&events))
	{
		switch (events.type)
		{
			case SDL_QUIT:
				m_isXClicked = true;
			break;

			case SDL_KEYDOWN:
				m_isKeyPressed = true;
				m_keyDown = events.key.keysym.sym;
			break;

			case SDL_KEYUP:
				m_isKeyPressed = false;
				m_keyUp = events.key.keysym.sym;
			break;
			
			case SDL_MOUSEBUTTONDOWN:
				switch (events.button.button)
				{
					case SDL_BUTTON_LEFT:
						m_isLeftButtonClicked = true;
						break;

					case SDL_BUTTON_RIGHT:
						m_isRightButtonClicked = true;
						break;

					case SDL_BUTTON_MIDDLE:
						m_isMiddleButtonClicked = true;
						break;

					default:
						break;
				}
			break;

			case SDL_MOUSEBUTTONUP:
				switch (events.button.button)
				{
				case SDL_BUTTON_LEFT:
					m_isLeftButtonClicked = false;
					break;

				case SDL_BUTTON_RIGHT:
					m_isRightButtonClicked = false;
					break;

				case SDL_BUTTON_MIDDLE:
					m_isMiddleButtonClicked = false;
					break;

				default:
					break;
				}
			break;

			case SDL_MOUSEMOTION:
				m_mouseMotionX = events.motion.xrel;
				m_mouseMotionY = events.motion.yrel;

				m_mousePositionX = events.motion.x;
				m_mousePositionY = events.motion.y;
			break;

			default:
				break;
		}

	}


}
