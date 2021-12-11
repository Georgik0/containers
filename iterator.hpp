//
// Created by egor on 10.12.2021.
//

#ifndef CONTAINERS_ITERATOR_HPP
#define CONTAINERS_ITERATOR_HPP

#include <cstddef>

template<class Category, class Type, class Dist = std::ptrdiff_t, class Ptr = T *, class Ref = T&>
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
            typedef ptrdiff_t distance_type;
            typedef T *pointer;
            typedef T& reference;
        };

/* стр. 104 */
template<class RanIt>
        class reverse_iterator : public iterator<
                typename iterator_traits<RanIt>::iterator_category,
                typename iterator_traits<RanIt>::value_type,
                typename iterator_traits<RanIt>::difference_type,
                typename iterator_traits<RanIt>::pointer,
                typename iterator_traits<RanIt>::reference> {
        protected:
            RanIt valueIt;
        public:
            typedef reverse_iterator<RanIt> RvIter;
            typedef typename iterator_traits<RanIt>::difference_type difference_type;
            typedef typename iterator_traits<RanIt>::pointer pointer;
            typedef typename iterator_traits<RanIt>::reference reference;
            typedef RanIt iter_type;
            reverse_iterator() : valueIt(0);
            explicit reverse_iterator(RanIt it) : valueIt(it) {};

        };

class iterator {

};


#endif //CONTAINERS_ITERATOR_HPP