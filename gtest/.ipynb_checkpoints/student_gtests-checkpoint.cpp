// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the shapes and Picture. It is graded: the autograder runs it
// against a correct implementation and against several with one bug each. A test is worth
// something only when it passes on the correct implementation and fails on a broken one, so a
// test that always fails (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for the areas, for print_all and draw_all,
// for total_area, and for copying a Picture.
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include "circle.hpp"
#include "picture.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "square.hpp"
#include "triangle.hpp"

TEST(ShapeTests, RectangleAreaIsWidthTimesHeight) {
    EXPECT_NEAR(Rectangle({0, 0}, "R", 7, 3).area(), 21.0, 0.001);
}

TEST(PictureTests, AnEmptyPictureHasNoArea) {
    const Picture p;
    EXPECT_DOUBLE_EQ(p.total_area(), 0.0);
}

// ADD YOUR TESTS HERE:
TEST(ShapeTests, AreaTests) {
    EXPECT_NEAR(Triangle({0, 0}, "T", 7, 3).area(), 10.5, 0.001);
    EXPECT_NEAR(Circle({0, 0}, "C", 5).area(), 78.539816, 0.001);
    EXPECT_NEAR(Square({0, 0}, "S", 3).area(), 9, 0.001);
}

TEST(PictureTests, TotalArea) {
    Picture p;
    Triangle t({0, 0}, "T", 7, 3);
    Circle c({0, 0}, "C", 5);
    Square s({0, 0}, "S", 3);
    p.add(t);
    p.add(c);
    p.add(s);
    EXPECT_NEAR(p.total_area(), 98.039816, 0.01);
}