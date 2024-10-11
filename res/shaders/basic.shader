#shader vertex
#version 400 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;

uniform vec3 position;

void main() {
    gl_Position = vec4(aPos,1.0) + vec4(position,1.0);
    ourColor = aColor;
    TexCoord = aTexCoord;
}

#shader fragment
#version 400 core
out vec4 FragColor;
  
in vec2 TexCoord;

uniform sampler2D texture1;


void main() {
    FragColor = texture(texture1,TexCoord);
}