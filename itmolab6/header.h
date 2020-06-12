#pragma once

template <typename iterator, typename object>
bool anyOf(iterator begin, iterator end, bool (&function)(object)){ //два итератора на начало и конец, ссылка на предикат
    for(auto it = begin; it != end; it = next(it)){ // цикл от начала до конца
        if(function(*it)){ //проверяем каждый элемент на соответствие условию
            return true; //если хотя бы один раз условие выполнилось, функция вернет true
        }
    }
    return false;//в другом случае false
}

template <typename iterator, typename object>
bool isSorted(const iterator begin, const iterator end, bool (&f)(object, object)) {//два итератора на начало и конец, ссылка на предикат, принимающий 2 объекта
    iterator prev = begin; //итератор на предыдущий элемент
    for (auto it = next(begin); it != end; it = next(it)) { //с 1 до конца
        if (!f(*prev, *it)) {//если нынешний элемент и предыдущий не подходят под условие сортировки то false
            return false;
        }
        prev = it; //в другом случае предыдущий становится нынешним
    }
    return true; //если все элементы подошли под условие, то return false не сработает ни разу, вернем true
}

template <typename iterator, typename object>
bool isPalindrome(const iterator begin, const iterator end, bool (&f)(object)){
    iterator last = end; //итератор на конец
    for(auto it = begin; it != last; it = next(it)){ //сначала до половины массива
        if(f(*it) == f(*last)){ //сравниваем сначала и с конца
            prev(last); //если выполнилось, сдвигаемся дальше
        } else {
            return false; //иначе не палиндром, выходим с false
        }
    }
    return true; //если первый return не сработал, возвращаем true
}