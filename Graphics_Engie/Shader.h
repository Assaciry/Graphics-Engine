#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>

#include "glad.h"

class Shader
{
public:
	enum class ShaderType {VERTEXSHADER, FRAGMENTSHADER };
public:
	static Shader* Instance();

public:
	bool CreateProgram();
	bool CreateShaders();

	bool CompileShaders(const std::string& filename, ShaderType shaderType);
	void AttachShaders();
	bool LinkProgram();

	void DetachShaders();
	void DestroyShaders();
	void DestroyProgram();

	GLuint GetShaderProgramID() const;

	bool SendUniformData(const std::string& uniformName, GLint data);
	bool SendUniformData(const std::string& uniformName, GLuint data);
	bool SendUniformData(const std::string& uniformName, GLfloat data);

	bool SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y);
	bool SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z);
	bool SendUniformData(const std::string& uniformName, GLfloat x, GLfloat y, GLfloat z, GLfloat w);

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
