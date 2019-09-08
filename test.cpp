#include <stdio.h>

#include <iostream>
#include "vec2d.h"
int main(){
    
    Vec2d a = Vec2d(1.0f, 0.0f);
    Vec2d b = Vec2d(2.0f, 2.0f);

    Vec2d c = a;
          c += b;
          c *= Vec2d(2.0);

    Vec2d d = Vec2d(0.0f, 3.0f);

    float dotValue = a.dot(d);
    float angleValue = a.angleBetween(d);

    
    a.print("a: ");
    b.print("b: ");
    c.print("c: ");
    d.print("d: ");
    
    std::cout << "dot product between (a) and (d)\t"<<dotValue   <<std::endl;
    std::cout << "Angle between (a) and (d)\t"      <<angleValue <<std::endl;
    std::cout << "(d) is equal to (a)? \t"          <<d.equals(a)<<std::endl;


    a.lerp(d,0.5f);
    a.print("New a: ");
    d.set(a.getX(),a.getY());
    std::cout << "Now (d) is equal to (a)? \t"          <<d.equals(a)<<std::endl;
    return 0;
}