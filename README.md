# OpenGL + SFML + MinGW
This is my study project that using Modern OpenGL


This project includes SFML, GLEW, GLM and stb_image


It's only able to build using MinGW and can be executed with bash


Also you can view this project as example of usage Modern OpenGL


I will add some more things to this project in the future


## How to build
To build the project, first clone it into your folder:
```
git clone https://github.com/pythshoma228/opengl-project.git
```
Then use cmake command to generate make files and don't forget to add MinGW generator:
```
cmake -S . -B ${YOUR_BUILD_FOLDER} -G"MinGW Makefiles"
```
And build:
```
cmake --build ${YOUR_BUILD_FOLDER}
```

### Link to libraries I used

SFML https://github.com/SFML/SFML


GLEW https://github.com/nigels-com/glew


GLM https://github.com/g-truc/glm


stb_image https://github.com/nothings/stb
