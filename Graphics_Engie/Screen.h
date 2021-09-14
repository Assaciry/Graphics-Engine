#ifndef SCREEN_H
#define SCREEN_H

#include <Windows.h>
#include <iostream>
#include <SDL.h>
#include <gl/GL.h>

class Screen
{
public:
	bool Initialize();
	void ClearScreen();
	void Render();
	void Close();

	static Screen* Instance();

private:
	Screen();
	Screen(const Screen& other);
	Screen& operator=(const Screen& other);

private:
	SDL_Window* window;
	SDL_GLContext context;
};

#endif

