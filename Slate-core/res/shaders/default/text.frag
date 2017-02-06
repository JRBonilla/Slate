#version 330 core

layout (location = 0) out vec4 color;

in DATA
{
	vec4 position;
	vec2 uv;
	float tid;
	vec4 color;
} fs_in;

uniform sampler2D tex;

void main()
{
	vec4 texColor = fs_in.color;
    color = vec4(texColor.bgr, texture(tex, fs_in.uv).r);
}