#include <iostream>
#include "./include/Money.h"

int main(){
    
    std::cout << "Initialize first string sum" << std::endl;
    Money M1("151,40");
    std::cout << "1 num:" << std::endl;
    M1.print(std::cout) << std::endl;

    std::cout << std:: endl;

    std::cout << "Initialize second string sum" << std::endl;
    Money M2("100,90");
    std::cout << "2 num:" << std::endl;
    M2.print(std::cout) << std::endl;

    std::cout << std::endl;

    std::cout << "Create object from add method" << std::endl;
    Money M3(M1.add(M2));
    std::cout << "1 num + 2 num:" << std::endl;
    M3.print(std::cout) << std::endl;

    std::cout << std::endl;

    std::cout << "Create object from remove method" << std::endl;
    Money M4(M1.remove(M2));
    std::cout << "1 num - 2 num:" << std::endl;
    M4.print(std::cout) << std::endl;

    std::cout << std::endl;

    std::cout << "Bool operations with 1 num and 2 num:" << std::endl;
    if (M1.is_equals(M2))
    {
        std::cout << "The fact that 1 num is equals to 2 num is true" << std::endl;
    }
    else {
        std::cout << "The fact that 1 num is equals to 2 num is false" << std::endl;
    }
    if (M1.is_larger(M2))
    {
        std::cout << "The fact that 1 num is larger than 2 num is true" << std::endl;
    }
    else {
        std::cout << "The fact that 1 num is larger than 2 num is false" << std::endl;
    }
    if (M1.is_smaller(M2))
    {
        std::cout << "The fact that 1 num is smaller than 2 num is true" << std::endl;
    }
    else {
        std::cout << "The fact that 1 num is smaller than 2 num is false" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Initialize 5 num with copying constructor" << std::endl;
    Money M5(M3);
    std::cout << "5 num:" << std::endl;
    M5.print(std::cout) << std::endl;

    std::cout << std::endl;

    std::cout << "Initialize 6 num with moving constructor" << std::endl;
    Money M6(std::move(M2));
    std::cout << "6 num:" << std::endl;
    M6.print(std::cout) << std::endl;

    std::cout << std::endl;

    std::cout << "Confirm that moving constructor works correctly" << std::endl;
    try{
        M2.print(std::cout) << std::endl;
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }

}