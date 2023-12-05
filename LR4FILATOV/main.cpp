#include "src/Figure_array.h"

int main() {
    std::cout << "Создадим фигурки:\n" << std::endl;

    std::cout << "Квадратик\n" << std::endl;
    Point<double> s1(1, 4), s2(4, 4), s3(4, 1), s4(1, 1);
    std::shared_ptr<Figure<double>> arr1(std::make_shared<Square<double>>(s1, s2, s3, s4));
    std::cout << *arr1 << std::endl;
    Point<double> c1 = arr1.get()->center();
    std::cout << "Ну ка, центр квадрата: " << c1 << std::endl;
    std::cout << std::endl; 

    std::cout << "Прямоугольничек\n" << std::endl;
    Point<double> r1(1, 4), r2(6, 4), r3(6, 1), r4(1, 1);
    std::shared_ptr<Figure<double>> arr2(std::make_shared<Rectangle<double>>(r1, r2, r3, r4));
    std::cout << *arr2 << std::endl;
    Point<double> c2 = arr2.get()->center();
    std::cout << "Ну ка, центр прямоугольника: " << c2 << std::endl;
    std::cout << std::endl;

    std::cout << "Трапечка\n" << std::endl;
    Point<double> t1(3, 4), t2(6, 4), t3(8, 1), t4(1, 1);
    std::shared_ptr<Figure<double>> arr3(std::make_shared<Trapezoid<double>>(t1, t2, t3, t4));
    std::cout << *arr3 << std::endl;
    Point<double> c3 = arr3.get()->center();
    std::cout << "Ну ка, центр трапеции: " << c3 << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "А засунем-ка всё в коробку!\n" << std::endl;
    Array<std::shared_ptr<Figure<double>>> mega_arr{
                            std::make_shared<Square<double>>(s1, s2, s3, s4),
                            std::make_shared<Rectangle<double>>(r1, r2, r3, r4),
                            std::make_shared<Trapezoid<double>>(t1, t2, t3, t4)
                            };

    for (int i = 0; i < mega_arr.arr_size(); i++) {
        std::cout << *mega_arr[i] << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Коробка-коробка, покажи мне площадь каждой фигурки: \n" << std::endl;
    for (int i = 0; i < mega_arr.arr_size(); i++) {
        std::cout << mega_arr[i].get()->getArea() << std::endl << std::endl;
    }

    std::cout << "Коробка-коробка, посчитай-ка всю-всю площадь: \n" << std::endl;
    double sum = mega_arr.sum_area();
    std::cout << sum << std::endl;

    std::cout << std::endl;
    std::cout << "Не, прямоугольничекчек у вас ерунда, удали-ка его: \n" << std::endl;
    mega_arr.remove(1);
    
    std::cout << "Коли точно удалил, докажите, будьте мил: " << mega_arr.arr_size() << std::endl;
    std::cout << "Что осталось в коробке? Покажи скорее мне!!!\n" << std::endl;
    for (int i = 0; i < mega_arr.arr_size(); i++) {
        std::cout << *mega_arr[i] << std::endl;
    }

    std::cout << "Вот и с лабою конец, те кто слушал - молодец :))\n" << std::endl;
    
    return 0;
}