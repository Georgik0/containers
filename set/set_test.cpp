#include "set.hpp"

#define green_bold(X) "\x1b[1;32m" + std::string(X) + "\x1b[0m"
#define green(X) "\x1b[0;32m" + std::string(X) + "\x1b[0m"

#define version     ft

template <class T>
void    info_set(version::set<T> &s) {
    typename version::set<T>::iterator   it = s.begin(), it_end = s.end();

    std::cout << "size = " << s.size() << std::endl;
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


        // for (int i = 0; i < 10; ++i) {
        //     m[i] = 10 - i;
        // }
        // for (int i = 0; i < 10; i++) {
        //     std::cout << "m[" << i << "] = " << m[i] << "   ";
        // }
        

        // size_t  sresult_erase = m.erase(4); std::cout << std::endl;
        // for (int i = 0; i < 10; i++) {
        //     std::cout << "m[" << i << "] = " << m[i] << "   ";
        // }
        // std::cout << "result erase(4) = " << sresult_erase << std::endl;
        // view_map(m);
    }
}