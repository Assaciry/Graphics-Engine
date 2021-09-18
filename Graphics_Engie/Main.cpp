#include "Screen.h"
#include "Input.h"
#include "Shader.h"

bool isAppRunning = true;

#define SCREEN Screen::Instance()
#define INPUT Input::Instance()
#define SHADER Shader::Instance()

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

	if(!SHADER->CreateProgram())
	{
		return 0;
	}

	if(!SHADER->CreateShaders())
	{
		return 0;
	}

	if(!SHADER->CompileShaders("Shaders/Main.vert", Shader::ShaderType::VERTEXSHADER))
	{
		// ...
	}

	if(!SHADER->CompileShaders("Shaders/Main.frag", Shader::ShaderType::FRAGMENTSHADER))
	{
		// ...
	}

	SHADER->AttachShaders();

	if(!SHADER->LinkProgram())
	{
		// ...
	}

	float xPos = 0, yPos = 0;

	GLint ID = glGetUniformLocation(shaderProgramID, "time");

	if(ID == -1)
	{
		// Warning
	}

	glUniform1f(ID, 2.4f);

	// ===================================================================
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

	SHADER->DetachShaders();
	SHADER->DestroyShaders();
	SHADER->DestroyProgram();

	SCREEN->Close();

	system("pause");
	return 0;
}