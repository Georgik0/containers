#include "vector.hpp"

#define version std

template<class T>
void    info_vector(version::vector<T> v) {
    std::cout << "-------- Info --------\n";
    std::cout << "cap: " << v.capacity() << "\n";
    std::cout << "len: " << v.size() << "\n\n";
}

template<class T>
void    view_vector(version::vector<T> v) {
    typename version::vector<T>::iterator    it_begin = v.begin(), it_end = v.end();

    std::cout << "vector:";
    for (; it_begin < it_end; it_begin++)
        std::cout << " " << *it_begin;
    std::cout << std::endl;
}

void    test_constructors() {
    version::vector<int>    a;
    info_vector(a);
    view_vector(a);

    version::vector<int>    b(21);
    info_vector(b);
    view_vector(b);

    version::vector<int>    c(5, 35);
    info_vector(c);
    view_vector(c);

    version::vector<int>    d;
    for (size_t i = 0; i < 10; i++)
        d.push_back(i);
    info_vector(d);
    view_vector(d);

    version::vector<int>    e(d.begin() + 2, d.begin() + 5);
    info_vector(e);
    view_vector(e);

    version::vector<int>    f(d);
    info_vector(f);
    view_vector(f);

    version::vector<int>    g = f;
    info_vector(g);
    view_vector(g);
}

void    test_modifiers() {
    version::vector<int>    a;

    for (size_t i = 0; i < 10; i++) {
        a.push_back(i);
        info_vector(a);
    }
    view_vector(a);
}

void vector_test() {
    test_constructors();
}