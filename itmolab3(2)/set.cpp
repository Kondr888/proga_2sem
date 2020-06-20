#include <iostream>
#include "Set.h"

Set::Set() {  //по умолчанию всё false стоит
    for (bool & i : set) {
        i = false;
    }
}

Set &Set::operator+(const Set &s) {
    for (int i = 0; i < 10; i++) {
        this->set[i] |= s.set[i];
    }
    return *this;
}

Set &Set::operator+=(int i) {
    this->set[i] = true;
    return *this;
}

Set &Set::operator-=(int i) {
    this->set[i] = false;
    return *this;
}

bool Set::operator==(const Set &s) {
    for (int i = 0; i < 10; i++) {
        if (this->set[i] != s.set[i]) {
            return false;
        }
    }
    return true;
}

bool Set::operator!=(const Set &s) {
    bool temp = true;
    for (int i = 0; i < 10; i++) {
        if (this->set[i] != s.set[i]) {
            temp = false;
        }
    }
    return temp;
}

void Set::print() {
    std::cout << "set { ";
    for (int i = 0; i < 10; i++) {
        if (set[i]) {
            std::cout << i << " ";
        }
    }
    std::cout << "}";
}
