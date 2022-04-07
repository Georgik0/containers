#include <iostream>
#include "map.hpp"

#define green_bold(X) "\x1b[1;32m" + std::string(X) + "\x1b[0m"
#define green(X) "\x1b[0;32m" + std::string(X) + "\x1b[0m"

template<class U, class V>
static void     view_map(ft::map<U, V> &m) {
    typename ft::map<U, V>::iterator        it = m.begin();
    typename ft::map<U, V>::iterator        it_end = m.end();
    
    for (; it != it_end; it++) {
        std::cout << (*it).v1 << " ";
    }
    std::cout << "      map size = " << m.size() << std::endl;
    std::cout << std::endl;
    
}

void    map_test() {
    std::cout << green_bold("\n\nMap test constructors\n\n");

    {
        ft::map<int, int>   m;
        int i;

        for (i = 0; i <= 10; i++) {
            ft::pair<int, int>    p(i, i);
            m.insert(p);
        }
        view_map(m);
    }
}