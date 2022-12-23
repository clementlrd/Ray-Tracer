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
  virtual Vect3D normal(Point3D surface_pt) const = 0;
  virtual Vect3D tangent(Point3D surface_pt) const = 0;
};

class Cube : public Object {
private:
  // The three length of vectors are Object.length
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
  double getSide() const { return length; }
  Vect3D normal(Point3D surface_pt) const;
  Vect3D tangent(Point3D surface_pt) const;
};

class Sphere : public Object {
  // The length here corresponds to the radius
public:
  Sphere();
  Sphere(Point3D origin, double radius);
  Sphere(const Sphere &sphere);

  double area(void) const { return 4 * pi * length * length * length / 3; }
  double volume(void) const { return 4 * pi * length * length; }
  double getRadius() const { return length; }
  Vect3D normal(Point3D surface_pt) const;
  Vect3D tangent(Point3D surface_pt) const;
};

class Plane : public Object {
  // The length corresponds to the radius
private:
  Vect3D vectx; // Which length = length
  double width;
  Vect3D vecty; // Which length = width

public:
  Plane();
  Plane(Point3D origin, double length, double width, Vect3D vectx,
        Vect3D vecty);
  Plane(const Plane &plane);

  double area(void) const { return length * width; }
  double volume(void) const { return 0; }
  double getLength() const { return length; }
  double getWidth() const { return width; }
  Vect3D normal(Point3D surface_pt) const;
  Vect3D tangent(Point3D surface_pt) const;
};
/* TO DO :
[DONE] Create an abstract base class and then create objects that can be added
to the scene (sphere, plan, cube...)

Each object can have the possibility to emit light.

Add texture to each object
*/