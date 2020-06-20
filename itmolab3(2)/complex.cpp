#include <cmath>
#include <iostream>

#include "Complex.h"

Complex::Complex(double _real, double _image) : _real(_real), _image(_image) {} //конструктор по умолчанию

double Complex::Length() { //функция длины по комплексному числу формула
    return sqrt(this->_real * this->_real + this->_image * this->_image);
}

Complex::operator double() { //возвращает длину переданного в него комплексного числа
    return this->Length();
}

Complex Complex::operator*(double x) { //перемножение  комплексного на вещ
    return Complex(this->_real * x, this->_image * x);
}

Complex Complex::operator+(const Complex &c) {//сложение
    return Complex(this->_real + c._real, this->_image + c._image);
}

Complex Complex::operator*(const Complex &c) {//ф-ция
    return Complex(this->_real * c._real - this->_image * c._image, this->_real * c._image + this->_image * c._real);
}

void Complex::Show() { //выводит
    std::cout << this->_real;
    if (this->_image > 0) {
        std::cout << " + " << this->_image << "i" << std::endl;
    } else if (this->_image < 0) {
        std::cout << " - " << abs(this->_image) << "i" << std::endl;
    }
    if (this->_image == 0) {
        std::cout << std::endl;
    }
}
