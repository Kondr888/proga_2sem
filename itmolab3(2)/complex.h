#pragma once

class Complex {
private:
    double _real;
    double _image;

public:
    Complex(double, double);

    double Length();
    void Show();

    Complex operator*(double);
    Complex operator+(const Complex &);
    Complex operator*(const Complex &);
    explicit operator double();

};