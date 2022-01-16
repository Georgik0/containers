#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include <iostream>
#include <vector>

namespace   ft {

    template < class Type, class Alloc = std::allocator<Type> >
    class vector {
    private:
    
    public:
        typedef Type                                                            value_type;
        typedef Alloc                                                           allocator_type;
        
        typedef std::size_t                                                     size_type;
        typedef std::ptrdiff_t                                                  difference_type;
        
        typedef value_type&                                                     reference;
        typedef const value_type&                                               const_reference;
        
        typedef typename allocator_type::pointer                                pointer;
        typedef typename allocator_type::const_pointer                          const_pointer;

        typedef typename ft::vector_iterator<Type, Type*, Type&>                iterator;
        typedef typename ft::vector_iterator<Type, const Type*, const Type&>    const_iterator;
        typedef typename ft::reverse_iterator<iterator>                         reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator>                   const_reverse_iterator;
    public:
        vector();
        ~vector();
    };
}

#endif //VECTOR_HPP