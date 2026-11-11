#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include <string>

struct Point {
    int x;
    int y;
};

// class Shape 
class Shape {
public:
    // construct this Shape with given center and name
    Shape(Point center, std::string name);

    // prints this Shape's name, coordinates and area in this specific format,
    // followed by a newline (see the format note below)
    void print(std::ostream& out) const;

    // delete assignment to prevent accidental slicing
    Shape& operator=(const Shape& other) = delete;

    // computes and returns the area of this Shape
    virtual double area() const = 0;

    // draws this Shape using character graphics (algorithms given below)
    virtual void draw(std::ostream& out) const = 0;

    // create a new duplicate of this Shape allocated from the free store
    // must be overridden by each concrete class to return a copy of itself
    virtual Shape* clone() const = 0;

    // clean up any sub-storage owned by this Shape object
    virtual ~Shape() = default;

protected:
    // protect the copy constructor to be used only by clone()
    Shape(const Shape& other) = default;

private:
    // position coordinates, used to illustrate inheritance
    Point center;

    // the name of this shape (supplied to constructor)
    std::string name;
};

#endif