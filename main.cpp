//
// Created by Stephane Kitsch on 12/11/21.
//

#include <iostream>
#include <vector>
#include "iterator.hpp"

int main() {

//    std::vector<int> a{1, 2, 3, 4, 4};
    int a[] {1, 2, 3, 4, 4, 5};
    {
        std::cout << "STD" << std::endl;
        std::reverse_iterator <int*> x = std::rbegin(a), y = std::rbegin(a) + 1;
        std::cout << "x = " << *x << std::endl;
        std::cout << "y = " << *y << std::endl;
        std::cout << "x == y =  " << (x == y) << std::endl;
    }
    {
        std::cout << "FT" << std::endl;
        ft::reverse_iterator <int*> x = std::rbegin(a), y = std::rbegin(a) + 1;
//        std::cout << "x = " << *x << std::endl;
//        std::cout << "y = " << *y << std::endl;
//        std::cout << "x == y =  " << (x == y) << std::endl;
    }

}
