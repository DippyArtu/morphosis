#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec3 aColor; // the color variable has attribute position 1
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor; // output a color to the fragment shader
out vec2 TexCoord;

uniform mat4 model; //model space transformation matrix
uniform mat4 view; //view space transformation
uniform mat4 projection; //world space transformation (perspective)

void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0f); //read multiplication from right to left in matricies
	ourColor = aColor;
	TexCoord = aTexCoord;
}