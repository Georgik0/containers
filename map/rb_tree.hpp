#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <memory>
#include "../utils/node.hpp"
#include "../utils/pair.hpp"
#include "../iterator/rb_tree_iterator.hpp"
#include "../iterator/reverse_iterator.hpp"

namespace   ft {

    template<class Type, class Compare = std::less<Type>, class Alloc = std::allocator<Type>, 
        class NodeAlloc = std::allocator<ft::node<Type> > >
    class rb_tree
    {
        public:
            typedef Type                                                            value_type;
            typedef Compare                                                         compare_type;
            
            typedef Alloc                                                           alloc_type;
            typedef NodeAlloc                                                       node_alloc_type;

            typedef std::size_t                                                     size_type;

            typedef value_type&                                                     reference;
            typedef const value_type&                                               const_reference;

            typedef typename alloc_type::pointer                                    pointer;
            typedef typename alloc_type::const_pointer                              const_pointer;

            typedef typename ft::rb_tree_iterator<Type, Type*, Type&>               iterator;
            typedef typename ft::rb_tree_iterator<Type, const Type*, const Type&>   const_iterator;

            typedef typename ft::reverse_iterator<Type, Type*, Type&>               reverse_iterator;
            typedef typename ft::reverse_iterator<Type, const Type*, const Type&>   const_reverse_iterator;
        private:
            compare_type        _compare;
            alloc_type          _alloc;
            node_alloc_type     _node_alloc;
            node<value_type>    *_root;
            node<value_type>    *_end;
            size_type           _size;
        public:
            explicit    rb_tree(const compare_type compare = compare_type(), const alloc_type &alloc = alloc_type(),
                            const node_alloc_type &node_alloc = node_alloc_type()) : 
                                _compare(compare), _alloc(alloc), _node_alloc(node_alloc), _root(NULL), _size(0) {
                _end = _node_alloc.allocate(1);
                _node_alloc.construct(_end, node<value_type>(NULL));
            }

            ~rb_tree() {
                _clear(_root);
                _node_alloc.destroy(_end);
                _node_alloc.deallocate(_end, 1);
            }

            rb_tree(rb_tree const &copy) :
                    _compare(copy._compare), _alloc(copy._alloc), _node_alloc(copy._node_alloc), _size(copy._size) {
                _end = _node_alloc.allocate(1);
                _node_alloc.construct(_end, node<value_type>(NULL));
                insert(copy.begin(), copy.end());
            }

            rb_tree     &operator=(const rb_tree &copy) {
                if (this == &copy)
                    return *this;
                _compare = copy._compare;
                _alloc = copy._alloc;
                _node_alloc = copy._node_alloc;
                _size = copy._size;
                _end = _node_alloc.allocate(1);
                _node_alloc.construct(_end, node<value_type>(NULL));
                insert(copy.begin(), copy.end());
            }

            template<class InputIt>
            rb_tree(InputIt first, InputIt last, const compare_type compare = compare_type(),
                const alloc_type &alloc = alloc_type(), const node_alloc_type &node_alloc = node_alloc_type()) :
                    _compare(compare), _alloc(alloc), _node_alloc(node_alloc), _root(NULL), _size(0) {
                _end = _node_alloc.allocate(1);
                _node_alloc.construct(_end, node<value_type>(NULL));
                insert(first, last);
            }

            iterator    begin() {
                if (_root == NULL)
                    return iterator(_end);
                node<value_type>    *tmp = _root;
                while (tmp->left)
                    tmp = tmp->left;
                return iterator(tmp);
            }
            iterator    end() { return iterator(_end); }

            const_iterator  begin() const {
                if (_root == NULL)
                    return const_iterator(_end);
                node<value_type>    *tmp = _root;
                while (tmp->left)
                    tmp = tmp->left;
                return const_iterator(tmp);
            }
            const_iterator  end() const { return const_iterator(_end); }

            reverse_iterator    rbegin() { return reverse_iterator(begin()); }
            reverse_iterator    rend() { return reverse_iterator(end()); }

            const_reverse_iterator  rbegin() const { return const_reverse_iterator(begin()); }
            const_reverse_iterator  rend() const { return const_reverse_iterator(end()); }

            bool    empty() { return _size == 0; }
            size_type    size() { return _size; }

            size_type   max_size() {
                size_type   max_alloc = _alloc.max_size(), max_node_alloc = _node_alloc.max_size();
                if (max_alloc > max_node_alloc)
                    return max_node_alloc;
                return max_alloc;
            }

            pair<iterator, bool>    insert(const_reference value) {
                pointer tmp = _alloc.allocate(1);
                _alloc.construct(tmp, value);

                node<value_type>    *n = _node_alloc.allocate(1);
                _node_alloc.construct(n, node<value_type>(tmp));

                if (_root == NULL) {
                    _root = n;
                    _root->parent = NULL;
                }
            }

            template<class InputIt>
            void    insert(InputIt first, InputIt last,
                        typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0) {
                
            }

        private:
            void    _clear(node<value_type> *n) {
                if (n == NULL)
                    return;
                _clear(n->left);
                _clear(n->right);
                _alloc.destroy(n->value);
                _alloc.deallocate(n->value, 1);
                _node_alloc.destroy(n);
                _node_alloc.deallocate(n, 1);
            }
    };

}

#endif // RB_TREE_HPP