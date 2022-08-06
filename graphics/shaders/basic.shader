#shader vertex
#version 410 core

in vec4 pos;

void main()
{
   gl_Position = pos;
};


#shader fragment
#version 410 core

out vec4 color;

uniform vec4 u_Color;

void main()
{
	color = u_Color;
};
