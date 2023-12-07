#ifndef GRAPHPOLY_H_
#define GRAPHPOLY_H_
#include <cmath>
static const double PI = 3.1415926;
class GraphicsBase {
public:
    virtual const char* shapeName() = 0;
    virtual ~GraphicsBase() {}
};
class PlaneGraphic : public GraphicsBase {
public:
    PlaneGraphic() = default;
    // 计算各自面积, 周长
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    ~PlaneGraphic() override { }
};
class SolidGraphic : public GraphicsBase {
public:
    SolidGraphic() = default;
    // 计算表面积、体积
    virtual double getSuperficalArea() const = 0;
    virtual double getVolume() const = 0;
    ~SolidGraphic() override {}
};
class Square : public PlaneGraphic {
public:
    Square() = default;
    Square(double i) : side(i) { }
    double getArea() const override { return side * side; }
    double getPerimeter() const override { return 4 * side; }
    const char* shapeName() override { return "Square"; }
    ~Square() { }
private:
    double side;
};
class Circle : public PlaneGraphic {
public:
    Circle() = default;
    Circle(double r) : radius(r) { }
    double getArea() const override { return PI * radius * radius; }
    double getPerimeter() const override { return 2 * PI * radius; }
    const char* shapeName() override { return "Circle"; }
    ~Circle() override { }
private:
    double radius;
};
class CircleCone : public SolidGraphic {
public:
    CircleCone() = default;
    CircleCone(double h, double r) : height(h), radius(r) { }
    double getSuperficalArea() const override;
    double getVolume() const override { return PI * pow(radius, 2) * height / 3;}
    const char* shapeName() override { return "CircleCone"; }
    ~CircleCone() { } 
private:
    double height;
    double radius;
};
class Sphere : public SolidGraphic {
public:
    Sphere() = default;
    Sphere(double r) : radius(r) { }
    double getSuperficalArea() const override { return 4 * PI * pow(radius, 2); }
    double getVolume() const override { return PI * pow(radius, 3); }
    const char* shapeName() override { return "Sphere"; }
    ~Sphere() { }
private:
    double radius;
};

double CircleCone::getSuperficalArea() const { 
    double basalArea = PI * radius * radius;
    double lateralArea;
    double motherLine = sqrt(pow(height, 2) + pow(radius, 2));
    lateralArea = PI * motherLine * radius;
    return lateralArea + basalArea;
}
//Square::getArea()
#endif