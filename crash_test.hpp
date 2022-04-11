#ifndef CRASH_TEST_HPP
#define CRASH_TEST_HPP

#include "vector/vector.hpp"
#include "map/map.hpp"
#include "set/set.hpp"
#include "name_container.hpp"

class Boom {
    private:
        int             *i;
        std::string     *s;
    public:
        Boom() {}
        ~Boom() {}
};

#endif // CRASH_TEST_HPP