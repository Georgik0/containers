#include "vector.hpp"

#define version std

template<class T>
void    info_vector(version::vector<T> v) {
    std::cout << "cap: " << v.capacity() << "\n";
    std::cout << "len: " << v.size() << "\n";
}

template<class T>
void    view_vector(version::vector<T> v) {
    typename version::vector<T>::iterator    it_begin = v.begin(), it_end = v.end();

    std::cout << "vector:";
    for (; it_begin < it_end; it_begin++)
        std::cout << " " << *it_begin;
    std::cout << "\n\n";
}

void    test_constructors() {
    std::cout << "Test constructors\n";
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

// modifierss
void    test_modifiers() {
    std::cout << "\x1b[1;32mTest modifiers\x1b[0m\n\n";
    std::cout << "\x1b[1;32minsert()\x1b[0m\n";
    version::vector<int>    a;

    for (size_t i = 0; i < 10; i++)
        a.push_back(i);
    view_vector(a);

    for (size_t i = 0; i < 4; i++)
        a.pop_back();
    view_vector(a);

    {
        version::vector<int>    b(10, 1);
        version::vector<int>::iterator  it = b.begin() + 5;
        int in = 35;
        b.insert(it, in);
        info_vector(b);
        view_vector(b);
    }
    
    {
        version::vector<int>    c;
        version::vector<int>::iterator  it = c.begin();
        c.insert(it, 35);
        info_vector(c);
        view_vector(c);
    }

    {
        version::vector<int>    d;
        version::vector<int>::iterator  it = d.end();
        d.insert(it, 35);
        info_vector(d);
        view_vector(d);
    }

    {
        version::vector<int>    e(10);
        for (size_t i = 0; i < 10; i++)
            e[i] = i;

        version::vector<int>::iterator  it_begin = e.begin(), it_end = e.end();
        version::vector<int>    f(10, 1);
        f.insert(f.begin() + 5, it_begin, it_end);
        info_vector(f);
        view_vector(f);
    }

    std::cout << "\x1b[1;32merase()\x1b[0m\n";
    {
        std::cout << "#1\n";
        version::vector<int>    a(10);
        for (size_t i = 0; i < 10; i++)
            a[i] = i;
        version::vector<int>::iterator  it = a.erase(a.begin() + 5);
        std::cout << "iterator = " << *it << "\n";
        info_vector(a);
        view_vector(a);
    }

    {
        std::cout << "#2\n";
        version::vector<int>    a(3); a[0] = 0; a[1] = 1; a[2] = 2;
        version::vector<int>::iterator  it = a.erase(a.begin());
        std::cout << "iterator = " << *it << "\n";
        info_vector(a);
        view_vector(a);
    }

    {
        std::cout << "#3\n";
        version::vector<int>    a(3); a[0] = 0; a[1] = 1; a[2] = 2;
        version::vector<int>::iterator  it = a.erase(a.end() - 1);
        std::cout << "iterator = " << *it << "\n";
        info_vector(a);
        view_vector(a);
    }

    {
        std::cout << "#4\n";
        version::vector<int>    a(10);
        for (size_t i = 0; i < 10; i++)
            a[i] = i;
        version::vector<int>::iterator  it = a.erase(a.begin(), a.end());
        std::cout << "iterator = " << *it << "\n";
        info_vector(a);
        view_vector(a);
    }

    {
        std::cout << "#5\n";
        version::vector<int>    a(10);
        for (size_t i = 0; i < 10; i++)
            a[i] = i;
        version::vector<int>::iterator  it = a.erase(a.begin(), a.end() - 1);
        std::cout << "iterator = " << *it << "\n";
        info_vector(a);
        view_vector(a);
    }

    {
        std::cout << "#6\n";
        version::vector<int>    a(10);
        for (size_t i = 0; i < 10; i++)
            a[i] = i;
        version::vector<int>::iterator  it = a.erase(a.begin(), a.begin() + 1);
        std::cout << "iterator = " << *it << "\n";
        info_vector(a);
        view_vector(a);
    }

    {
        std::cout << "#7\n";
        version::vector<int>    a(10);
        for (size_t i = 0; i < 10; i++)
            a[i] = i;
        version::vector<int>::iterator  it = a.erase(a.begin(), a.begin());
        std::cout << "iterator = " << *it << "\n";
        info_vector(a);
        view_vector(a);
    }
    
    std::cout << "\x1b[1;32massign()\x1b[0m\n";
    {
        version::vector<int>    a(10, 1);
        int r = 22;
        a.assign(5, r);
        info_vector(a);
        view_vector(a);
    }
// segmentation fault
    // {
    //     version::vector<int>    a(10);
    //     for (size_t i = 0; i < 10; i++)
    //         a[i] = i;
    //     version::vector<int>::iterator  it = a.erase(a.end() + 2, a.end() + 5);
    //     std::cout << "iterator = " << *it << "\n";
    //     info_vector(a);
    //     view_vector(a);
    // }

    // {
    //     version::vector<int>    a(3); a[0] = 0; a[1] = 1; a[2] = 2;
    //     version::vector<int>::iterator  it = a.erase(a.end());
    //     std::cout << "iterator = " << *it << "\n";
    //     info_vector(a);
    //     view_vector(a);
    // }

    // {
    //     version::vector<int>    a;
    //     version::vector<int>::iterator  it = a.erase(a.begin());
    //     std::cout << "iterator = " << *it << "\n";
    //     info_vector(a);
    //     view_vector(a);
    // }

    // {
    //     version::vector<int>    a;
    //     version::vector<int>::iterator  it = a.erase(a.end());
    //     std::cout << "iterator = " << *it << "\n";
    //     info_vector(a);
    //     view_vector(a);
    // }

    // {
    //     version::vector<int>    a;
    //     version::vector<int>::iterator  it = a.erase(a.begin() + 4);
    //     std::cout << "iterator = " << *it << "\n";
    //     info_vector(a);
    //     view_vector(a);
    // }

    // {
    //     version::vector<int>    a(3, 1);
    //     version::vector<int>::iterator  it = a.erase(a.begin() + 10);
    //     std::cout << "iterator = " << *it << "\n";
    //     info_vector(a);
    //     view_vector(a);
    // }
}

// element_access
void    test_element_access() {
    std::cout << "\n\x1b[1;32melement access\x1b[0m\n";

    {
        version::vector<int>    a(10);
        for (size_t i = 0; i < 10; i++)
            a[i] = i;
        std::cout << "Info: a\n";
        info_vector(a);
        view_vector(a);
        int n = a.at(0);
        std::cout << "at(0) = " << n << "\n";
        try {
            n = a.at(-1);
            std::cout << "at(-1) = " << n << "\n";
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        try {
            n = a.at(10);
            std::cout << "at(10) = " << n << "\n";
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
        n = a.at(5);
        std::cout << "at(5) = " << n << "\n";
    }
}

void    test_non_member_functions() {
    std::cout << "\x1b[1;32mNon-member functions\x1b[0m\n";

    {
        std::cout << "#1\n";
        version::vector<int>    a;
        version::vector<int>    b;

        std::cout << "Info: a\n";
        info_vector(a);
        view_vector(a);
        std::cout << "Info: b\n";
        info_vector(b);
        view_vector(b);
        std::cout << "a == b    " << (a == b ? "true" : "false") << "\n\n";
    }
    
    {
        std::cout << "#2\n";
        version::vector<int>    a(10);
        version::vector<int>    b(2);

        std::cout << "Info: a\n";
        info_vector(a);
        view_vector(a);
        std::cout << "Info: b\n";
        info_vector(b);
        view_vector(b);
        std::cout << "a == b    " << (a == b ? "true" : "false") << "\n\n";
    }

    {
        std::cout << "#3\n";
        version::vector<int>    a(10, 1);
        version::vector<int>    b(10, 2);

        std::cout << "Info: a\n";
        info_vector(a);
        view_vector(a);
        std::cout << "Info: b\n";
        info_vector(b);
        view_vector(b);
        std::cout << "a == b    " << (a == b ? "true" : "false") << "\n\n";
    }

    {
        std::cout << "#4\n";
        version::vector<int>    a(5, 1);
        version::vector<int>    b(10, 1);

        std::cout << "Info: a\n";
        info_vector(a);
        view_vector(a);
        std::cout << "Info: b\n";
        info_vector(b);
        view_vector(b);
        std::cout << "a == b    " << (a == b ? "true" : "false") << "\n\n";
    }

    {
        std::cout << "#5\n";
        version::vector<int>    a(10, 1);
        version::vector<int>    b(10, 2);

        std::cout << "Info: a\n";
        info_vector(a);
        view_vector(a);
        std::cout << "Info: b\n";
        info_vector(b);
        view_vector(b);
        std::cout << "a < b    " << (a < b ? "true" : "false") << "\n\n";
    }

    {
        std::cout << "#6\n";
        version::vector<int>    a(10, 1);
        version::vector<int>    b(10, 1);

        std::cout << "Info: a\n";
        info_vector(a);
        view_vector(a);
        std::cout << "Info: b\n";
        info_vector(b);
        view_vector(b);
        std::cout << "a <= b    " << (a <= b ? "true" : "false") << "\n\n";
    }

    {
        std::cout << "#7\n";
        version::vector<int>    a(10, 1);
        version::vector<int>    b(5, 1);

        std::cout << "Info: a\n";
        info_vector(a);
        view_vector(a);
        std::cout << "Info: b\n";
        info_vector(b);
        view_vector(b);
        std::cout << "a <= b    " << (a <= b ? "true" : "false") << "\n\n";
    }

    {
        std::cout << "#8\n";
        version::vector<int>    a(5, 1);
        version::vector<int>    b(10, 1);

        std::cout << "Info: a\n";
        info_vector(a);
        view_vector(a);
        std::cout << "Info: b\n";
        info_vector(b);
        view_vector(b);
        std::cout << "a <= b    " << (a <= b ? "true" : "false") << "\n\n";
    }

}

void vector_test() {
    test_constructors();
    test_modifiers();
    test_non_member_functions();
    test_element_access();
}