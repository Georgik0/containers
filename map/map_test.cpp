#include <iostream>
#include "map.hpp"
#include "../vector/vector.hpp"
#include <map>

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

template<class U, class V>
static void     view_map_std(std::map<U, V> &m) {
    typename std::map<U, V>::iterator        it = m.begin();
    typename std::map<U, V>::iterator        it_end = m.end();

    for (; it != it_end; it++) {
        std::cout << (*it).first << " ";
    }
    std::cout << "      map size = " << m.size() << std::endl;
    std::cout << std::endl;

}

void    map_test_insert() {
    std::cout << green_bold("\n\nMap test insert\n\n");

    std::cout << green("#1\n");
    {
        ft::map<int, int>   m;
        int i;

        for (i = 0; i <= 10; i++) {
            ft::pair<int, int>    p(i, i);
            m.insert(p);
        }
        view_map(m);
    }

    {
        std::cout << green("#2\n");
        ft::vector<int>     v;
        int i;
        for (i = 10; i >= 0; i--) {
            v.push_back(i);
        }

        ft::map<int, int>   m;
        m.insert(v.begin(), v.end());
        view_map(m);
    }
    
}

void    map_test_get_value() {
    std::cout << green_bold("\n\nMap test []\n\n");

    std::cout << green("#1\n");
    {
        ft::map<int, int>   m;
        int i, val;

        for (i = 0; i <= 10; i++) {
            ft::pair<int, int>    p(i, i);
            val = m[i];
            std::cout << val << " ";
        }
        std::cout << std::endl;
        view_map(m);
    }

    std::cout << green("#2\n");
    {
        ft::map<int, int>   m;
        int i;

        m[5] = 5;
        m[1] = 1;
        m[1] = 1;
        m[5] = 5;
        m[5] = 5;

        view_map(m);
    }

    std::cout << green("#3\n");
    {
        ft::map<int, int>   m;
        int i, val;

        for (i = 0; i <= 10; i++) {
            ft::pair<int, int>    p(i, i);
            m[i] = i;
            std::cout << m[i] << " ";
        }
        std::cout << std::endl;
        view_map(m);
    }
}

void    map_test_erase() {
    std::map<int, int>  m;
    for (int i = 0; i < 10; ++i) {
        m[i] = i;
        m[i] = i;
        m[i] = i;
    }

    size_t  s = m.erase(4);
    std::cout << "s = " << s << std::endl;
    view_map_std(m);
}

void    map_test() {
//    map_test_get_value();
//    map_test_insert();
    map_test_erase();
}