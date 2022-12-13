# Ray-Tracer

A basic ray tracer as a project for ENSTA Course IN204

Ressource : [RayTracingInOneWeek](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

## Commands

Compile and launch project, it renders the project in a ppm file :
```bash
make
``` 

Compile project only :

```bash
make build
``` 

Renders the project only (in a ppm file) :
```bash
make start
``` 

Clean project (remove binary files) :
```bash
make clean
``` 

### Miscellaneous

print in console :
```
make start-console
```

Renders in ppm :
```
make start-ppm
```

## Project description

A scene is composed of objects in a 3D space that have a materials and color.

We implement basic math as vectors for doing the render : [explain math methode for rendering].

The project export the image in a file (we use the ppm format for simplicity at start)

## Development

We use the *clang-format* formatter.

Use the command `make debug` for gdb.
