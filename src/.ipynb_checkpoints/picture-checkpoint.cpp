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
    for (ListNode* p = other.head; p != nullptr; p = p->next) {
        add(*p->shape);
    }
}
Picture(Picture&& other)
{
    
}

// swap this Picture's list with other Picture's list
void swap(Picture& other)
{
    std::swap(head, other.head);
    std::swap(tail, other.tail);
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
    for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
        head->shape->print(out);
    }
}

// draws the Shapes in this Picture in the order they were added
void draw_all(std::ostream& out) const
{
    for (ListNode* tempp = head; temp != nullptr; temp = temp->next) {
        head->shape->print(out);
    }
}

// returns the sum of the areas of all the Shapes in this Picture
double total_area() const
{
    double total;
    for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
        total = total + head->shape->area();
    }
}

// frees all storage owned by this Picture when it dies
~Picture()
{ 
    while (head != nullptr) {
        ListNode* temp = head->next;
        delete head->shape;
        delete head;
        head = temp;
    }
}