#include <gtest/gtest.h>
#include "../include/Money.h"

TEST(test1, basic_test_set) {
    bool check1 = true;
    try{
        Money Empty_sum{""};
    }
    catch(std::exception &ex){
        check1 = false;
    }
    ASSERT_FALSE(check1);
}

TEST(test2, basic_test_set) {
    bool check2 = true;
    try{
        Money Low_amount{"1,2"};
    }
    catch(std::exception &ex){
        check2 = false;
    }
    ASSERT_FALSE(check2);
}

TEST(test3, basic_test_set) {
    bool check3 = true;
    try{
        Money Wrong_punctuation{"120,00000"};
    }
    catch(std::exception &ex){
        check3 = false;
    }
    ASSERT_FALSE(check3);
}

TEST(test4, basic_test_set) {
    bool check4 = true;
    try{
        Money Consist_letters1{"120,AA"};
    }
    catch(std::exception &ex){
        check4 = false;
    }
    ASSERT_FALSE(check4);
}

TEST(test5, basic_test_set) {
    bool check5 = true;
    try{
        Money Consist_letters2{"cd,00"};
    }
    catch(std::exception &ex){
        check5 = false;
    }
    ASSERT_FALSE(check5);
}

TEST(test6, basic_test_set) {
    bool check6 = true;
    try{
        Money No_punctuation{"10000"};
    }
    catch(std::exception &ex){
        check6 = false;
    }
    ASSERT_FALSE(check6);
}

TEST(test7, basic_test_set) {
    Money First_num1("100,50");
    Money Second_num1("50,90");
    Money Result1(First_num1.add(Second_num1));
    Money Expected1("151,40");
    ASSERT_TRUE(Expected1.is_equals(Result1));
}

TEST(test8, basic_test_set) {
    Money First_num2("200,33");
    Money Second_num2("0,11");
    Money Result2(First_num2.remove(Second_num2));
    Money Expected2("200,22");
    ASSERT_TRUE(Expected2.is_equals(Result2));
}

TEST(test9, basic_test_set) {
    bool check9 = true;
    Money First_num3("100,00");
    Money Second_num3("200,11");
    try {
        First_num3.remove(Second_num3);
    }
    catch (std::exception &ex) {
        check9 = false;
    }
    ASSERT_FALSE(check9);
}

TEST(test10, basic_test_set) {
    bool check10 = true;
    Money First_num3("100,00");
    Money Second_num3("100,11");
    try {
        First_num3.remove(Second_num3);
    }
    catch (std::exception &ex) {
        check10 = false;
    }
    ASSERT_FALSE(check10);
}

TEST(test13, basic_test_set) {
    bool check11 = false;
    Money First_num4("5,15");
    Money Second_num4("5,15");
    check11 = First_num4.is_equals(Second_num4);
    ASSERT_TRUE(check11);
}

TEST(test14, basic_test_set) {
    bool check12 = false;
    Money First_num5("100,50");
    Money Second_num5("40,12");
    check12 = First_num5.is_larger(Second_num5);
    ASSERT_TRUE(check12);
}

TEST(test15, basic_test_set) {
    bool check13 = false;
    Money First_num6("12,00");
    Money Second_num6("12,10");
    check13 = First_num6.is_larger(Second_num6);
    ASSERT_FALSE(check13);
}

TEST(test16, basic_test_set) {
    bool check14 = false;
    Money First_num7("10,00");
    Money Second_num7("10,00");
    check14 = First_num7.is_larger(Second_num7);
    ASSERT_FALSE(check14);
}

TEST(test17, basic_test_set) {
    bool check15 = false;
    Money First_num8("0,00");
    Money Second_num8("0,01");
    check15 = First_num8.is_smaller(Second_num8);
    ASSERT_TRUE(check15);
}

TEST(test18, basic_test_set) {
    bool check16 = false;
    Money First_num9("0,01");
    Money Second_num9("0,00");
    check16 = First_num9.is_smaller(Second_num9);
    ASSERT_FALSE(check16);
}

TEST(test19, basic_test_set) {
    bool check17 = false;
    Money First_num10("100000,00");
    Money Second_num10("100000,00");
    check17 = First_num10.is_smaller(Second_num10);
    ASSERT_FALSE(check17);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}