#shader vertex 
#version 400 core
layout (location = 0) in vec2 posCoord;


void main() {
    vec2 pos = posCoord / 60;
    pos.y *= 3;
    pos.x *= 2;
    gl_Position = vec4(pos,0,1.0);
}

#shader fragment
#version 400 core

out vec4 FragColor;

void main() {
    FragColor = vec4(0.8,0.8,0.8,1.0);
}