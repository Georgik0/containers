#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include <memory>
#include "../utils/node.hpp"
#include "../utils/pair.hpp"
#include "../utils/utils.hpp"
#include "../iterator/rb_tree_iterator.hpp"
#include "../iterator/reverse_iterator.hpp"

namespace   ft {

    template<class Type, class Compare = std::less<Type>, class Alloc = std::allocator<Type>,
        class NodeAlloc = std::allocator<ft::node<Type> > >
    class rb_tree
    {
        public:
            typedef Type                                                            value_type;
            typedef Compare                                                         compare_type; // compare(a, b)=true <=> (a < b)
            
            typedef Alloc                                                           alloc_type;
            typedef NodeAlloc                                                       node_alloc_type;

            typedef std::size_t                                                     size_type;

            typedef value_type&                                                     reference;
            typedef const value_type&                                               const_reference;

            typedef typename alloc_type::pointer                                    pointer;
            typedef typename alloc_type::const_pointer                              const_pointer;

            typedef typename ft::rb_tree_iterator<Type, Type*, Type&>               iterator;
            typedef typename ft::rb_tree_iterator<Type, const Type*, const Type&>   const_iterator;

            typedef typename ft::reverse_iterator<iterator>                         reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>                   const_reverse_iterator;
        private:
            compare_type        _compare;
            alloc_type          _alloc;
            node_alloc_type     _node_alloc;
            node<value_type>    *_root;
            node<value_type>    *_nil;
            size_type           _size;

            void    _left_rotate(node<value_type> *x) {
                node<value_type>    *y = x->right;
                x->right = y->left;

                if (y->left != _nil)
                    y->left->parent = x;
                y->parent = x->parent;
                if (x->parent == _nil)
                    _root = y;
                else if (x == x->parent->left)
                    x->parent->left = y;
                else
                    x->parent->right = y;
                y->left = x;
                x->parent = y;
            }

            void    _right_rotate(node<value_type> *y) {
                node<value_type>    *x = y->left;
                y->left = x->right;

                if (x->right != _nil)
                    x->right->parent = y;
                x->parent = y->parent;
                if (y->parent == _nil)
                    _root = x;
                else if (y == y->parent->right)
                    y->parent->right = x;
                else
                    y->parent->left = x;
                x->right = y;
                y->parent = x;
            }

            void    _rb_insert(node<value_type> *z) {
                node<value_type>    *y = _nil, *x = _root;

                while (x != _nil) {
                    y = x;
                    if (*z->value == *x->value)
                        return;
                    else if (_compare(*z->value, *x->value))
                        x = x->left;
                    else
                        x = x->right;
                }
                z->parent = y;
                if (y == _nil)
                    _root = z;
                else if (_compare(*z->value, *y->value))
                    y->left = z;
                else
                    y->right = z;
                z->left = _nil;
                z->right = _nil;
                z->color = RED;
                _rb_insert_fixup(z);
            }

            void    _rb_insert_fixup(node<value_type> *z) {
                node<value_type>    *y; 
                while (z->parent->color == RED) {
                    if (z->parent == z->parent->parent->left) {
                        y = z->parent->parent->right;
                        if (y->color == RED) {
                            z->parent->color = BLACK;
                            y->color = BLACK;
                            z->parent->parent->color = RED;
                            z = z->parent->parent;
                        } else {
                            if (z == z->parent->right) {
                                z = z->parent;
                                _left_rotate(z);
                            }
                            z->parent->color = BLACK;
                            z->parent->parent->color = RED;
                            _right_rotate(z->parent->parent);
                        }
                    } else {
                        y = z->parent->parent->left;
                        if (y->color == RED) {
                            z->parent->color = BLACK;
                            y->color = BLACK;
                            z->parent->parent->color = RED;
                            z = z->parent->parent;
                        } else {
                            if (z == z->parent->left) {
                                z = z->parent;
                                _right_rotate(z);
                            }
                            z->parent->color = BLACK;
                            z->parent->parent->color = RED;
                            _left_rotate(z->parent->parent);
                        }
                    }
                }
                _root->color = BLACK;
            }

        public:
            explicit    rb_tree(const compare_type compare = compare_type(), const alloc_type &alloc = alloc_type(),
                            const node_alloc_type &node_alloc = node_alloc_type()) : 
                                _compare(compare), _alloc(alloc), _node_alloc(node_alloc), _root(NULL), _size(0) {
                _nil = _node_alloc.allocate(1);
                _node_alloc.construct(_nil, node<value_type>(NULL));
            }

            ~rb_tree() {
                _clear(_root);
                _node_alloc.destroy(_nil);
                _node_alloc.deallocate(_nil, 1);
            }

            rb_tree(rb_tree const &copy) :
                    _compare(copy._compare), _alloc(copy._alloc), _node_alloc(copy._node_alloc), _size(copy._size) {
                _nil = _node_alloc.allocate(1);
                _node_alloc.construct(_nil, node<value_type>(NULL));
                insert(copy.begin(), copy.end());
            }

            rb_tree     &operator=(const rb_tree &copy) {
                if (this == &copy)
                    return *this;
                _compare = copy._compare;
                _alloc = copy._alloc;
                _node_alloc = copy._node_alloc;
                _size = copy._size;
                _nil = _node_alloc.allocate(1);
                _node_alloc.construct(_nil, node<value_type>(NULL));
                insert(copy.begin(), copy.end());
            }

            template<class InputIt>
            rb_tree(InputIt first, InputIt last, const compare_type compare = compare_type(),
                const alloc_type &alloc = alloc_type(), const node_alloc_type &node_alloc = node_alloc_type()) :
                    _compare(compare), _alloc(alloc), _node_alloc(node_alloc), _root(NULL), _size(0) {
                _nil = _node_alloc.allocate(1);
                _node_alloc.construct(_nil, node<value_type>(NULL));
                insert(first, last);
            }

            iterator    begin() {
                if (_root == NULL)
                    return iterator(_nil);
                node<value_type>    *tmp = _root;
                while (tmp->left != _nil)
                    tmp = tmp->left;
                return iterator(tmp);
            }
            iterator    end() { return iterator(_nil); }

            const_iterator  begin() const {
                if (_root == NULL)
                    return const_iterator(_nil);
                node<value_type>    *tmp = _root;
                while (tmp->left != _nil)
                    tmp = tmp->left;
                return const_iterator(tmp);
            }
            const_iterator  end() const { return const_iterator(_nil); }

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

                n->parent = _nil;
                n->left = _nil;
                n->right = _nil;

                if (_root == NULL) {
                    _size++;
                    _root = n;
                    return make_pair(begin(), true);
                }
                _rb_insert(n);
                return make_pair(iterator(n), true);
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
                if (n != _nil) {
                    _alloc.destroy(n->value);
                    _alloc.deallocate(n->value, 1);
                    _node_alloc.destroy(n);
                    _node_alloc.deallocate(n, 1);
                }
            }
    };

}

#endif // RB_TREE_HPP