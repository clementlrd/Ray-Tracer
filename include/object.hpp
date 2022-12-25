#pragma once
#include "maths.hpp"
#include "ray.hpp"

#include <memory>

using maths::Point3D;
using maths::Vect3D;

namespace obj {

  /* struct for recording ray hit informations */
  struct hit_record {
    Point3D p; /* hitting point */
    Vect3D n;  /* normal vector at hit point */
    double t;  /* ray time at hit */
  };

  /*
   * Hittable virtual class to apply to objects
   */
  class Hittable {
  public:
    /* return intersection point  */
    virtual bool intersect(Ray, hit_record&)  = 0;
    virtual bool intersect(Ray&, hit_record&) = 0;
  };
  /*
   * Object abstract class
   */
  class Object {
  protected:
    Point3D origin;

  public:
    virtual Vect3D normal(Point3D surface_pt) const  = 0;
    virtual Vect3D tangent(Point3D surface_pt) const = 0;
  };

  /* TODO :
   * Each object can have the possibility to emit light.
   * Add texture to each object
   */
  /*
   * Cube object
   *
   * TODO : rename class
   */
  class Cube : public Object {
  private:
    // 3 base vectors
    Vect3D vectx;
    Vect3D vecty;
    Vect3D vectz;
    double side;

  public:
    Cube();
    Cube(double side);
    Cube(double origin, Vect3D vectx, Vect3D vecty, Vect3D vectz);
    Cube(const Cube& cube);

    Vect3D normal(Point3D surface_pt) const;
    Vect3D tangent(Point3D surface_pt) const;
  };

  /*
   * Sphere object
   */
  class Sphere : public Object {
  private:
    double radius;

  public:
    Sphere();
    Sphere(Point3D origin, double radius);
    Sphere(const Sphere& sphere);

    Vect3D normal(Point3D surface_pt) const;
    Vect3D tangent(Point3D surface_pt) const;
  };

  /*
   * plane object
   */
  class Plane : public Object {
  private:
    Vect3D vectx; // width
    Vect3D vecty; // height

  public:
    Plane();
    Plane(Point3D origin, Vect3D vectx, Vect3D vecty);
    Plane(const Plane& plane);

    double getWidth() const;
    double getHeight() const;
    Vect3D normal(Point3D surface_pt) const;
    Vect3D tangent(Point3D surface_pt) const;
  };

  /*
   * TODO : Camera class
   * implement a camera to create image for render
   */
  class Camera {};

  /*
   * TODO : Scene
   *
   * Scene is a collection of objects
   */
  class Scene {
  protected:
    Camera camera;
    int n; /* size of objects list */
    Object* objects[];

  public:
    Scene();
    Scene(Camera&);
    ~Scene(); // delete all objects

    /* check https://www.geeksforgeeks.org/ellipsis-in-c-with-examples/ */
    void add_objects(int nbr, ...);
    void add_objects_from_file(char* path); /* for textual scene repr */
  };
} // namespace obj