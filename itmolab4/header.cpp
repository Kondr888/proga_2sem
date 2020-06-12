#include "header.h"


EquilateralTriangle::EquilateralTriangle() {
    centre = {0, 0};
    a = 0;
    mass_ = 0;
    position_ = {0, 0};
}

EquilateralTriangle::EquilateralTriangle(const Point &centre_, const double &mass__,
                                         const CVector2D &position__, int a) {
    centre = centre_;
    this->a = a;
    mass_ = mass__;
    position_ = position__;
}

EquilateralTriangle::EquilateralTriangle(const EquilateralTriangle &obj) {
    centre = obj.centre;
    a = obj.a;
    mass_ = obj.mass_;
    position_ = obj.position_;
}

void EquilateralTriangle::initFromDialog() {
    std::cout << "введите координаты центра: ";
    centre.initFromDialog();
    std::cout << "введите сторону: ";
    std::cin >> a;
    std::cout << "введите массу: ";
    std::cin >> mass_;
}

double EquilateralTriangle::square() const {
    return sqrt(3) * pow(a, 2) / 4;
}

double EquilateralTriangle::perimeter() const {
    return a * 3;
}

void EquilateralTriangle::draw() const {
    std::cout << "Центр масс: " << std::endl;
    centre.printCoordinate();
    std::cout << "Сторона: " << a << std::endl;
    std::cout << "Масса:  " << mass_ << std::endl;
}

unsigned int EquilateralTriangle::size() const {
    return sizeof(*this);
}

double EquilateralTriangle::mass() const {
    return mass_;
}

CVector2D EquilateralTriangle::position() const {
    return position_;
}

const char *EquilateralTriangle::classname() const {
    return "Equilateral Triangle";
}

bool EquilateralTriangle::operator==(const IPhysObject &obj) const {
    return this->mass() == obj.mass();
}

bool EquilateralTriangle::operator<(const IPhysObject &obj) const {
    return this->mass() < obj.mass();
}


Parallelogram::Parallelogram() {
    centre = {0, 0};
    a = {0, 0};
    b = {0, 0};
    c = {0, 0};
    d = {0, 0};
    mass_ = 0;
    position_ = {0, 0};
}

Parallelogram::Parallelogram(const Point &centre_, const double &mass__, const CVector2D &position__,
                             Point a, Point b, Point c, Point d) {
    centre = centre_;
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    mass_ = mass__;
    position_ = position__;
}

Parallelogram::Parallelogram(const Parallelogram &obj) {
    centre = obj.centre;
    a = obj.a;
    b = obj.b;
    c = obj.c;
    d = obj.d;
    mass_ = obj.mass_;
    position_ = obj.position_;
}

void Parallelogram::initFromDialog() {
    std::cout << "введите координаты центра: ";
    centre.initFromDialog();
    std::cout << "введите координаты стороны a: \n";
    std::cin >> a.x >> a.y;
    std::cout << "введите координаты стороны b: \n";
    std::cin >> b.x >> b.y;
    std::cout << "введите координаты стороны c: \n";
    std::cin >> c.x >> c.y;
    std::cout << "введите координаты стороны d: \n";
    std::cin >> d.x >> d.y;
    std::cout << "введите массу: ";
    std::cin >> mass_;
}

double Parallelogram::square() const {
    double cos = (a.x * b.x + a.y * b.y) /
                 ((sqrt(pow(a.x, 2)) + sqrt(pow(b.y, 2))) * (sqrt(pow(b.x, 2)) + sqrt(pow(b.y, 2))));
    double a_side = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    double b_side = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
    return a_side * b_side * cos;
}

double Parallelogram::perimeter() const {
    double a_side = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    double b_side = sqrt(pow(c.x - b.x, 2) + pow(c.y - b.y, 2));
    double c_side = sqrt(pow(d.x - c.x, 2) + pow(d.y - c.y, 2));
    double d_side = sqrt(pow(a.x - d.x, 2) + pow(a.y - d.y, 2));
    return a_side + b_side + c_side + d_side;
}

void Parallelogram::draw() const {
    std::cout << "Центр масс: " << std::endl;
    centre.printCoordinate();
    std::cout << "Координаты сторон\na = (" << a.x << ',' << a.y << ")\nb = (" << b.x << ',' << b.y << ")\nc = (" << c.x
              << ',' << c.y << ")\nd = (" << d.x << ',' << d.y << ")\nb = (";
    std::cout << "Масса:  " << mass_ << std::endl;
}

unsigned int Parallelogram::size() const {
    return sizeof(*this);
}

double Parallelogram::mass() const {
    return mass_;
}

CVector2D Parallelogram::position() const {
    return position_;
}

const char *Parallelogram::classname() const {
    return "Parallelogram";
}

bool Parallelogram::operator==(const IPhysObject &obj) const {
    return this->mass() == obj.mass();
}

bool Parallelogram::operator<(const IPhysObject &obj) const {
    return this->mass() < obj.mass();
}


