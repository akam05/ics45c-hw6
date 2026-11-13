#include "shape.hpp"

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
// class Rectangle

// class Circle 
class Circle : public Shape {
public: 
    Rectangle(Point center, std::string name, int width, int height);

    double area() const override;
    void draw(std::ostream& out) const override;
    Rectangle* clone() const override;
protected:
    Rectangle(const Circle& other) = default;
private:
    int width;
    int height;
};

#endif