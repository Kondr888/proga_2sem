#pragma once
#include <iostream>
#include <cmath>


class IGeoFig {
public:
    virtual double square() const = 0;
    virtual double perimeter() const = 0;
};

class Point{
public:
    double x = 0;
    double y = 0;

    void initFromDialog(){
        std::cin >> x >> y;
    }

    void printCoordinate() const {
        std::cout << "(" << x << ";" << y << ")" << std::endl;
    }
};

// Вектор
class CVector2D {
public:
    Point A;
    Point B;
    Point AB = {(B.x - A.x), (B.y-A.y)};

    double lenghtVector() const {
        return sqrt(pow(AB.x, 2) + pow (AB.y, 2));
    }

    void PrintVector () const {
        std::cout << "Координаты вектораА: (" << AB.x << ";" << AB.y << ")" << std::endl;
    }
};

// Интерфейс "Физический объект".
class IPhysObject {
public:
// Масса, кг.
    virtual double mass() const = 0;
// Координаты центра масс, м.
    virtual CVector2D position() const = 0;
// Сравнение по массе.
    virtual bool operator== ( const IPhysObject& ob ) const = 0;
// Сравнение по массе.
    virtual bool operator< ( const IPhysObject& ob ) const = 0;
};

// Интерфейс "Отображаемый"
class IPrintable {
public:
    virtual void draw() const = 0;
};

class IDialogInitiable {
public:
    virtual void initFromDialog() = 0;
};

// Интерфейс "Класс"
class BaseCObject {
public:
// Имя класса (типа данных).
    virtual const char* classname() const = 0;
// Размер занимаемой памяти.
    virtual unsigned int size() const = 0;
};

class BaseClass : public BaseCObject, public IGeoFig, public IDialogInitiable, public  IPrintable, public IPhysObject {
public:
    virtual  ~BaseClass() = default;
};

class EquilateralTriangle: public BaseClass {
private:
    int a;
public:
    EquilateralTriangle();
    EquilateralTriangle(const Point &centre_, const double &mass__, const CVector2D &position__, int a);
    EquilateralTriangle(const EquilateralTriangle &obj);
    ~EquilateralTriangle() override = default;

    Point centre{0, 0};
    double mass_;
    CVector2D position_{};

    void initFromDialog() override;
    double square() const override;
    double perimeter () const override;
    void draw() const override;
    unsigned int size() const override;
    double mass() const override;
    CVector2D position() const override;
    const char* classname() const override;

    bool operator == (const IPhysObject &obj) const override;
    bool operator < (const IPhysObject &obj) const override;
};

class Parallelogram : public BaseClass {
private:
    Point a, b, c, d;
public:
    Parallelogram();

    Parallelogram(const Point &centre_, const double &mass__, const CVector2D &position__, Point a, Point b, Point c, Point d);

    Parallelogram(const Parallelogram &obj);

    ~Parallelogram() override = default;

    Point centre{0, 0};
    double mass_;
    CVector2D position_{};

    void initFromDialog() override;

    double square() const override;

    double perimeter () const override;

    void draw() const override;

    unsigned int size() const override;

    double mass() const override;

    CVector2D position() const override;

    const char* classname() const override;

    bool operator == (const IPhysObject &obj) const override;

    bool operator < (const IPhysObject &obj) const override;
};