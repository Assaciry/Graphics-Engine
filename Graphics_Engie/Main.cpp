#include "Screen.h"
#include "Input.h"

bool isAppRunning = true;

void drawQuad()
{
	glBegin(GL_QUADS);

	// top left
	glColor3f(1, 0, 0);
	glVertex3f(-0.5f, 0.5f, 0.0f);

	// top right
	glColor3f(0, 1, 0);
	glVertex3f(0.5f, 0.5f, 0.0f);

	// bottom right
	glColor3f(0, 0, 1);
	glVertex3f(0.5f, -0.5f, 0.0f);

	// bottom left
	glColor3f(0, 0, 1);
	glVertex3f(-0.5f, -0.5f, 0.0f);

	glEnd();
}

int main(int arg, char* argc[])
{
	Screen::Instance()->Initialize();

	while(isAppRunning)
	{
		Screen::Instance()->ClearScreen();

		if (Input::Instance()->IsKeyPressed())
			std::cout << "Key pressed!\n";

		drawQuad();

		Screen::Instance()->Render();
		
	}

	Screen::Instance()->Close();

	system("pause");
	return 0;
}