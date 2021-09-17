#include "Screen.h"
#include "Input.h"

bool isAppRunning = true;

#define SCREEN Screen::Instance()
#define INPUT Input::Instance()

void drawQuad(float x, float y)
{
	glBegin(GL_QUADS);

	// top left
	glColor3f(1, 0, 0);
	glVertex3f(x - 0.5f, y + 0.5f, 0.0f);

	// top right
	glColor3f(0, 1, 0);
	glVertex3f(x + 0.5f, y + 0.5f, 0.0f);

	// bottom right
	glColor3f(0, 0, 1);
	glVertex3f(x + 0.5f, y - 0.5f, 0.0f);

	// bottom left
	glColor3f(0, 0, 1);
	glVertex3f(x - 0.5f, y - 0.5f, 0.0f);

	glEnd();
}

int main(int arg, char* argc[])
{
	SCREEN->Initialize();

	float xPos = 0, yPos = 0;

	while(isAppRunning)
	{
		SCREEN->ClearScreen();
		INPUT->Update();

		isAppRunning = !INPUT->IsXClicked();

		char keyPressed = INPUT->GetKeyDown();
		switch (keyPressed)
		{
			case 'w':
				yPos += 0.01f;
				break;

			case 's':
				yPos -= 0.01f;
				break;

			case 'a':
				xPos -= 0.01f;
				break;

			case 'd':
				xPos += 0.01f;
				break;

			default:
				break;
		}

		drawQuad(xPos, yPos);

		SCREEN->Render();
		
	}

	SCREEN->Close();

	system("pause");
	return 0;
}