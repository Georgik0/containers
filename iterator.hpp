//
// Created by egor on 10.12.2021.
//

#ifndef CONTAINERS_ITERATOR_HPP
#define CONTAINERS_ITERATOR_HPP

#include <cstddef>

namespace ft
{
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

    /* стр. 104 */
    template<class Iter>
    class reverse_iterator : public iterator<
            typename iterator_traits<Iter>::iterator_category,
            typename iterator_traits<Iter>::value_type,
            typename iterator_traits<Iter>::difference_type,
            typename iterator_traits<Iter>::pointer,
            typename iterator_traits<Iter>::reference> {
    protected:
        Iter value_it;
    public:
        typedef reverse_iterator<Iter> RvIter;
        typedef typename iterator_traits<Iter>::difference_type difference_type;
        typedef typename iterator_traits<Iter>::pointer pointer;
        typedef typename iterator_traits<Iter>::reference reference;
        typedef Iter iter_type;

        reverse_iterator() : value_it(0) {}

        explicit reverse_iterator(Iter it) : value_it(it) {}

        template<class U>
        reverse_iterator(const reverse_iterator<U> &X) : value_it(X.base()) {}

        template<class U>
        reverse_iterator &operator=(const reverse_iterator<U> &other) {
            if (this != other)
                this->value_it = other.base();
            return *this;
        }

        Iter base() const { return value_it; }

        reference operator*() const {
            Iter tmp = value_it;
            return *--tmp;
        }

        pointer operator->() const { return *this; }

        reference operator[](difference_type N) const { return (base()[-N - 1]); }

        iter_type &operator++() {
            --value_it;
            return *this;
        }

        iter_type operator++(int) {
            iter_type tmp = *this;
            --value_it;
            return tmp;
        }

        iter_type &operator+=(difference_type N) {
            value_it -= N;
            return *this;
        }

        iter_type operator+(difference_type N) { return reverse_iterator<Iter>(base() - N); }

        iter_type &operator--() {
            ++value_it;
            return (*this);
        }

        iter_type operator--(int) {
            iter_type tmp = *this;
            ++value_it;
            return tmp;
        }

        iter_type &operator-=(difference_type N) {
            value_it += N;
            return *this;
        }

        iter_type operator-(difference_type N) { return reverse_iterator<Iter>(base() + N); }
    };

    template<class Iterator1, class Iterator2>
    bool operator==(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs) {
        return lhs.base() == rhs.base();
    }

    template<class Iterator1, class Iterator2>
    bool operator!=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs) {
        return lhs.base() != rhs.base();
    }

    template<class Iterator1, class Iterator2>
    bool operator<(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs) {
        return lhs.base() < rhs.base();
    }

    template<class Iterator1, class Iterator2>
    bool operator<=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs) {
        return lhs.base() <= rhs.base();
    }

    template<class Iterator1, class Iterator2>
    bool operator>(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs) {
        return lhs.base() > rhs.base();
    }

    template<class Iterator1, class Iterator2>
    bool operator>=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs) {
        return lhs.base() >= rhs.base();
    }

    template<class Iter>
    reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type N, const reverse_iterator<Iter> &it) {
        return reverse_iterator<Iter>(it.base() - N);
    }

    template<class Iter>
    reverse_iterator<Iter> operator-(typename reverse_iterator<Iter>::difference_type N, const reverse_iterator<Iter> &it) {
        return reverse_iterator<Iter>(it.base() + N);
    }

}

#endif //CONTAINERS_ITERATOR_HPP
