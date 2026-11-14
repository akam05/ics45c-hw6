#include "picture.hpp"
#include <iostream>
#include <utility>

// initializing constructor creates this as an empty picture
Picture::Picture() : head(nullptr), tail(nullptr)
{
}

// copy and move constructors for Picture (good C++ practice)
Picture::Picture(const Picture& other) : Picture()
{
    for (ListNode* p = other.head; p != nullptr; p = p->next) {
        add(*p->shape);
    }
}
Picture::Picture(Picture&& other) : Picture() // head(nullptr), tail(nullptr) - empty list
{
    swap(other);
}

// swap this Picture's list with other Picture's list
void Picture::swap(Picture& other)
{
    std::swap(head, other.head);
    std::swap(tail, other.tail);
}

// copy and move assignment for Picture (good C++ practice)
Picture& Picture::operator=(const Picture& other)
{
    if (this != & other)
    {
        Picture temp(other);
        swap(temp);
    }
    return *this;
}

Picture& Picture::operator=(Picture&& other)
{
    if (this != &other)
    {
        swap(other);
    }
    return *this;
}

// adds a clone of shape to the end of this Picture's linked list.
// Cloning allows us to create any number of shape objects at runtime,
// while Picture can own the newly created shape objects contained within
// it. Note this means Picture is responsible for deleting these clones
// when this Picture object dies.
void Picture::add(const Shape& shape)
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
void Picture::print_all(std::ostream& out) const
{
    for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
        temp->shape->print(out);
        temp->shape->draw(out);
    }
}

// draws the Shapes in this Picture in the order they were added
void Picture::draw_all(std::ostream& out) const
{
    for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
        temp->shape->draw(out);
    }
}

// returns the sum of the areas of all the Shapes in this Picture
double Picture::total_area() const
{
    double total = 0.0;
    for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
        total = total + temp->shape->area();
    }
    return total;
}

// frees all storage owned by this Picture when it dies
Picture::~Picture()
{ 
    while (head != nullptr) {
        ListNode* temp = head->next;
        delete head->shape;
        delete head;
        head = temp;
    }
}