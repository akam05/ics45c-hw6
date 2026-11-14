#include "picture.hpp"
#include <iostream>
#include <utility>

// initializing constructor creates this as an empty picture
Picture::Picture() : head(nullptr), tail(nullptr)
{
}

// copy and move constructors for Picture (good C++ practice)
Picture(const Picture& other) : Picture()
{
    for (ListNode* p = other.head; p != nullptr; p = p->next)
        {
            
}
Picture(Picture&& other)
{
}

// swap this Picture's list with other Picture's list
void swap(Picture& other)
{
}

// copy and move assignment for Picture (good C++ practice)
Picture& operator=(const Picture& other)
{
}
Picture& operator=(Picture&& other)
{
}

// adds a clone of shape to the end of this Picture's linked list.
// Cloning allows us to create any number of shape objects at runtime,
// while Picture can own the newly created shape objects contained within
// it. Note this means Picture is responsible for deleting these clones
// when this Picture object dies.
void add(const Shape& shape)
{
    ListNode* node = new ListNode{shape.clone(), nullptr};
    if (head == nullptr)
    {
        head = node;
    } else {
        tail->next = node;
    }
    tail = node;
}

// calls method print() on each shape in the order they were added
void print_all(std::ostream& out) const
{
}

// draws the Shapes in this Picture in the order they were added
void draw_all(std::ostream& out) const
{
}

// returns the sum of the areas of all the Shapes in this Picture
double total_area() const
{
}

// frees all storage owned by this Picture when it dies
~Picture()
{
}