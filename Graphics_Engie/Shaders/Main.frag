#version 460

in vec3 colorOut; // pass through from the vertex shader
out vec4 fragColor;

void main()
{
	fragColor = vec4(colorOut, 1.0);
	
}
