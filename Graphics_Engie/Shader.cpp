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
	m_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	m_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	if(m_vertexShaderID == 0)
	{
		std::cout << "Error creating the vertex shader." << std::endl;
		return false;
	}

	if (m_fragmentShaderID == 0)
	{
		std::cout << "Error creating the fragment shader." << std::endl;
		return false;
	}

	return true;
}

bool Shader::CompileShaders(const std::string& filename, ShaderType shaderType)
{
	std::fstream file;
	std::string line;
	std::string sourceCode;
	GLuint shaderID;

	shaderID = (shaderType == ShaderType::VERTEXSHADER) ? m_vertexShaderID : m_fragmentShaderID;

	file.open(filename);

	if(!file)
	{
		std::cout << "Error reading shader file: " << filename << std::endl;
		return false;
	}

	while(!file.eof())
	{
		std::getline(file, line);
		sourceCode += line + "\n";
	}

	file.close();

	const GLchar* finalSourceCode = reinterpret_cast<const GLchar*>( sourceCode.c_str() );
	glShaderSource(shaderID, 1, &finalSourceCode, nullptr);
	glCompileShader(shaderID);

	GLint errorCode;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &errorCode);

	if(errorCode == GL_TRUE)
	{
		std::cout << "Shader compilation successful." << std::endl;
	}

	else
	{
		GLchar errorBuffer[1000];
		GLsizei bufferLength = 1000;

		glGetShaderInfoLog(shaderID, bufferLength, &bufferLength, errorBuffer);
		std::cout << errorBuffer << std::endl;
		return false;
	}

	return true;
}

void Shader::AttachShaders()
{
	glAttachShader(m_shaderProgramID, m_vertexShaderID);
	glAttachShader(m_shaderProgramID, m_fragmentShaderID);
}

bool Shader::LinkProgram()
{
	glLinkProgram(m_shaderProgramID);
	glUseProgram(m_shaderProgramID);

	GLint errorCode;
	glGetProgramiv(m_shaderProgramID, GL_LINK_STATUS, &errorCode);
	if (errorCode == GL_TRUE)
	{
		std::cout << "Shader linking successful." << std::endl;
	}

	else
	{
		GLchar errorBuffer[1000];
		GLsizei bufferLength = 1000;

		glGetProgramInfoLog(m_shaderProgramID, bufferLength, &bufferLength, errorBuffer);
		std::cout << errorBuffer << std::endl;
		return false;
	}

	return true;
}

void Shader::DetachShaders()
{
	glDetachShader(m_shaderProgramID, m_vertexShaderID);
	glDetachShader(m_shaderProgramID, m_fragmentShaderID);
}

void Shader::DestroyShaders()
{
	glDeleteShader(m_vertexShaderID);
	glDeleteShader(m_fragmentShaderID);
}

void Shader::DestroyProgram()
{
	glDeleteProgram(m_shaderProgramID);
}

GLuint Shader::GetShaderProgramID() const
{
	return m_shaderProgramID;
}

bool Shader::SendUniformData(const std::string& uniformName, GLint data)
{
	GLint ID = glGetUniformLocation(m_shaderProgramID, uniformName.c_str());

	if (ID == -1)
	{
		std::cout << "Shader variable " << uniformName << " not found or not used." << std::endl;
		return false;
	}

	glUniform1i(ID, data);
	return true;
}

bool Shader::SendUniformData(const std::string& uniformName, GLuint data)
{
	GLint ID = glGetUniformLocation(m_shaderProgramID, uniformName.c_str());

	if (ID == -1)
	{
		std::cout << "Shader variable " << uniformName << " not found or not used." << std::endl;
		return false;
	}

	glUniform1ui(ID, data);
	return true;
}

bool Shader::SendUniformData(const std::string& uniformName, GLfloat data)
{
	GLint ID = glGetUniformLocation(m_shaderProgramID, uniformName.c_str());

	if (ID == -1)
	{
		std::cout << "Shader variable " << uniformName << " not found or not used." << std::endl;
		return false;
	}

	glUniform1f(ID, data);
	return true;
}

bool Shader::SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y)
{
	GLint ID = glGetUniformLocation(m_shaderProgramID, uniformName.c_str());

	if (ID == -1)
	{
		std::cout << "Shader variable " << uniformName << " not found or not used." << std::endl;
		return false;
	}

	glUniform2f(ID, x, y);
	return true;
}

bool Shader::SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z)
{
	GLint ID = glGetUniformLocation(m_shaderProgramID, uniformName.c_str());

	if (ID == -1)
	{
		std::cout << "Shader variable " << uniformName << " not found or not used." << std::endl;
		return false;
	}

	glUniform3f(ID, x, y, z);
	return true;
}

bool Shader::SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	GLint ID = glGetUniformLocation(m_shaderProgramID, uniformName.c_str());

	if (ID == -1)
	{
		std::cout << "Shader variable " << uniformName << " not found or not used." << std::endl;
		return false;
	}

	glUniform4f(ID, x, y, z, w);
	return true;
}
