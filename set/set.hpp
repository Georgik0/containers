#ifndef SET_HPP
#define SET_HPP

#include "../utils/pair.hpp"
#include "../map/rb_tree.hpp"

namespace   ft {
    template<class Type, class Compare = std::less<Type>, class Alloc = std::allocator<Type> >
    class set : public rb_tree<Type, Compare, Alloc> {
        public:
            typedef Type    key_type;
            typedef Type    value_type;
            typedef Compare compare_type;
            typedef Compare value_compare;
            typedef Alloc   allocator_type;

            explicit    set(const compare_type &comp = compare_type(), const allocator_type &alloc = allocator_type()) : rb_tree<Type, Compare, Alloc>(comp, alloc) {}

            template<class InputIt>
            set(InputIt first, InputIt last, const compare_type &comp = compare_type(), const allocator_type &alloc = allocator_type()) : rb_tree<Type, Compare, Alloc>(first, last, comp, alloc) {}

            set(set const &s) : rb_tree<Type, Compare, Alloc>(s) {}

            virtual ~set() {}

            set &operator=(const set &s) {
                rb_tree<Type, Compare, Alloc>::operator=(s);
                return *this;
            }

            compare_type    key_comp() const { return compare_type(); }
            value_compare   value_comp() const { return value_compare(); }
    };
};

#endif // SET_HPP