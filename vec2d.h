#ifndef VEC2D_H
#define VEC2D_H
#include <string>
#include <iostream>
struct Vec2dData{
    float x, y;
};


class Vec2d{
private:
    Vec2dData data;
public:

    void print(std::string str);
    void print();

    //Constructors
    Vec2d();
    Vec2d(float n);
    Vec2d(float  x, float y);
    Vec2d(Vec2dData a);

    //Setters
    void set(float x, float y);
    void set(float n);
    void setX(float x);
    void setY(float y);

    //Lerp
    void lerp(Vec2d b, float amount);
    void lerp(Vec2dData b, float amount);
    void lerp(float x, float y, float amount);
    void lerp(float n, float amount);
    //Getters
    float getX();
    float getY();
    Vec2dData getData();

    //Size of an vector or "magnitude"
    //sqMag returns the squared distance (x*x)+(y*y)
    //mag just made the square root of sqMag
    float sqMag(); 
    float mag();

    float dist(Vec2d b);

    //Operators
    void add(float n);
    void add(float x, float y);
    void add(Vec2d b);
    void add(Vec2dData b);

    void sub(float n);
    void sub(float x, float y);
    void sub(Vec2d b);
    void sub(Vec2dData b);

    void mult(Vec2d b);
    void mult(float factor);

    void div(Vec2d b);
    void div(float factor);

    Vec2d operator+(Vec2d const b);
    void operator+=(Vec2d const b);

    Vec2d operator-(Vec2d const b);
    void operator-=(Vec2d const b);

    Vec2d operator*(Vec2d const b);
    void operator*=(Vec2d const b);

    Vec2d operator/(Vec2d const b);
    void operator/=(Vec2d const b);

    //Checkers
    bool equals(float x, float y);
    bool equals(Vec2d b);
    bool equals(Vec2dData b);
    bool equals(float x, float y, double precision);
    bool equals(Vec2d b, double precision);
    bool equals(Vec2dData b, double precision);

    //Angle and rotations
    float heading();
    void rotate(float deltaTheta);

    float angleBetween(Vec2d b);
    float angleBetween(Vec2dData b);
    float angleBetween(float x, float y);

    float dot(Vec2d b);
    float dot(Vec2dData b);
    float dot(float x, float y);

    //Limiters
    void limit(float n);
    void normalize();
    
};
#endif
