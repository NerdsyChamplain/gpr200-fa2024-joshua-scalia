#version 330 core
out vec4 FragColor;

in vec4 ourColor;
in vec2 TexCoord;
uniform sampler2D texture2;
uniform sampler2D texture3;
void main()
{
    FragColor = mix(texture(texture2, TexCoord * 7.0f), texture(texture3, TexCoord * 7.0f), 0.5);
}