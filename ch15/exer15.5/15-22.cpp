#include <iostream>
#include "GraphPoly.h"

int main()
{
    Square square(10);
    std::cout << square.shapeName() << std::endl;
    std::cout << square.getArea() << ", " << square.getPerimeter() << std::endl;
    std::cout << std::endl;

    Circle circle(5);
    std::cout << circle.shapeName() << std::endl;
    std::cout << circle.getArea() << ", " << circle.getPerimeter() << std::endl;
    std::cout << std::endl;

    CircleCone cone(10, 5);
    std::cout << cone.shapeName() << std::endl;
    std::cout << cone.getSuperficalArea() << ", " << cone.getVolume() << std::endl;
    std::cout << std::endl;

    Sphere sphere(5);
    std::cout << sphere.shapeName() << std::endl;
    std::cout << sphere.getSuperficalArea() << ", " << sphere.getVolume() << std::endl;
    std::cout << std::endl;
    return 0;
}
