#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <memory>
#include "../utils/node.hpp"

namespace   ft {

    template<class Type, class Compare = std::less<Type>, class Alloc = std::allocator<Type>,
        class NodeAlloc = std::allocator<ft::node<Type> > >
    class rb_tree
    {
        public:
            typedef Type                                    value_type;
            typedef Alloc                                   alloc_type;
            typedef NodeAlloc                               node_alloc_type;

            typedef value_type&                             reference;
            typedef const value_type&                       const_reference;

            typedef typename alloc_type::pointer            pointer;
            typedef typename alloc_type::const_pointer      const_pointer;
    };

}

#endif // RB_TREE_HPP