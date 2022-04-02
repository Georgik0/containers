#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "iterator.hpp"

namespace ft {
    template <class Type, class Ptr, class Ref>
    class vector_iterator {
    public:
        typedef Type                            value_type;
        typedef Ptr                             pointer;
        typedef Ref                             reference;
        typedef random_access_iterator_tag      iterator_category;
        typedef ptrdiff_t                       difference_type;
        typedef vector_iterator<Type, Ptr, Ref> v_iter;

        vector_iterator() : _ptr(0) {}
        explicit vector_iterator(pointer ptr) : _ptr(ptr) {}
        vector_iterator(const v_iter &iter) : _ptr(iter._ptr) {}
        ~vector_iterator() {}

        v_iter     &operator=(const v_iter &iter) {
            if (this == &iter)
                return *this;
            _ptr = iter.base();
            return *this;
        }

        reference operator*() { return *_ptr; }
        pointer operator->() { return _ptr; }
        reference operator[](difference_type id) { return _ptr[id]; }

        v_iter  &operator++() {++_ptr; return *this;}
        v_iter  &operator--() {--_ptr; return *this;}
        v_iter  operator++(int) { v_iter tmp(*this); ++_ptr; return tmp;}
        v_iter  operator--(int) { v_iter tmp(*this); --_ptr; return tmp;}

        v_iter  operator+(difference_type offset) { return v_iter(_ptr + offset); }
        v_iter  operator-(difference_type offset) { return v_iter(_ptr - offset); }
        
        v_iter  &operator+=(difference_type offset) { _ptr += offset; return *this; }
        v_iter  &operator-=(difference_type offset) { _ptr -= offset; return *this; }

        bool    operator==(v_iter const &iter) { return _ptr == iter._ptr; }
        bool    operator!=(v_iter const &iter) { return _ptr != iter._ptr; }
        bool    operator>(v_iter const &iter) { return _ptr > iter._ptr; }
        bool    operator<(v_iter const &iter) { return _ptr < iter._ptr; }
        bool    operator<=(v_iter const &iter) { return _ptr <= iter._ptr; }
        bool    operator>=(v_iter const &iter) { return _ptr >= iter._ptr; }


        pointer     base() const { return _ptr; }

    private:
        pointer     _ptr;
    };

    template <class Type, class Ref, class Ptr>
    vector_iterator<Type, Ref, Ptr> operator+(
        typename vector_iterator<Type, Ref, Ptr>::difference_type offset, 
        vector_iterator<Type, Ref, Ptr> &rhs) {
        return rhs + offset;
    }

    template <class Type, class Ref, class Ptr>
    typename vector_iterator<Type, Ref, Ptr>::difference_type operator-(
        const vector_iterator<Type, Ref, Ptr> &lhs, 
        const vector_iterator<Type, Ref, Ptr> &rhs) {
        return lhs.base() - rhs.base();
    }

    template <class Type, class Ref, class Ptr>
    bool operator==(
        const vector_iterator<Type, Ref, Ptr> &lhs, 
        const vector_iterator<Type, Ref, Ptr> &rhs) {
        return lhs.base() == rhs.base();
    }

    template <class Type, class Ref, class Ptr>
    bool operator!=(
        const vector_iterator<Type, Ref, Ptr> &lhs, 
        const vector_iterator<Type, Ref, Ptr> &rhs) {
        return lhs.base() != rhs.base();
    }

    template <class Type, class Ref, class Ptr>
    bool operator>=(
        const vector_iterator<Type, Ref, Ptr> &lhs, 
        const vector_iterator<Type, Ref, Ptr> &rhs) {
        return lhs.base() >= rhs.base();
    }

    template <class Type, class Ref, class Ptr>
    bool operator<=(
        const vector_iterator<Type, Ref, Ptr> &lhs, 
        const vector_iterator<Type, Ref, Ptr> &rhs) {
        return lhs.base() <= rhs.base();
    }

    template <class Type, class Ref, class Ptr>
    bool operator>(
        const vector_iterator<Type, Ref, Ptr> &lhs, 
        const vector_iterator<Type, Ref, Ptr> &rhs) {
        return lhs.base() > rhs.base();
    }

    template <class Type, class Ref, class Ptr>
    bool operator<(
        const vector_iterator<Type, Ref, Ptr> &lhs, 
        const vector_iterator<Type, Ref, Ptr> &rhs) {
        return lhs.base() < rhs.base();
    }
}

#endif //VECTOR_ITERATOR_HPP