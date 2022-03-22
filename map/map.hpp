#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>
#include "pair.hpp"

namespace   ft {

    template<class Key, class Type, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, Type> > >
    class map {
        public:
            typedef Key                                                             key_type;
            typedef Type                                                            mapped_type;
            typedef typename    ft::pair<const key_type, mapped_type>               value_type;
            typedef Compare                                                         key_compare;
        private:
            class value_compare {
                friend class map;
                protected:
                    Compare _comp;
                    value_compare(Compare c) : _comp(c) {}
                public:
                    typedef value_type  first_argument_type;
                    typedef value_type  second_argument_type;
                    bool operator()(const value_type &x, const value_type &y) const {
                        return _comp(x.v1, y.v1);
                    }
            };
        public:
            typedef Alloc                                                           allocator_type;
            
            typedef std::size_t                                                     size_type;
            typedef std::ptrdiff_t                                                  difference_type;
            
            typedef value_type&                                                     reference;
            typedef const value_type&                                               const_reference;
            
            typedef typename allocator_type::pointer                                pointer;
            typedef typename allocator_type::const_pointer                          const_pointer;

    };
}

#endif //MAP_HPP