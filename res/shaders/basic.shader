#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;

uniform mat4 rotation;

void main() {
    gl_Position = rotation * (vec4(aPos,1.0));
    ourColor = aColor;
    TexCoord = aTexCoord;
}

#shader fragment
#version 330 core
out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;


void main() {
    FragColor = texture(texture1,TexCoord);
}