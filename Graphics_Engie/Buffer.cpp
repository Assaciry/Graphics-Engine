#include "Buffer.h"

#include "Shader.h"

Buffer::Buffer()
{
	GLuint m_VAO = 0;
	GLuint m_vertexVBO = 0;
	GLuint m_colorVBO = 0;
	GLuint m_totalVertices = 0;
}


void Buffer::CreateBuffer(GLuint totalVertices)
{
	glGenBuffers(1, &m_vertexVBO);
	glGenBuffers(1, &m_colorVBO);
	glGenVertexArrays(1, &m_VAO);

	m_totalVertices = totalVertices;
}

void Buffer::FillVBO(VBOType vboType, GLfloat* data, GLsizeiptr bufferSize, FillType fillType)
{
	glBindVertexArray(m_VAO);

		if(vboType == VERTEX_BUFFER)
			glBindBuffer(GL_ARRAY_BUFFER, m_vertexVBO);
		else
			glBindBuffer(GL_ARRAY_BUFFER, m_colorVBO);

		glBufferData(GL_ARRAY_BUFFER, bufferSize, data, fillType);

	glBindVertexArray(0);

}

void Buffer::FillEBO(GLuint* data, GLsizeiptr bufferSize, FillType fillType)
{

}

void Buffer::LinkBuffer(const std::string& attribute,
						VBOType vboType, 
						ComponentType componentType,
						DataType dataType)
{
	GLuint shaderProgramID = Shader::Instance()->GetShaderProgramID();

	GLint ID = glGetAttribLocation(shaderProgramID, attribute.c_str());

	glBindVertexArray(m_VAO);

		if (vboType == VERTEX_BUFFER)
			glBindBuffer(GL_ARRAY_BUFFER, m_vertexVBO);
		else
			glBindBuffer(GL_ARRAY_BUFFER, m_colorVBO);

		glVertexAttribPointer(ID, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
		glEnableVertexAttribArray(ID);

	glBindVertexArray(0);

}

void Buffer::Render(DrawType drawType)
{
	glBindVertexArray(m_VAO);
	glDrawArrays(drawType, 0, m_totalVertices);
	glBindVertexArray(0);
}

void Buffer::DestroyBuffer()
{
	glDeleteBuffers(1, &m_vertexVBO);
	glDeleteBuffers(1, &m_colorVBO);
	glDeleteVertexArrays(1, &m_VAO);
}
