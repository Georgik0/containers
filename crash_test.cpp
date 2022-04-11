#include "crash_test.hpp"
#include <sstream>
#include <map>

std::string to_string(int a) {
    std::stringstream ss;
    ss << a;
    std::string str = ss.str();
    return str;
}

void    crash_test() {
    {
        typedef     version::map<int, std::string>  mis;
        version::vector<mis>    v(10);

        version::vector<mis>::reverse_iterator      rit_start = v.rbegin(), rit_end = v.rend();
        while (rit_start != rit_end) {
            for (int i = 0; i < 4; i++) {
                (*rit_start)[i] = to_string(i);
            }
            rit_start++;
        }

        version::vector<mis>::const_iterator    it_start = v.begin();
    }
}