#include "Shader.h"

#include <iostream>

Shader::Shader()
{
	m_shaderProgramID = 0;
	m_vertexShaderID = 0;
	m_fragmentShaderID = 0;
}

Shader* Shader::Instance()
{
	static Shader* instance = new Shader;
	return instance;
}


bool Shader::CreateProgram()
{
	m_shaderProgramID = glCreateProgram();

	if (m_shaderProgramID == 0)
	{
		std::cout << "Error creating shader program." << std::endl;
		return false;
	}

	return true;
}

bool Shader::CreateShaders()
{


	return true;
}

bool Shader::CompileShaders(const std::string& filename)
{
	return true;
}

void Shader::AttachShaders()
{
}

bool Shader::LinkProgram()
{
	return true;
}

void Shader::DetachShaders()
{
}

void Shader::DestroyShaders()
{
}

void Shader::DestroyProgram()
{
}
