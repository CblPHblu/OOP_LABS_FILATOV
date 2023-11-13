#include <iostream>
#include "include/Figure_array.h"

int main () {
    Farray *array = create_arr();

    std::cout << "Квадрат:" << std::endl;
    Point s1(1, 4), s2(4, 4), s3(4, 1), s4(1, 1);
    Square square1(s1, s2, s3, s4);
    if (square1.is_correct()) {
        add_figure(array, square1);
        std::cout << "Площадь: " << array->arr[0]->getArea() << std::endl;
        std::cout << "Текущая сумма площадей: " << sum_area(array) << std::endl;
        Point с(array->arr[0]->center());
        std::cout << "Центр квадрата: " << с << std::endl;
    }
    else {
        std::cout << "Некорректная фигура!" << std::endl;
        return 1;
    }
    std::cout << std::endl;

    std::cout << "Прямоугольник:" << std::endl;
    Point r1(1, 4), r2(6, 4), r3(6, 1), r4(1, 1);
    Rectangle rect1(r1, r2, r3, r4);
    if (rect1.is_correct()) {
        add_figure(array, rect1);
        std::cout << "Площадь: " << array->arr[1]->getArea() << std::endl;
        std::cout << "Текущая сумма площадей: " << sum_area(array) << std::endl;
        Point c_1(array->arr[1]->center());
        std::cout << "Центр прямоугольника: " << c_1 << std::endl;
    }
    else {
        std::cout << "Некорректная фигура!" << std::endl;
        return 1;
    }
    std::cout << std::endl;
    
    std::cout << "Трапеция:" << std::endl;
    Point t1(3, 4), t2(6, 4), t3(8, 1), t4(1, 1);
    Trapezoid trap1(t1, t2, t3, t4);
    if (trap1.is_correct()) {
        add_figure(array, trap1);
        std::cout << "Площадь: " << array->arr[2]->getArea() << std::endl;
        std::cout << "Текущая сумма площадей: " << sum_area(array) << std::endl;
        Point c_3(array->arr[2]->center());
        std::cout << "Центр трапеции: " << c_3 << std::endl;
    }
    else {
        std::cout << "Некорректная фигура!" << std::endl;
        return 1;
    }
    std::cout << std::endl;
    
    std::cout << "Фигуры в текущем массиве:" << std::endl;
    for (int i = 0; i < array->size; i++) {
        std::cout << array->arr[i] << std::endl;
    }
    
    //удаление 1-го элемента массива
    std::cout << "Массив после удаления 1-го элемента (квадрата):" << std::endl;
    array->arr = rm_figure(array, 0);
    array->size--;
    int s = array->size;
    for (int i = 0; i < s; i++) {
        std::cout << array->arr[i] << std::endl;
    }

    std::cout << "Текущая сумма площадей: " << sum_area(array) << std::endl;
    rm_arr(array);
}