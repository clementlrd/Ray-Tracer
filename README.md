# Ray-Tracer

A basic ray tracer as a project for ENSTA Course IN204

## Create project

Create the project with CMake for the first time :
```bash
mkdir build
cd build
cmake ..
```

Then you can configure your editor (with `>CMake: Configure` for vscode with the CMake tools extension).

For lauching the project, you can type the `make` command in the `build/` forlder. 
The result is printed in the console, but you can put it in a picture :
```bash
make > ../render/image.ppm
```

## Project description

A scene is composed of objects in a 3D space that have a materials and color.

We implement basic math as vectors for doing the render : [explain math methode for rendering].

The project export the image in a file (we use the ppm format for simplicity at start)

## Development

We use the *clang-format* formatter.
