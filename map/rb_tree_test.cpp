#include "rb_tree.hpp"
#include <iostream>

void    rb_tree_test() {
    ft::rb_tree<int>    tr;

    tr.insert(-1);
    for (size_t i = 0; i < 10; i++) {
        tr.insert(i);
    }

    ft::rb_tree<int>::iterator  it = tr.begin(), it_end = tr.end();
    for (int i = 0; it != it_end; it++, i++) {
        std::cout << i << ":    " << *it << std::endl;
    }
}