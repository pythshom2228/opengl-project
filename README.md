# OpenGL + SFML
This is my study project that using Modern OpenGL

You can build this project in Windows and Linux

It includes SFML, GLEW, GLM and stb_image

Also you can view this project as example of usage Modern OpenGL

I will add some more things to this project in the future


## How to build
Supported Compilers: gcc, MinGw

To build the project, first clone it into your folder:
```
git clone https://github.com/pythshoma228/opengl-project.git
```
install vcpkg using git and build it yourself to have all dependecies:
```
cd opengl-project

git clone https://github.com/microsoft/vcpkg.git

vcpkg\bootstrap-vcpkg.bat (for Windows)

vcpkg/bootstrap-vcpkg.sh (for Linux)
```

Then use cmake command and don't forget to write your build path and generator:
```
cmake -S . -B YOUR_BUILD_FOLDER_PATH -G"YOUR_GENERATOR"
```
If you already have vcpkg then define variable
```
-DCMAKE_TOOLCHAIN_FILE=path_to_vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake
```

By default it shall build in Debug mode

To specify a certain build type add this variable
```
-DCMAKE_BUILD_TYPE=Debug/Release
```

And build:
```
cmake --build YOUR_BUILD_FOLDER_PATH
```

### Link to libraries I used

SFML https://github.com/SFML/SFML


GLEW https://github.com/nigels-com/glew


GLM https://github.com/g-truc/glm


stb_image https://github.com/nothings/stb
