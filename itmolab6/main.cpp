#include <iostream>
#include <vector>
#include <set>
#include "header.h"

bool predicate(int x) {
    return x == 0;
}

bool sort_predicate(int x, int y) {
    return x < y;
}

int main() {
    std::vector<int> v = {1, 5, 3, 3, 2};
    std::set<double> s = {-1, 2, 3.123, 4, 5};
    std::cout << "Для вектора: \n";
    if (anyOf(v.begin(), v.end(), predicate)) {
        std::cout << "Не существует элементов в заданном диапозоне\n";
    } else {
        std::cout << "Существует хотя бы один элемент в заданном диапозоне\n";
    }
    if (isSorted(v.begin(), v.end(), sort_predicate)) {
        std::cout << "Отсортирован\n";
    } else {
        std::cout << "Не отсортирован\n";
    }
    std::cout << isPalindrome(v.begin(), v.end(), predicate) << std::endl;
}