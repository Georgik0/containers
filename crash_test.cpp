#include "crash_test.hpp"
#include <time.h>
#include <sstream>
#include <map>
#include <set>

namespace   ft {
    std::string to_string(int a) {
    std::stringstream ss;
    ss << a;
    std::string str = ss.str();
    return str;
}
}

void    crash_test() {
    std::cout << green_bold("\n\nCrash test\n\n");
    {
        std::cout << green("#1\n");
        typedef     version::map<int, std::string>  mis;
        version::vector<mis>    v(10);

        int i = 0, j = 0;
        while (i < 10) {
            for (j = 0; j < 10; j++) {
                v[i][j] = ft::to_string(i) + ft::to_string(j);
            }
            i++;
        }

        for (i = 0; i < v.size(); i++) {
            for (j = 0; j < v[i].size(); j++) {
                std::cout << v[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }

    {
        std::cout << green("#2\n");
        typedef     version::set<std::string>  s;
        version::map<int, s>    m;

        int i = 0, j = 0;
        while (i < 10) {
            for (j = 0; j < 10; j++) {
                m[i].insert(ft::to_string(i) + ft::to_string(j));
            }
            i++;
        }

        version::map<int, s>::iterator      it = m.begin(), it_end = m.end();
        s::iterator     it_set, it_set_end;
        while (it != it_end) {
            it_set = (*it).second.begin(), it_set_end = (*it).second.end();
            while (it_set != it_set_end) {
                std::cout << *it_set << "  ";
                it_set++;
            }
            std::cout << std::endl;
            it++;
        }
    }

    {
        std::cout << green("#3\n");
        typedef     version::set<std::string>  s;
        version::map<int, s>    m;

        int i = 0, j = 0;
        while (i < 10) {
            for (j = 0; j < 10; j++) {
                m[i].insert(ft::to_string(i) + ft::to_string(j));
            }
            i++;
        }
        i = 4; j = 4;
        while (i < 9) {
            for (j = 4; j < 9; j++) {
                m[i].erase(ft::to_string(i) + ft::to_string(j));
            }
            i++;
        }

        version::map<int, s>::iterator      it = m.begin(), it_end = m.end();
        s::iterator     it_set, it_set_end;
        while (it != it_end) {
            it_set = (*it).second.begin(), it_set_end = (*it).second.end();
            while (it_set != it_set_end) {
                std::cout << *it_set << "  ";
                it_set++;
            }
            std::cout << std::endl;
            it++;
        }
    }
}

void    speed_test() {
    clock_t start = clock();
    clock_t end = clock();
    double sec;

    std::cout << green_bold("\n\nCrash test speed\n\n");
    {
        std::cout << green("#1\n");
        typedef     version::map<int, std::string>  mis;
        version::vector<mis>    v(10);

        start = clock();
        int i = 0, j = 0;
        while (i < 10) {
            for (j = 0; j < 10; j++) {
                v[i][j] = ft::to_string(i) + ft::to_string(j);
            }
            i++;
        }

        for (i = 0; i < v.size(); i++) {
            for (j = 0; j < v[i].size(); j++) {
                v[i][j];
            }
        }
        end = clock();
        sec = double(end - start) / CLOCKS_PER_SEC;
        std::cout << green_bold("time = ") << sec << std::endl;
    }

    {
        std::cout << green("#2\n");
        typedef     version::set<std::string>  s;
        version::map<int, s>    m;

        start = clock();
        int i = 0, j = 0;
        while (i < 100) {
            for (j = 0; j < 100; j++) {
                m[i].insert(ft::to_string(i) + ft::to_string(j));
            }
            i++;
        }

        version::map<int, s>::iterator      it = m.begin(), it_end = m.end();
        s::iterator     it_set, it_set_end;
        while (it != it_end) {
            it_set = (*it).second.begin(), it_set_end = (*it).second.end();
            while (it_set != it_set_end) {
                *it_set;
                it_set++;
            }
            it++;
        }
        end = clock();
        
        sec = double(end - start) / CLOCKS_PER_SEC;
        std::cout << green_bold("time = ") << sec << std::endl;
    }
    
    {
        std::cout << green("#3\n");
        typedef     version::set<std::string>  s;
        version::map<int, s>    m;

        start = clock();
        int i = 0, j = 0;
        while (i < 10) {
            for (j = 0; j < 10; j++) {
                m[i].insert(ft::to_string(i) + ft::to_string(j));
            }
            i++;
        }
        i = 4; j = 4;
        while (i < 9) {
            for (j = 4; j < 9; j++) {
                m[i].erase(ft::to_string(i) + ft::to_string(j));
            }
            i++;
        }

        version::map<int, s>::iterator      it = m.begin(), it_end = m.end();
        s::iterator     it_set, it_set_end;
        while (it != it_end) {
            it_set = (*it).second.begin(), it_set_end = (*it).second.end();
            while (it_set != it_set_end) {
                *it_set;
                it_set++;
            }
            it++;
        }
        end = clock();
        sec = double(end - start) / CLOCKS_PER_SEC;
        std::cout << green_bold("time = ") << sec << "\n" << std::endl;
    }
}