#include "rb_tree.hpp"
#include <iostream>

void    rb_tree_test() {
    {
        ft::rb_tree<int>    tr;

        tr.insert(-1);
        for (size_t i = 0; i < 10; i++) {
            tr.insert(i);
        }

        ft::rb_tree<int>::iterator  it = tr.begin(), it_end = tr.end();
        for (int i = 0; it != it_end; it++, i++) {
            std::cout << *it << "   ";
        }
        std::cout << std::endl;
    }

    {
        ft::rb_tree<int>    tr;
        int i;

        tr.insert(-1);
        for (i = 9; i >= 0; i--) {
            tr.insert(i);
        }

        ft::rb_tree<int>::iterator  it = tr.begin(), it_end = tr.end();
        for (i = 0; it != it_end; it++, i++) {
            std::cout << *it << "   ";
        }
        std::cout << std::endl;
    }

    {
        ft::rb_tree<int>    tr;
        int i, j;

        for (i = -20, j = 21; i <= 0; i++, j--) {
            tr.insert(i);
            tr.insert(j);
        }

        ft::rb_tree<int>::iterator  it = tr.begin(), it_end = tr.end();
        for (i = 0; it != it_end; it++, i++) {
            std::cout << *it << "   ";
        }
        std::cout << std::endl;
    }

    {
        ft::rb_tree<int>    tr;
        int i;

        for (i = -10; i <= 10; i++) {
            tr.insert(i);
        }
        tr.insert(0); tr.insert(0); tr.insert(0); tr.insert(0);
        tr.insert(-5); tr.insert(5); tr.insert(10); tr.insert(10);

        ft::rb_tree<int>::iterator  it = tr.begin(), it_end = tr.end();
        for (i = 0; it != it_end; it++, i++) {
            std::cout << *it << "   ";
        }
        std::cout << std::endl;
    }

    {
        ft::rb_tree<int>    tr;
        int i;

        tr.insert(-1);
        for (i = -10; i <= -5; i++) {
            tr.insert(i);
        }
        for (i = 10; i >= 5; i--) {
            tr.insert(i);
        }
        for (i = -10; i <= 10; i += 2) {
            tr.insert(i);
        }

        ft::rb_tree<int>::iterator  it = tr.begin(), it_end = tr.end();
        for (i = 0; it != it_end; it++, i++) {
            std::cout << *it << "   ";
        }
        std::cout << std::endl;
    }
}