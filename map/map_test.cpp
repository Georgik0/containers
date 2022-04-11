#include <iostream>
#include "map.hpp"
#include "../vector/vector.hpp"
#include <map>
#include "../name_container.hpp"

#define green_bold(X) "\x1b[1;32m" + std::string(X) + "\x1b[0m"
#define green(X) "\x1b[0;32m" + std::string(X) + "\x1b[0m"

template<class U, class V>
static void     view_map(version::map<U, V> &m) {
    typename version::map<U, V>::iterator        it = m.begin();
    typename version::map<U, V>::iterator        it_end = m.end();
    
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
        version::map<int, int>   m;
        int i;

        for (i = 0; i <= 10; i++) {
            version::pair<int, int>    p(i, i);
            m.insert(p);
        }
        view_map(m);
    }

    {
        std::cout << green("#2\n");
        version::map<int, int>     v;
        int i;
        for (i = 10; i >= 0; i--) {
            v[i] = i;
        }

        version::map<int, int>   m;
        m.insert(v.begin(), v.end());
        view_map(m);
    }
    
}

void    map_test_get_value() {
    std::cout << green_bold("\n\nMap test []\n\n");

    std::cout << green("#1\n");
    {
        version::map<int, int>   m;
        int i, val;

        for (i = 0; i <= 10; i++) {
            version::pair<int, int>    p(i, i);
            val = m[i];
            std::cout << val << " ";
        }
        std::cout << std::endl;
        view_map(m);
    }

    std::cout << green("#2\n");
    {
        version::map<int, int>   m;
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
        version::map<int, int>   m;
        int i, val;

        for (i = 0; i <= 10; i++) {
            version::pair<int, int>    p(i, i);
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
        version::map<int, int>  m;
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
        version::map<int, int>  m;
        for (int i = 0; i < 10; ++i) {
            m[i] = i;
        }

        size_t  sresult_erase = m.erase(4);
        std::cout << "result erase(4) = " << sresult_erase << std::endl;
        view_map(m);
    }

    {
        std::cout << green("#3\n");
        version::map<int, int>  m;
        for (int i = 0; i < 10; ++i) {
            m[i] = i;
        }

        version::map<int, int>::iterator first = m.begin(), last = first;
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
        version::map<int, int>  m;
        for (int i = 0; i < 10; ++i) {
            m[i] = 10 - i;
        }

        version::map<int, int>::iterator it = m.find(2);
        if (it != m.end())
            std::cout << "it = m.find(2); *it = " << (*it).second << std::endl;
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
        version::map<int, int>  m;
        for (int i = 0; i < 10; ++i) {
            m[i] = 10 - i;
        }

        version::map<int, int>::size_type c = m.count(2);
        std::cout << "m.count(2) = " << c << std::endl;
        for (int i = 0; i < 10; i++) {
            std::cout << "m[" << i << "] = " << m[i] << "   ";
        }
        std::cout << std::endl;
    }

    {
        std::cout << green("#2\n");
        version::map<int, int>  m;
        for (int i = 0; i < 10; ++i) {
            m[i] = 10 - i;
        }

        version::map<int, int>::size_type c = m.count(2222);
        std::cout << "m.count(2222) = " << c << std::endl;
        for (int i = 0; i < 10; i++) {
            std::cout << "m[" << i << "] = " << m[i] << "   ";
        }
        std::cout << std::endl;
    }

    std::cout << green_bold("\n\nMap test equal_range\n\n");
    {
        version::map<int, int>  m;
        for (int i = 0; i < 10; ++i) {
            m[i] = i;
        }

        std::cout << green("#1\n");
        typedef version::map<int, int>::iterator     iter_map;
        version::pair<iter_map, iter_map>  p = m.equal_range(1);
        std::cout << "(*p.first).first (*p.first).second: " << (*p.first).first << "   " << (*p.first).second << std::endl; 
        std::cout << "(*p.second).first (*p.second).second: " << (*p.second).first << "   " << (*p.second).second << std::endl;
        for (iter_map q = p.first; q != p.second; ++q) {
            std::cout << "m[" << q->first << "] = " << q->second << '\n';
        }
        
        std::cout << green("#2\n");
        p = m.equal_range(9);
        std::cout << "(*p.first).first (*p.first).second: " << (*p.first).first << "   " << (*p.first).second << std::endl; 
        if (p.second == m.end())
            std::cout << "p.second == m.end()" << std::endl;
        else
            std::cout << "(*p.second).first (*p.second).second: " << (*p.second).first << "   " << (*p.second).second << std::endl;
        for (iter_map q = p.first; q != p.second; ++q) {
            std::cout << "m[" << q->first << "] = " << q->second << '\n';
        }
    }
}

void    map_test() {
    map_test_get_value();
    map_test_insert();
    map_test_erase();
    map_test_operation();
}