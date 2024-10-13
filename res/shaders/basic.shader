#shader vertex
#version 400 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform mat4 rotation;
uniform mat4 model;
uniform mat4 projection;
unifrom mat4 view;

void main() {
    gl_Position = projection * view * model * rotation * (vec4(aPos,1.0));
    TexCoord = aTexCoord;
}
#shader fragment
#version 400 core
out vec4 Texture;

in vec2 TexCoord;

uniform sampler2D texture1;


void main() {
    
    Texture = texture(texture1,TexCoord);
}