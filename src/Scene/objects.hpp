#pragma once

#include "../maths/Vector3D.hpp"
#include <cmath>

#define pi M_PI

class Object {
protected:
  double length;
  Point3D origin;

public:
  virtual double area() const = 0;
  virtual double volume() const = 0;
};

class Cube : public Object {
private:
  // The three vectors that have length = Object.length and define a cube
  Vect3D vectx;
  Vect3D vecty;
  Vect3D vectz;

public:
  Cube();
  Cube(double side);
  Cube(double origin, double side, Vect3D vectx, Vect3D vecty, Vect3D vectz);
  Cube(const Cube &cube);

  double area(void) const { return 6 * length * length; }
  double volume(void) const { return length * length * length; }
  double get_side() const { return length; }
};

class Sphere : public Object {
  // The length corresponds to the radius
public:
  Sphere();
  Sphere(Point3D origin, double radius);
  Sphere(const Sphere &sphere);

  double area(void) const { return 4 * pi * length * length * length / 3; }
  double volume(void) const { return 4 * pi * length * length; }
  double get_radius() const { return length; }
};

class Plane : public Object {
  // The length corresponds to the radius
private:
  // With length = length
  Vect3D vectx;
  double width;
  // With length = width
  Vect3D vecty;

public:
  Plane();
  Plane(Point3D origin, double length, double width, Vect3D vectx,
        Vect3D vecty);
  Plane(const Plane &plane);

  double area(void) const { return length * width; }
  double volume(void) const { return 0; }
  double get_length() const { return length; }
  double get_width() const { return width; }
};
/* TO DO :
[DONE] Create an abstract base class and then create objects that can be added
to the scene (sphere, plan, cube...)

Each object can have the possibility to emit light.

Add texture to each object
*/