#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>

#include "glad.h"

class Shader
{
public:
	static Shader* Instance();

public:
	bool CreateProgram();
	bool CreateShaders();

	bool CompileShaders(const std::string& filename);
	void AttachShaders();
	bool LinkProgram();

	void DetachShaders();
	void DestroyShaders();
	void DestroyProgram();

private:
	Shader();
	Shader(const Shader& other);
	Shader operator=(const Shader& other);

private:
	GLuint m_shaderProgramID;
	GLuint m_vertexShaderID;
	GLuint m_fragmentShaderID;
};

#endif
