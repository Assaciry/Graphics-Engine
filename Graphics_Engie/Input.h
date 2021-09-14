#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <iostream>

class Input
{
public:
	static Input* Instance();

public:
	bool IsXClicked() const;
	bool IsKeyPressed() const ;

	char GetKeyUp() const;
	char GetKeyDown() const;

	bool IsMouseLeftClicked() const;
	bool IsMouseRightClicked() const;
	bool IsMouseMiddleClicked() const;

	int GetMousePositionX() const;
	int GetMousePositionY() const;

	int GetMouseMotionX() const;
	int GetMouseMotionY() const;

	void Update();

private:
	Input();
	Input(const Input& other);
	Input& operator=(const Input& other);

private:
	char m_keyUp;
	char m_keyDown;

	bool m_isXClicked;
	bool m_isKeyPressed;

	bool m_isLeftButtonClicked;
	bool m_isRightButtonClicked;
	bool m_isMiddleButtonClicked;

	int m_mouseMotionX;
	int m_mouseMotionY;

	int m_mousePositionX;
	int m_mousePositionY;

};

#endif
