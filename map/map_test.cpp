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
    std::cout << green_bold("\n\nMap test erase\n\n");

    {
        std::cout << green("#1\n");
        ft::map<int, int>  m;
        for (int i = 0; i < 10; ++i) {
            m[i] = 10 - i;
        }
        for (int i = 0; i < 10; i++) {
            std::cout << "m[" << i << "] = " << m[i] << "   ";
        }
        

        size_t  sresult_erase = m.erase(4); std::cout << std::endl;
        for (int i = 0; i < 10; i++) {
            std::cout << "m[" << i << "] = " << m[i] << "   ";
        }
        std::cout << "result erase(4) = " << sresult_erase << std::endl;
        view_map(m);
    }

    {
        std::cout << green("#2\n");
        ft::map<int, int>  m;
        for (int i = 0; i < 10; ++i) {
            m[i] = i;
        }

        size_t  sresult_erase = m.erase(4);
        std::cout << "result erase(4) = " << sresult_erase << std::endl;
        view_map(m);
    }

    {
        std::cout << green("#3\n");
        ft::map<int, int>  m;
        for (int i = 0; i < 10; ++i) {
            m[i] = i;
        }

        ft::map<int, int>::iterator first = m.begin(), last = first;
        int i = 0;
        while (i++ < 5)
            last++;
        m.erase(first, last);
        view_map(m);
    }
}

void    map_test_operation() {
    std::cout << green_bold("\n\nMap test find\n\n");

    {
        std::cout << green("#1\n");
        ft::map<int, int>  m;
        for (int i = 0; i < 10; ++i) {
            m[i] = 10 - i;
        }

        ft::map<int, int>::iterator it = m.find(2);
        if (it != m.end())
            std::cout << "it = m.find(2); *it = " << (*it).v2 << std::endl;
        else
            std::cout << "not found" << std::endl;
        for (int i = 0; i < 10; i++) {
            std::cout << "m[" << i << "] = " << m[i] << "   ";
        }
        std::cout << std::endl;
    }

    std::cout << green_bold("\n\nMap test count\n\n");
    {
        std::cout << green("#1\n");
        ft::map<int, int>  m;
        for (int i = 0; i < 10; ++i) {
            m[i] = 10 - i;
        }

        ft::map<int, int>::size_type c = m.count(2);
        std::cout << "m.count(2) = " << c << std::endl;
        for (int i = 0; i < 10; i++) {
            std::cout << "m[" << i << "] = " << m[i] << "   ";
        }
        std::cout << std::endl;
    }

    {
        std::cout << green("#2\n");
        ft::map<int, int>  m;
        for (int i = 0; i < 10; ++i) {
            m[i] = 10 - i;
        }

        ft::map<int, int>::size_type c = m.count(2222);
        std::cout << "m.count(2222) = " << c << std::endl;
        for (int i = 0; i < 10; i++) {
            std::cout << "m[" << i << "] = " << m[i] << "   ";
        }
        std::cout << std::endl;
    }

    std::cout << green_bold("\n\nMap test equal_range\n\n");
    {
        ft::map<int, int>  m;
        for (int i = 0; i < 10; ++i) {
            m[i] = i;
        }

        std::cout << green("#1\n");
        typedef ft::map<int, int>::iterator     iter_map;
        ft::pair<iter_map, iter_map>  p = m.equal_range(1);
        std::cout << "(*p.v1).v1 (*p.v1).v2: " << (*p.v1).v1 << "   " << (*p.v1).v2 << std::endl; 
        std::cout << "(*p.v2).v1 (*p.v2).v2: " << (*p.v2).v1 << "   " << (*p.v2).v2 << std::endl;
        for (iter_map q = p.v1; q != p.v2; ++q) {
            std::cout << "m[" << q->v1 << "] = " << q->v2 << '\n';
        }
        
        std::cout << green("#2\n");
        p = m.equal_range(9);
        std::cout << "(*p.v1).v1 (*p.v1).v2: " << (*p.v1).v1 << "   " << (*p.v1).v2 << std::endl; 
        if (p.v2 == m.end())
            std::cout << "p.v2 == m.end()" << std::endl;
        else
            std::cout << "(*p.v2).v1 (*p.v2).v2: " << (*p.v2).v1 << "   " << (*p.v2).v2 << std::endl;
        for (iter_map q = p.v1; q != p.v2; ++q) {
            std::cout << "m[" << q->v1 << "] = " << q->v2 << '\n';
        }
    }
}

void    map_test() {
    map_test_get_value();
    map_test_insert();
    map_test_erase();
    map_test_operation();
}