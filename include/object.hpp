#pragma once
#include "image.hpp"
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
    /* If the ray hit the object, record data  */
    virtual bool intersect(Ray&, hit_record&) const = 0;
  };
  /*
   * Object abstract class
   */
  class Object {
  protected:
    Point3D origin;

  public:
    virtual Vect3D normal(Point3D surface_pt)
        const = 0; // weird for camera for example... useful ?
    virtual Vect3D tangent(Point3D surface_pt)
        const = 0; // weird for camera for example... useful ?
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
  class Cube : public Object, public Hittable {
  private:
    // 3 base vectors
    Vect3D vectx;
    Vect3D vecty;
    Vect3D vectz;
    double side;

  public:
    Cube();
    Cube(double side);
    Cube(Point3D origin, double side, Vect3D vectx, Vect3D vecty, Vect3D vectz);
    Cube(const Cube& cube);

    Vect3D normal(Point3D surface_pt) const override;
    Vect3D tangent(Point3D surface_pt) const override;
    bool intersect(Ray&, hit_record&) const override;
  };

  /*
   * Sphere object
   */
  class Sphere : public Object, public Hittable {
  private:
    double radius;

  public:
    Sphere();
    Sphere(Point3D origin, double radius);
    Sphere(const Sphere& sphere);

    Vect3D normal(Point3D surface_pt) const override;
    Vect3D tangent(Point3D surface_pt) const override;
    bool intersect(Ray&, hit_record&) const override;
  };

  /*
   * plane object
   */
  class Plane : public Object, public Hittable {
  private:
    Vect3D vectx; // width
    Vect3D vecty; // height

  public:
    Plane();
    Plane(Point3D origin, Vect3D vectx, Vect3D vecty);
    Plane(const Plane& plane);

    double getWidth() const;
    double getHeight() const;

    Vect3D normal(Point3D surface_pt) const override;
    Vect3D tangent(Point3D surface_pt) const override;
    bool intersect(Ray&, hit_record&) const override;
  };

  class Camera {
  private:
    screenSize size;
    size_t focal_length;
    Point3D origin;

  public:
    Camera();
    Camera(size_t height,
           size_t width,
           size_t focal_length,
           Point3D origin = Point3D(0, 0, 0));
    Camera(screenSize size,
           size_t focal_length,
           Point3D origin = Point3D(0, 0, 0));
    Camera(const Camera& cam);

    Vect3D get_horizontal() const { return Vect3D(size.width, 0, 0); };
    Vect3D get_vertical() const { return Vect3D(0, size.height, 0); };
    Point3D get_origin() const { return origin; };
    size_t get_focal_length() const { return focal_length; };
    screenSize get_size() const { return size; };
    Point3D get_llc() const; /* llc : lower left corner */
  };

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