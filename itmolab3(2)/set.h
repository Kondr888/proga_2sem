#pragma once

class Set {
public:
    bool set[10]{};

    Set();

    Set &operator+(const Set &);

    Set &operator+=(int);

    Set &operator-=(int);

    bool operator==(const Set &);

    bool operator!=(const Set &);

    void print();

};