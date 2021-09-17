#include "Screen.h"

Screen::Screen()
{
	window = nullptr;
	context = nullptr;
}

Screen* Screen::Instance()
{
	static Screen* instance = new Screen;
	return instance;
}

bool Screen::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Error initializing SDL.\n";
		return false;
	}

	std::cout << "SDL is running.\n";

	//SDL_GL_SetAttribute(attribute, value);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0); // 4.0

	window = SDL_CreateWindow("Graphics Engine",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1280, 720, SDL_WINDOW_OPENGL);

	if (window == nullptr)
	{
		std::cout << "Could not create SDL window.\n";
		return false;
	}

	context = SDL_GL_CreateContext(window);

	if (context == nullptr)
	{
		std::cout << "Could not create OpenGL context.\n";
		return false;
	}

	// Load all the Extension functionality
	if(!gladLoadGL())
	{
		std::cout << "Error loading extensions." << std::endl;
		return false;
	}


	return true;
}

void Screen::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT); // clear frame buffer
}

void Screen::Render()
{
	SDL_GL_SwapWindow(window); // swap back and front buffers
}

void Screen::Close()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
