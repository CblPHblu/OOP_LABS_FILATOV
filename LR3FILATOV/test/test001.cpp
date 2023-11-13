#include <gtest/gtest.h>
#include "../include/Figure_array.h"

TEST(test_1, create_square) {
    Square square1;
    ASSERT_TRUE(square1.is_correct());
}

TEST(test_2, create_rectangle) {
    Rectangle rect1;
    ASSERT_TRUE(rect1.is_correct());
}

TEST(test_3, create_trapezoid) {
    Trapezoid trap1;
    ASSERT_TRUE(trap1.is_correct());
}

TEST(test_4, create_square_with_points) {
    Point p1(1, 1), p2(3, 1), p3(3, 3), p4(1, 3);
    Square square2(p1, p2, p3, p4);
    ASSERT_TRUE(square2.is_correct());
}

TEST(test_5, create_rectangle_with_points) {
    Point p1(1, 1), p2(3, 1), p3(3, 5), p4(1, 5);
    Rectangle rect2(p1, p2, p3, p4);
    ASSERT_TRUE(rect2.is_correct());
}

TEST(test_6, create_trapezoid_with_points) {
    Point p1(2, 2), p2(3, 2), p3(4, 1), p4(1, 1);
    Trapezoid trap2(p1, p2, p3, p4);
    ASSERT_TRUE(trap2.is_correct());
}

TEST(test_7, create_bad_square_with_points) {
    Point p1(1, 0), p2(2, 4), p3(3, 14), p4(1, 12);
    bool check = true;
    try {
        Square square3(p1, p2, p3, p4);
    }
    catch (std::exception &ex)  {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_8, create_bad_rectangle_with_points) {
    Point p1(0, 0), p2(0, 0), p3(0, 0), p4(1, 1);
    bool check = true;
    try {
        Rectangle rect3(p1, p2, p3, p4);
    }
    catch (std::exception &ex)  {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_9, create_bad_trapezoid_with_points) {
    Point p1(0, 0), p2(2, 2), p3(0, 0), p4(1, 1);
    bool check = true;
    try {
        Trapezoid trap3(p1, p2, p3, p4);
    }
    catch (std::exception &ex)  {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_10, find_square_center) {
    Point p1(1, 3), p2(3, 3), p3(3, 1), p4(1, 1);
    Square square(p1, p2, p3, p4);
    Point center = square.center();
    Point exp_center(2, 2);
    ASSERT_TRUE(center.Is_Equal(exp_center));
}

TEST(test_11, find_rectangle_center) {
    Point p1(1, 1), p2(1, 3), p3(5, 3), p4(5, 1);
    Rectangle rect(p1, p2, p3, p4);
    Point center = rect.center();
    Point exp_center(3, 2);
    ASSERT_TRUE(center.Is_Equal(exp_center));
}

TEST(test_12, find_trapezoid_center) {
    Point p1(1, 1), p2(2, 3), p3(4, 3), p4(5, 1);
    Trapezoid trap(p1, p2, p3, p4);
    Point center = trap.center();
    Point exp_center(3, 2);
    ASSERT_TRUE(center.Is_Equal(exp_center));
}

TEST(test_13, find_square_area) {
    Point p1(1, 3), p2(3, 3), p3(3, 1), p4(1, 1);
    Square square(p1, p2, p3, p4);
    double area = square.getArea();
    double exp_area = 4.0;
    ASSERT_TRUE(area == exp_area);
}

TEST(test_14, find_rectangle_area) {
    Point p1(1, 1), p2(1, 3), p3(5, 3), p4(5, 1);
    Rectangle rect(p1, p2, p3, p4);
    double area = rect.getArea();
    double exp_area = 8.0;
    ASSERT_TRUE(area == exp_area);
}

TEST(test_15, find_trapezoid_area) {
    Point p1(2, 3), p2(4, 3), p3(5, 1), p4(1, 1);
    Trapezoid trap(p1, p2, p3, p4);
    double area = trap.getArea();
    double exp_area = 6.0;
    ASSERT_TRUE(area == exp_area);
}

TEST(test_16, copy_operator_square) {
    Point p1(1, 3), p2(3, 3), p3(3, 1), p4(1, 1);
    Square square1(p1, p2, p3, p4);
    Square square2;
    square2 = square1;
    ASSERT_TRUE(square1 == square2);
}

TEST(test_17, move_operator_square) {
    Point p1(1, 3), p2(3, 3), p3(3, 1), p4(1, 1);
    Square square1(p1, p2, p3, p4);
    Square square2;
    square2 = std::move(square1);
    ASSERT_TRUE((square1 == square2) and (square1.center().Is_Equal(square2.center())) and (square1.getArea() == square2.getArea()));
}

TEST(test_18, copy_operator_rectangle) {
    Point p1(1, 1), p2(1, 3), p3(5, 3), p4(5, 1);
    Rectangle rect1(p1, p2, p3, p4);
    Rectangle rect2;
    rect2 = rect1;
    ASSERT_TRUE(rect1 == rect2);
}

TEST(test_19, move_operator_rectangle) {
    Point p1(1, 1), p2(1, 3), p3(5, 3), p4(5, 1);
    Rectangle rect1(p1, p2, p3, p4);
    Rectangle rect2;
    rect2 = std::move(rect1);
    ASSERT_TRUE(rect1 == rect2);
}

TEST(test_20, copy_operator_trapezoid) {
    Point p1(2, 3), p2(4, 3), p3(5, 1), p4(1, 1);
    Trapezoid trap1(p1, p2, p3, p4);
    Trapezoid trap2;
    trap2 = trap1;
    ASSERT_TRUE((trap1 == trap2));
}

TEST(test_21, move_operator_trapezoid) {
    Point p1(2, 3), p2(4, 3), p3(5, 1), p4(1, 1);
    Trapezoid trap1(p1, p2, p3, p4);
    Trapezoid trap2;
    trap2 = std::move(trap1);
    ASSERT_TRUE((trap1 == trap2));
}

TEST(test_22, Figure_array_add) {
    Point p1(1, 3), p2(3, 3), p3(3, 1), p4(1, 1);
    Square square1(p1, p2, p3, p4);

    Point r1(1, 1), r2(1, 3), r3(5, 3), r4(5, 1);
    Rectangle rect1(r1, r2, r3, r4);

    Point t1(2, 3), t2(4, 3), t3(5, 1), t4(1, 1);
    Trapezoid trap1(t1, t2, t3, t4);

    Farray *far = create_arr();
    add_figure(far, square1);
    add_figure(far, rect1);
    add_figure(far, trap1);
    ASSERT_TRUE(far->size == 3);
}

TEST(test_23, Figure_array_sum_area) {
    Point p1(1, 3), p2(3, 3), p3(3, 1), p4(1, 1);
    Square square1(p1, p2, p3, p4);

    Point r1(1, 1), r2(1, 3), r3(5, 3), r4(5, 1);
    Rectangle rect1(r1, r2, r3, r4);

    Point t1(2, 3), t2(4, 3), t3(5, 1), t4(1, 1);
    Trapezoid trap1(t1, t2, t3, t4);

    Farray *far = create_arr();
    add_figure(far, square1);
    add_figure(far, rect1);
    add_figure(far, trap1);
    ASSERT_TRUE(sum_area(far) == 18);
}

TEST(test_24, Figure_array_rm_figure) {
    Point p1(1, 3), p2(3, 3), p3(3, 1), p4(1, 1);
    Square square1(p1, p2, p3, p4);

    Point r1(1, 1), r2(1, 3), r3(5, 3), r4(5, 1);
    Rectangle rect1(r1, r2, r3, r4);

    Point t1(2, 3), t2(4, 3), t3(5, 1), t4(1, 1);
    Trapezoid trap1(t1, t2, t3, t4);

    Farray *far = create_arr();
    add_figure(far, square1);
    add_figure(far, rect1);
    add_figure(far, trap1);
    far->arr = rm_figure(far, 0);
    far->size--;
    ASSERT_TRUE(far->size == 2);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}