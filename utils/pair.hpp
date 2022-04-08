#ifndef PAIR_HPP
#define PAIR_HPP

namespace   ft {

    template<class T1, class T2>
    struct pair {
        typedef T1  type1;
        typedef T2  type2;

        type1   v1;
        type2   v2;

        pair() : v1(), v2() {}
        pair(const type1 &u1, const type2 &u2) : v1(u1), v2(u2) {}

        template<class U1, class U2>
        pair(const pair<U1,U2> &pr) : v1(pr.v1), v2(pr.v2) {}

        pair    &operator=(const pair &pr) {
            if (&pr == this)
                return *this;
            v1 = pr.v1;
            v2 = pr.v2;
            return *this;
        }
    };

    template<class T1, class T2>
    bool    operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return lhs.v1 == rhs.v1 && lhs.v2 == rhs.v2;
    }
    
    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return !(lhs == rhs);
    }
    
    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
        return lhs.v1 < rhs.v1 || (lhs.v1 == rhs.v1 && lhs.v1 < rhs.v2);
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