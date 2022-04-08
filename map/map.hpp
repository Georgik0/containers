#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>
#include "../utils/pair.hpp"
#include "rb_tree.hpp"

namespace   ft {

    template<class Key, class Type, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, Type> > >
    class map {
        public:
            typedef Key                                                             key_type;
            typedef Type                                                            mapped_type;
            typedef typename    ft::pair<const key_type, mapped_type>               value_type;
            typedef Compare                                                         compare_type;
            typedef Alloc                                                           allocator_type;
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
            rb_tree<value_type, value_compare, allocator_type>                                          _tree;
        public:
            typedef std::size_t                                                                         size_type;
            typedef std::ptrdiff_t                                                                      difference_type;
            
            typedef value_type&                                                                         reference;
            typedef const value_type&                                                                   const_reference;
            
            typedef typename allocator_type::pointer                                                    pointer;
            typedef typename allocator_type::const_pointer                                              const_pointer;

            typedef typename ft::rb_tree_iterator<value_type, value_type*, value_type&>                 iterator;
            typedef typename ft::rb_tree_iterator<value_type, const value_type*, const value_type&>     const_iterator;

            typedef typename ft::reverse_iterator<iterator>                                             reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>                                       const_reverse_iterator;

        explicit    map(const compare_type &comp = compare_type(), const allocator_type &alloc = allocator_type()) : _tree(value_compare(comp), alloc) {}
        
        template<class InputIt>
        map(InputIt first, InputIt last, const compare_type &comp = compare_type(),
            const allocator_type &alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0) : _tree(first, last, value_compare(comp), alloc) {}

        map(const map &m) : _tree(m._tree.begin(), m._tree.end()) {}

        ~map() {}

        map &operator=(const map &m) {
            if (&m == this)
                return *this;
            _tree = m._tree;
        }

        mapped_type &operator[](const key_type &key) {
            value_type  p = ft::make_pair(key, mapped_type());
            ft::pair<iterator, bool>  result = insert(p);

            return (*result.v1).v2;
        }

        iterator    begin() { return _tree.begin(); }
        iterator    end() { return _tree.end(); }

        const_iterator  begin() const { return _tree.begin(); }
        const_iterator  end() const { return _tree.end(); }

        reverse_iterator    rbegin() { return _tree.rbegin(); }
        reverse_iterator    rend() { return _tree.rend(); }

        const_reverse_iterator    rbegin() const { return _tree.rbegin(); }
        const_reverse_iterator    rend() const { return _tree.rend(); }

        bool    empty() const { return _tree.empty(); }
        size_type   size() const { return _tree.size(); }
        size_type   max_size() const { return _tree.max_size(); }

        void    clear() { _tree.clear(); }
        ft::pair<iterator, bool>    insert(const_reference value) { return _tree.insert(value); }
        iterator    insert(iterator hint, const_reference value) { return _tree.insert(value).v1; }
        template<class InputIt>
        void    insert(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0) { _tree.insert(first, last); }

        void    erase(iterator pos) { _tree.erase(pos); }

    };
}

#endif //MAP_HPP