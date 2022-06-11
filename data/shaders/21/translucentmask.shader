#shader fragment
#version 120

uniform sampler2D tex;
uniform vec4 col;
in vec2 UV;
out vec4 fragColor;

void main(void)
{
  fragColor = vec4(col.rgb, texture(tex, UV).r);
}

#shader vertex
#version 120

uniform mat4 MVP;
in vec2 Position;
in vec2 TexCoord;
out vec2 UV;

void main(void)
{
  UV = TexCoord;
  gl_Position = MVP*vec4(Position, 0.0, 1.0);
}

