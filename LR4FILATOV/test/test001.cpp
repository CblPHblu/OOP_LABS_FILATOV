#include <gtest/gtest.h>
#include "../src/Figure_array.h"

TEST(test_1, create_square) {
    Square<double> square1;
    ASSERT_TRUE(square1.is_correct());
}

TEST(test_2, create_rectangle) {
    Rectangle<double> rect1;
    ASSERT_TRUE(rect1.is_correct());
}

TEST(test_3, create_trapezoid) {
    Trapezoid<double> trap1;
    ASSERT_TRUE(trap1.is_correct());
}

TEST(test_4, create_square_with_points) {
    Point<double> p1(1, 1), p2(3, 1), p3(3, 3), p4(1, 3);
    Square<double> square2(p1, p2, p3, p4);
    ASSERT_TRUE(square2.is_correct());
}

TEST(test_5, create_rectangle_with_points) {
    Point<double> p1(1, 1), p2(3, 1), p3(3, 5), p4(1, 5);
    Rectangle<double> rect2(p1, p2, p3, p4);
    ASSERT_TRUE(rect2.is_correct());
}

TEST(test_6, create_trapezoid_with_points) {
    Point<double> p1(2, 2), p2(3, 2), p3(4, 1), p4(1, 1);
    Trapezoid<double> trap2(p1, p2, p3, p4);
    ASSERT_TRUE(trap2.is_correct());
}

TEST(test_7, create_bad_square_with_points) {
    Point<double> p1(1, 0), p2(2, 4), p3(3, 14), p4(1, 12);
    bool check = true;
    try {
        Square<double> square3(p1, p2, p3, p4);
    }
    catch (std::exception &ex)  {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_8, create_bad_rectangle_with_points) {
    Point<double> p1(0, 0), p2(0, 0), p3(0, 0), p4(1, 1);
    bool check = true;
    try {
        Rectangle<double> rect3(p1, p2, p3, p4);
    }
    catch (std::exception &ex)  {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_9, create_bad_trapezoid_with_points) {
    Point<double> p1(0, 0), p2(2, 2), p3(0, 0), p4(1, 1);
    bool check = true;
    try {
        Trapezoid<double> trap3(p1, p2, p3, p4);
    }
    catch (std::exception &ex)  {
        check = false;
    }
    ASSERT_FALSE(check);
}

TEST(test_10, find_square_center) {
    Point<double> p1(1, 3), p2(3, 3), p3(3, 1), p4(1, 1);
    Square<double> square(p1, p2, p3, p4);
    Point<double> center = square.center();
    Point<double> exp_center(2, 2);
    ASSERT_TRUE(center.Is_Equal(exp_center));
}

TEST(test_11, find_rectangle_center) {
    Point<double> p1(1, 1), p2(1, 3), p3(5, 3), p4(5, 1);
    Rectangle<double> rect(p1, p2, p3, p4);
    Point<double> center = rect.center();
    Point<double> exp_center(3, 2);
    ASSERT_TRUE(center.Is_Equal(exp_center));
}

TEST(test_12, find_trapezoid_center) {
    Point<double> p1(1, 1), p2(2, 3), p3(4, 3), p4(5, 1);
    Trapezoid<double> trap(p1, p2, p3, p4);
    Point<double> center = trap.center();
    Point<double> exp_center(3, 2);
    ASSERT_TRUE(center.Is_Equal(exp_center));
}

TEST(test_13, find_square_area) {
    Point<double> p1(1, 3), p2(3, 3), p3(3, 1), p4(1, 1);
    Square<double> square(p1, p2, p3, p4);
    double area = square.getArea();
    double exp_area = 4.0;
    ASSERT_TRUE(area == exp_area);
}

TEST(test_14, find_rectangle_area) {
    Point<double> p1(1, 1), p2(1, 3), p3(5, 3), p4(5, 1);
    Rectangle<double> rect(p1, p2, p3, p4);
    double area = rect.getArea();
    double exp_area = 8.0;
    ASSERT_TRUE(area == exp_area);
}

TEST(test_15, find_trapezoid_area) {
    Point<double> p1(2, 3), p2(4, 3), p3(5, 1), p4(1, 1);
    Trapezoid<double> trap(p1, p2, p3, p4);
    double area = trap.getArea();
    double exp_area = 6.0;
    ASSERT_TRUE(area == exp_area);
}

TEST(test_16, copy_operator_shared_ptr_square) {
    Point<double> s1(1, 3), s2(3, 3), s3(3, 1), s4(1, 1);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Square<double>>(s1, s2, s3, s4));
    std::shared_ptr<Figure<double>> arr_new;
    arr_new = arr;
    ASSERT_TRUE(arr_new.get()->getArea() == 4);
}

TEST(test_17, copy_operator_shared_ptr_rectangle) {
    Point<double> r1(1, 4), r2(6, 4), r3(6, 1), r4(1, 1);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Rectangle<double>>(r1, r2, r3, r4));
    std::shared_ptr<Figure<double>> arr_new;
    arr_new = arr;
    ASSERT_TRUE(arr_new.get()->getArea() == 15);
}

TEST(test_18, copy_operator_shared_ptr_trapezoid) {
    Point<double> t1(3, 4), t2(6, 4), t3(8, 1), t4(1, 1);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Trapezoid<double>>(t1, t2, t3, t4));
    std::shared_ptr<Figure<double>> arr_new;
    arr_new = arr;
    ASSERT_TRUE(arr_new.get()->getArea() == 15);
}

TEST(test_19, move_operator_shared_ptr_square) {
    Point<double> s1(1, 3), s2(3, 3), s3(3, 1), s4(1, 1);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Square<double>>(s1, s2, s3, s4));
    std::shared_ptr<Figure<double>> arr_new;
    arr_new = std::move(arr);
    ASSERT_TRUE(arr_new.get()->getArea() == 4);
}

TEST(test_20, move_operator_shared_ptr_rectangle) {
    Point<double> r1(1, 4), r2(6, 4), r3(6, 1), r4(1, 1);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Rectangle<double>>(r1, r2, r3, r4));
    std::shared_ptr<Figure<double>> arr_new;
    arr_new = std::move(arr);
    ASSERT_TRUE(arr_new.get()->getArea() == 15);
}

TEST(test_21, move_operator_shared_ptr_trapezoid) {
    Point<double> t1(3, 4), t2(6, 4), t3(8, 1), t4(1, 1);
    std::shared_ptr<Figure<double>> arr(std::make_shared<Trapezoid<double>>(t1, t2, t3, t4));
    std::shared_ptr<Figure<double>> arr_new;
    arr_new = std::move(arr);
    ASSERT_TRUE(arr_new.get()->getArea() == 15);
}

TEST(test_22, creating_figure_array) {
    Point<double> s1(1, 3), s2(3, 3), s3(3, 1), s4(1, 1);
    Point<double> r1(1, 4), r2(6, 4), r3(6, 1), r4(1, 1);
    Point<double> t1(3, 4), t2(6, 4), t3(8, 1), t4(1, 1);
    Array<std::shared_ptr<Figure<double>>> mega_arr{
                        std::make_shared<Square<double>>(s1, s2, s3, s4),
                        std::make_shared<Rectangle<double>>(r1, r2, r3, r4),
                        std::make_shared<Trapezoid<double>>(t1, t2, t3, t4)
                        };
    ASSERT_TRUE(mega_arr.arr_size() == 3);
}

TEST(test_23, finding_square_center_and_area_from_figure_array) {
    Point<double> s1(1, 3), s2(3, 3), s3(3, 1), s4(1, 1);
    Point<double> r1(1, 4), r2(6, 4), r3(6, 1), r4(1, 1);
    Point<double> t1(3, 4), t2(6, 4), t3(8, 1), t4(1, 1);
    Array<std::shared_ptr<Figure<double>>> mega_arr{
                        std::make_shared<Square<double>>(s1, s2, s3, s4),
                        std::make_shared<Rectangle<double>>(r1, r2, r3, r4),
                        std::make_shared<Trapezoid<double>>(t1, t2, t3, t4)
                        };
    Point<double> center(2, 2);
    ASSERT_TRUE(mega_arr[0].get()->center().Is_Equal(center) && mega_arr[0].get()->getArea() == 4);
}

TEST(test_26, finding_area_sum) {
    Point<double> s1(1, 3), s2(3, 3), s3(3, 1), s4(1, 1);
    Point<double> r1(1, 4), r2(6, 4), r3(6, 1), r4(1, 1);
    Point<double> t1(3, 4), t2(6, 4), t3(8, 1), t4(1, 1);
    Array<std::shared_ptr<Figure<double>>> mega_arr{
                        std::make_shared<Square<double>>(s1, s2, s3, s4),
                        std::make_shared<Rectangle<double>>(r1, r2, r3, r4),
                        std::make_shared<Trapezoid<double>>(t1, t2, t3, t4)
                        };
    double expect_sum_area = 34;
    ASSERT_TRUE(mega_arr.sum_area() == expect_sum_area);
}

TEST(test_27, removing_figure_from_figure_array) {
    Point<double> s1(1, 3), s2(3, 3), s3(3, 1), s4(1, 1);
    Point<double> r1(1, 4), r2(6, 4), r3(6, 1), r4(1, 1);
    Point<double> t1(3, 4), t2(6, 4), t3(8, 1), t4(1, 1);
    Array<std::shared_ptr<Figure<double>>> mega_arr{
                        std::make_shared<Square<double>>(s1, s2, s3, s4),
                        std::make_shared<Rectangle<double>>(r1, r2, r3, r4),
                        std::make_shared<Trapezoid<double>>(t1, t2, t3, t4)
                        };
    mega_arr.remove(0);
    ASSERT_TRUE(mega_arr.arr_size() == 2);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}