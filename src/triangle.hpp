#include "shape.hpp"

// class Triangle
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Triangle : public Shape {
public: 
    Triangle(Point center, std::string name, int base, int height);

    double area() const override;
    void draw(std::ostream& out) const override;
    Triangle* clone() const override;
protected:
    Triangle(const Triangle& other) = default;
private:
    int base;
    int height;
};

#endif