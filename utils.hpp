#ifndef UTILS_HPP
#define UTILS_HPP

namespace   ft {

    template<class InputIt>
    bool lexicographical_compare( InputIt first1, InputIt last1, InputIt first2, InputIt last2 ) {
        while (first1 <= last1) {
            if (first2 >= last2 || *first1 > *first2)
                return false;
            if (*first1 < *first2)
                return true;
            first1++;
            first2++;
        }
        return first2 != last2;
    }

    template <bool B, typename U, typename V>
    struct conditional {
        typedef V type;
    };

    template <typename U, typename V>
    struct conditional<true, U, V> {
        typedef U type;
    };

    template <bool B, typename T = void>
    struct enable_if {};

    template <typename T>
    struct enable_if<true, T> {
        typedef T type;
    };

    template< class T >
    struct is_integral {
        static const bool value = false;
    };

    template<>
    struct is_integral<bool> {
        static const bool value = true;
    };

    template<>
    struct is_integral<char> {
        static const bool value = true;
    };

    template<>
    struct is_integral<char16_t> {
        static const bool value = true;
    };

    template<>
    struct is_integral<char32_t> {
        static const bool value = true;
    };

    template<>
    struct is_integral<wchar_t> {
        static const bool value = true;
    };

    template<>
    struct is_integral<short> {
        static const bool value = true;
    };

    template<>
    struct is_integral<int> {
        static const bool value = true;
    };

    template<>
    struct is_integral<long> {
        static const bool value = true;
    };

    template<>
    struct is_integral<long long> {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned char> {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned short> {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned int> {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned long> {
        static const bool value = true;
    };

    template<>
    struct is_integral<unsigned long long> {
        static const bool value = true;
    };
}

#endif  // UTILS_HPP