//
// Created by Stephane Kitsch on 12/11/21.
//

#include <iostream>
#include <vector>
#include "reverse_iterator.hpp"

template <class ptr>
void    checker(ptr x, ptr y) {
    std::cout << "x = " << *x << std::endl;
    std::cout << "y = " << *y << std::endl;
    std::cout << "x == y =  " << (x == y) << std::endl;
    std::cout << "*(x - 3) =  " << *(x - 3) << std::endl;
    std::cout << "*(y + 1) =  " << *(y + 1) << std::endl;
}

void reverse_iterator_test() {

    int a[] = {1, 2, 3, 4, 4, 5};
    {
        std::cout << "STD" << std::endl;
        int *ptra = a;
        std::reverse_iterator <int*> x = std::reverse_iterator<int *>(a), y = std::reverse_iterator<int *>(ptra);
        checker(x, y);
    }
    {
        std::cout << "FT" << std::endl;
        int *ptra = a;
        ft::reverse_iterator <int*> x = ft::rend(a), y = ft::rend(ptra);
        checker(x, y);
    }

}
