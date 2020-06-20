#include <iostream>

#include "Complex.h"
#include "set.h"

int main() {

    //ЗАДАНИЕ 1
    std::cout << "\nЗадание 1" << std::endl;
    std::cout << "Вот сами числа a и b (сидели на трубе) ";
    Complex a = Complex(1, -1);
    Complex b = Complex(1.1, 1.1);
    a.Show();

    std::cout << "Умножение комплексного на нормальное ";
    (a * 10.1).Show();
    std::cout << "Сложение ";
    (a + b).Show();
    std::cout << "Умножение двух комплексных ";
    (a * b).Show();
    std::cout << "Длина ";
    std::cout << a.Length();

    std::cout << std::endl << std::endl;

    //ЗАДАНИЕ 7
    std::cout << "\nЗадание 7" << std::endl;
    Set s1;
    s1 += 2;
    s1 += 4;
    s1 += 6;
    std::cout << "Добавили элементы в множество ";
    s1.print();
    s1 -= 4;
    std::cout << "\nУдалили элемент из множества ";
    s1.print();
    Set s2;
    s2 += 2;
    s2 += 7;
    std::cout << "\nПервое множество ";
    s1.print();
    std::cout << "\nВторое множество ";
    s2.print();
    std::cout << std::endl;
    if (s1 == s2) {
        std::cout << "Множества 1 и 2 равны" << std::endl;
    } else {
        std::cout << "Множества 1 и 2 не равны" << std::endl;
    }
    std::cout << "Объединили два множетсва ";
    (s1 + s2).print();
    Set s3;
    s3 += 1;
    s3 += 3;
    s3 += 4;
    Set s4;
    s4 += 1;
    s4 += 3;
    s4 += 4;
    std::cout << "\nТретье множество ";
    s3.print();
    std::cout << "\nЧетвертое множество ";
    s4.print();
    std::cout << std::endl;
    if (s3 == s4) {
        std::cout << "Множества 3 и 4 равны" << std::endl;
    } else {
        std::cout << "Множества 3 и 4 не равны" << std::endl;
    }
    return 0;
}