#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft {
    template<class Category, class Type, class Dist = std::ptrdiff_t, class Ptr = Type *, class Ref = Type &>
    struct iterator {
        typedef Category iterator_category;
        typedef Type value_type;
        typedef Dist difference_type;
        typedef Ptr pointer;
        typedef Ref reference;
    };

    struct input_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template<class It>
    struct iterator_traits {
        typedef typename It::iterator_category iterator_category;
        typedef typename It::value_type value_type;
        typedef typename It::difference_type difference_type;
        typedef typename It::pointer pointer;
        typedef typename It::reference reference;
    };

    template<class T>
    struct iterator_traits<T *> {
        typedef random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
    };
}

#endif //ITERATOR_HPP