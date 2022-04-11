#include "rb_tree.hpp"
#include <iostream>
#include <unistd.h>
#include "../name_container.hpp"

#define green_bold(X) "\x1b[1;32m" + std::string(X) + "\x1b[0m"
#define green(X) "\x1b[0;32m" + std::string(X) + "\x1b[0m"

template <class T>
static void view_rb_tree(ft::rb_tree<T> &tr) {
        typename ft::rb_tree<T>::iterator  it = tr.begin(), it_end = tr.end();
        if (it == it_end) {
            std::cout << "begin == end" << std::endl;
            return;
        }
        for (int i = 0; it != it_end; it++, i++) {
            std::cout << *it << "   ";
        }
        std::cout << std::endl;
}

void    rb_tree_insert_test() {
    std::cout << green_bold("\n\nTest insert in rb_tree\n");

    {
        ft::rb_tree<int>    tr;

        tr.insert(-1);
        for (size_t i = 0; i < 10; i++) {
            tr.insert(i);
        }

        std::cout << green("\n#1\n");
        view_rb_tree(tr);
    }

    {
        ft::rb_tree<int>    tr;
        int i;

        tr.insert(-1);
        for (i = 9; i >= 0; i--) {
            tr.insert(i);
        }

        std::cout << green("\n#2\n");
        view_rb_tree(tr);
    }

    {
        ft::rb_tree<int>    tr;
        int i, j;

        for (i = -20, j = 21; i <= 0; i++, j--) {
            tr.insert(i);
            tr.insert(j);
        }

        std::cout << green("\n#3\n");
        view_rb_tree(tr);
    }

    {
        ft::rb_tree<int>    tr;
        int i;

        for (i = -10; i <= 10; i++) {
            tr.insert(i);
        }
        tr.insert(0); tr.insert(-5); tr.insert(5); tr.insert(10); tr.insert(-10);

        std::cout << green("\n#4\n");
        view_rb_tree(tr);
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

        std::cout << green("\n#5\n");
        view_rb_tree(tr);
    }
}

void    rb_tree_delete_test() {
    std::cout << green_bold("\n\nTest erase from rb_tree\n");

    {
        ft::rb_tree<int>    tr;
        int i;

        tr.insert(-1);
        for (i = 0; i <= 10; i++) {
            tr.insert(i);
        }

        std::cout << green("\n#1\n");
        std::cout << "Before:   ";
        view_rb_tree(tr);
        tr.erase(0);
        tr.erase(1);
        tr.erase(9);
        std::cout << "After:  ";
        view_rb_tree(tr);
        std::cout << std::endl;
    }

    {
        ft::rb_tree<int>    tr;
        int i;

        for (i = 0; i <= 10; i++) {
            tr.insert(i);
        }

        std::cout << green("\n#2\n");
        std::cout << "Before:   ";
        view_rb_tree(tr);
        tr.erase(1000);
        tr.erase(-1000);
        std::cout << "After:  ";
        view_rb_tree(tr);
        std::cout << std::endl;
    }

    {
        ft::rb_tree<int>    tr;
        int i;

        for (i = 0; i <= 10; i++) {
            tr.insert(i);
        }

        std::cout << green("\n#3\n");
        std::cout << "Before:   ";
        view_rb_tree(tr);
        tr.erase(0);
        tr.erase(1);
        std::cout << "After:  ";
        std::cout << "begin = " << *tr.begin() << ";    ";
        view_rb_tree(tr);
        std::cout << std::endl;
    }

    {
        ft::rb_tree<int>    tr;
        int i;

        for ( i = 0; i <= 10; i++) {
            tr.insert(i);
        }

        std::cout << green("\n#4\n");
        std::cout << "Before:   ";
        view_rb_tree(tr);
        for ( i = 0; i <= 9; i++) {
            tr.erase(i);
        }
        std::cout << "After:  ";
        view_rb_tree(tr);
        std::cout << std::endl;
    }

    {
        ft::rb_tree<int>    tr;
        int i;

        for ( i = 0; i <= 10; i++) {
            tr.insert(i);
        }

        std::cout << green("\n#4\n");
        std::cout << "Before:   ";
        view_rb_tree(tr);
        for ( i = 0; i <= 10; i++) {
            tr.erase(i);
        }
        std::cout << "After:  ";
        view_rb_tree(tr);
        std::cout << std::endl;
    }
}

void    rb_tree_construct_test() {

    {
        ft::rb_tree<ft::pair<const int, int> >  tr;

    }
}