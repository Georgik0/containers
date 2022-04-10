#include "set.hpp"
#include <set>

#define green_bold(X) "\x1b[1;32m" + std::string(X) + "\x1b[0m"
#define green(X) "\x1b[0;32m" + std::string(X) + "\x1b[0m"

#define version     ft

template <class T>
void    info_set(version::set<T> &s) {
    typename version::set<T>::iterator   it = s.begin(), it_end = s.end();

    std::cout << "size = " << s.size() << std::endl;
    std::cout << "empty = " << s.empty() << std::endl;
    std::cout << "max_size = " << s.max_size() << std::endl;
    if (it == it_end)
        std::cout << "begin == end" << std::endl;
    while (it != it_end) {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

void    test_set() {
    std::cout << green_bold("\n\nSet test constructor\n\n");

    {
        std::cout << green("#1\n");
        
        version::set<int>  s;
        info_set(s);
    }

    std::cout << green_bold("\n\nSet test erase, insert\n\n");
    {
        std::cout << green("#1\n");
        
        version::set<int>  s;
        int i = 0;
        for (int i = 0; i < 10; i++) {
            s.insert(i);
        }
        info_set(s);

        for (int i = 4; i < 8; i++) {
            s.erase(i);
        }
        info_set(s);
    }

    std::cout << green_bold("\n\nSet test iterators\n\n");
    {
        std::cout << green("#1\n");
        
        version::set<int>  s;
        int i = 0;
        for (int i = 0; i < 10; i++) {
            s.insert(i);
        }
        info_set(s);

        version::set<int>::reverse_iterator     rit = s.rbegin(), rit_end = s.rend();
        while (rit != rit_end) {
            rit++;
            std::cout << *rit << " ";
        }
        
    }
}