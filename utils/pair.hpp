#ifndef PAIR_HPP
#define PAIR_HPP

namespace   ft {

    template<class T1, class T2>
    struct pair {
        typedef T1  type1;
        typedef T2  type2;

        type1   first;
        type2   second;

        pair() : first(), second() {}
        pair(const type1 &u1, const type2 &u2) : first(u1), second(u2) {}

        template<class U1, class U2>
        pair(const pair<U1,U2> &pr) : first(pr.first), second(pr.second) {}

        pair    &operator=(const pair &pr) {
            if (&pr == this)
                return *this;
            first = pr.first;
            second = pr.second;
            return *this;
        }
    };

    template<class T1, class T2>
    bool    operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }
    
    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return !(lhs == rhs);
    }
    
    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.first < rhs.second);
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return lhs < rhs || lhs == rhs;
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return rhs < lhs;
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return !(lhs < rhs);
    }

    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y) {
        return pair<T1, T2>(x, y);
    }
}

#endif //PAIR_HPP