#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace   ft {

    template<class T, class Container = ft::vector<T> >
    class   stack {
        public:
            typedef T           value_type;
            typedef Container   container_type;
            typedef size_t      size_type;
        protected:
            container_type      _ctr;
        public:
            explicit    stack(const container_type &ctr = container_type()) : _ctr(ctr) {}
            stack   &operator=( const stack& other ) {
                if (this == &other)
                    return *this;
                _ctr = other._ctr;
                return *this;
            }

            bool    empty() const { return _ctr.empty(); }
            size_type   size() const { return _ctr.size(); }

            const value_type  &top() const { return _ctr.back(); }
            value_type  &top() { return _ctr.back(); }

            void    push(const value_type &value) { _ctr.push_back(value); }
            void    pop() { _ctr.pop_back(); }
    };

    template <class T, class C>
  	bool operator==(const stack<T,C>& lhs, const stack<T,C>& rhs) {
        return lhs._ctr == rhs._ctr;
	}

    template <class T, class C>
  	bool operator!=(const stack<T,C>& lhs, const stack<T,C>& rhs) {
        return lhs._ctr != rhs._ctr;
	}

    template <class T, class C>
  	bool operator<(const stack<T,C>& lhs, const stack<T,C>& rhs) {
        return lhs._ctr < rhs._ctr;
	}

    template <class T, class C>
  	bool operator<=(const stack<T,C>& lhs, const stack<T,C>& rhs) {
        return lhs._ctr <= rhs._ctr;
	}

    template <class T, class C>
  	bool operator>(const stack<T,C>& lhs, const stack<T,C>& rhs) {
        return lhs._ctr > rhs._ctr;
	}

    template <class T, class C>
  	bool operator>=(const stack<T,C>& lhs, const stack<T,C>& rhs) {
        return lhs._ctr >= rhs._ctr;
	}
}

#endif //STACK_HPP