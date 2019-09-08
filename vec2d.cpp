#include "vec2d.h"
#include <math.h>
#include <iostream>
#include <string>

#define LERP(a, b, n) (1 - (n))* (a)+(n)*(b)
#define MAX(x,y) (x)>=(y)?(x):(y)
#define MIN(x,y) (x)<=(y)?(x):(y)
#define CLAMP(x, upper, lower) (MIN((upper), (MAX((x), (lower)))))

void Vec2d::print(std::string str){
    std::cout<<str<<"\t"<<"| x: "<<data.x<<"\ty: "<<data.y<<std::endl; 
}
void Vec2d::print(){
    std::cout<<"Vec2d: "<<"\t"<<"| x: "<<data.x<<"\ty: "<<data.y<<std::endl;
}
//Constructors
Vec2d::Vec2d(){
    set(0.0f, 0.0f);
}
Vec2d::Vec2d(float n){
    set(n);
}
Vec2d::Vec2d(float  x, float y){
    set(x, y);
}
Vec2d::Vec2d(Vec2dData a){
    set(a.x, a.y);
}

//Setters
void Vec2d::set(float x, float y){
    data.x = x;
    data.y = y;
}
void Vec2d::set(float n){
    data.x = n;
    data.y = n;
}
void Vec2d::setX(float x){
    data.x = x;
}
void Vec2d::setY(float y){
    data.y = y;
}
//Lerp
void Vec2d::lerp(Vec2d b, float amount){
    data.x += (b.getX() - data.x) * (amount);
    data.y += (b.getY() - data.y) * (amount);
}
void Vec2d::lerp(Vec2dData b, float amount){
    data.x += (b.x - data.x) * (amount);
    data.y += (b.y - data.y) * (amount);
}
void Vec2d::lerp(float x, float y, float amount){
    data.x += (x - data.x) * (amount);
    data.y += (y - data.y) * (amount);
}
void Vec2d::lerp(float n, float amount){
    data.x += (n - data.x) * (amount);
    data.y += (n - data.y) * (amount);
}
//Getters
float Vec2d::getX(){
    return data.x;
}
float Vec2d::getY(){
    return data.y;
}
Vec2dData Vec2d::getData(){
    return data;
}
//Size of an vector or "magnitude"
float Vec2d::sqMag(){
    return ((data.x * data.x)+(data.y*data.y));
}
float Vec2d::mag(){
    return sqrt(sqMag());
}
float Vec2d::dist(Vec2d b){
    return sqrt((b.getX()-data.x) * (b.getX()-data.x) +
                (b.getY()-data.y) * (b.getY()-data.y));
}

//Operators
void Vec2d::add(float n){
    data.x += n;
    data.y += n;
}
void Vec2d::add(float x, float y){
    data.x += x;
    data.y += y;
}
void Vec2d::add(Vec2d b){
    data.x += b.getX();
    data.y += b.getY();
}
void Vec2d::add(Vec2dData b){
    data.x += b.x;
    data.y += b.y;
}

void Vec2d::sub(float n){
    data.x -= n;
    data.y -= n;
}
void Vec2d::sub(float x, float y){
    data.x -= x;
    data.y -= y;
}
void Vec2d::sub(Vec2d b){
    data.x -= b.getX();
    data.y -= b.getY();
}
void Vec2d::sub(Vec2dData b){
    data.x -= b.x;
    data.y -= b.y;
}

void Vec2d::mult(Vec2d b){
    data.x *= b.getX();
    data.y *= b.getY();
}
void Vec2d::mult(float factor){
    data.x *= factor;
    data.y *= factor;
}

void Vec2d::div(Vec2d b){
    data.x /= b.getX();
    data.y /= b.getY();
}
void Vec2d::div(float factor){
    data.x /= factor;
    data.y /= factor;
}
//Operators overloaders
Vec2d Vec2d::operator+(Vec2d const b){
    Vec2d _this = Vec2d(data.x, data.y);
    _this.add(b);
    return _this;
}
void Vec2d::operator+=(Vec2d const b){
    add(b);
}

Vec2d Vec2d::operator-(Vec2d const b){
    Vec2d _this = Vec2d(data.x, data.y);
    _this.sub(b);
    return _this;
}
void Vec2d::operator-=(Vec2d const b){
    sub(b);
}

Vec2d Vec2d::operator*(Vec2d const b){
    Vec2d _this = Vec2d(data.x, data.y);
    _this.mult(b);
    return _this;
}
void Vec2d::operator*=(Vec2d const b){
    mult(b);
}

Vec2d Vec2d::operator/(Vec2d const b){
    Vec2d _this = Vec2d(data.x, data.y);
    _this.div(b);
    return _this;
}
void Vec2d::operator/=(Vec2d const b){
    div(b);
}
//Checkers
bool Vec2d::equals(float x, float y){
    return equals(x, y, 0.0000001);
}
bool Vec2d::equals(Vec2d b){
    return equals(b, 0.0000001);
}
bool Vec2d::equals(Vec2dData b){
    return equals(b, 0.0000001);
}
bool Vec2d::equals(float x, float y, double precision){
    return (abs(data.x - x) <= precision &&
            abs(data.y - y) <= precision);
}
bool Vec2d::equals(Vec2d b, double precision){
    return equals(b.getX(), b.getY(),precision);
}
bool Vec2d::equals(Vec2dData b, double precision){
    return equals(b.x, b.y,precision);
}

//Angle and rotations
float Vec2d::heading(){
    return atan2(data.y, data.x);
}
void Vec2d::rotate(float deltaTheta){
    float previousAngle = heading();
    float newAngle = previousAngle + deltaTheta;
    float len = mag();
    data.x = cos(newAngle)*len;
    data.y = sin(newAngle)*len;

    printf("%f\n",newAngle);
}
float Vec2d::dot(Vec2d b){
    return data.x*b.getX() + data.y*b.getY();
}
float Vec2d::dot(Vec2dData b){
    return data.x * b.x + data.y * b.y;
}
float Vec2d::dot(float x, float y){
    return data.x * x + data.y * y;
}

float Vec2d::angleBetween(Vec2d b){
    const float dotmagmag = dot(b) / (mag() * b.mag());

    return acos(CLAMP(dotmagmag, 1, -1));
}
float Vec2d::angleBetween(Vec2dData b){
    return angleBetween(Vec2d(b.x, b.y));
}
float Vec2d::angleBetween(float x, float y){
    return angleBetween(Vec2d(x,y));
}
//Limiters
void Vec2d::limit(float n){
    float len = sqMag();
    if(n * n > len ){
        //normalize
        mult( 1 / sqrt(len));
        //multiply for limit
        mult(n);
    }else{
        return;
    }
}
void Vec2d::normalize(){
    //if(equals(0.0f, 0.0f, 0.00000001)){return;}
    if(abs(data.x) < 0.000001 &&abs(data.y) < 0.000001){return; }
    float mg = mag();
    data.x /= mg;
    data.y /= mg;
}


