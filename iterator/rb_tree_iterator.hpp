#ifndef RB_TREE_ITERATOR_HPP
#define RB_TREE_ITERATOR_HPP

#include "../utils/node.hpp"
#include "../iterator/iterator.hpp"

namespace   ft {
    
    template<class Type, class Ptr, class Ref>
    class rb_tree_iterator {
        public:
            typedef Type                                value_type;
            typedef Ptr                                 pointer;
            typedef Ref                                 reference;
            typedef bidirectional_iterator_tag          iterator_category; // в целом-то он не нужен
            typedef std::ptrdiff_t                      difference_type;
            typedef rb_tree_iterator<Type, Ptr, Ref>    rb_iter;
        private:
            node<value_type>                            *_ptr;

            bool    _is_not_nil_node(node<value_type> *n) {
                return !_is_nil_node(n);
            }

            bool    _is_nil_node(node<value_type> *n) {
                if (n->value == NULL && n->right == NULL && n->left == NULL)
                    return true;
                return false;
            }
        public:
            rb_tree_iterator() : _ptr(NULL) {}
            ~rb_tree_iterator() {}
            explicit    rb_tree_iterator(node<value_type> *ptr) : _ptr(ptr) {}
            rb_tree_iterator(rb_iter const &it) : _ptr(it.base()) {}
            
            node<value_type>    *base() const { return _ptr; }

            rb_iter &operator=(rb_iter const &iter) {
                if (this == &iter)
                    return *this;
                _ptr = iter.base();
                return *this;
            }

            reference   operator*() const { return *_ptr->value; }
            pointer     operator->() const { return _ptr->value; }

            rb_iter     &operator++() {
                if (_is_not_nil_node(_ptr->right)) {
                    _ptr = _ptr->right;
                    while (_is_not_nil_node(_ptr->left))
                        _ptr = _ptr->left;
                } else {
                    node<value_type>    *new_ptr = _ptr->parent, *tmp = _ptr;
                    while (_is_not_nil_node(new_ptr) && new_ptr->right == tmp) {
                        tmp = new_ptr;
                        new_ptr = new_ptr->parent;
                    }
                    _ptr = new_ptr;
                }
                return *this;
            }

            rb_iter     operator++(int) {
                rb_iter     tmp_it(*this);
                ++(*this);
                return  tmp_it;
            }

            rb_iter     &operator--() {
                if (_is_not_nil_node(_ptr->left)) {
                    _ptr = _ptr->left;
                    while (_is_not_nil_node(_ptr->right))
                        _ptr = _ptr->right;
                } else {
                    node<value_type>    *new_ptr = _ptr->parent, *tmp = _ptr;
                    while (_is_not_nil_node(new_ptr) && new_ptr->left == tmp) {
                        tmp = new_ptr;
                        new_ptr = new_ptr->parent;
                    }
                    _ptr = new_ptr;
                }
                return *this;
            }

            rb_iter     operator--(int) {
                rb_iter     tmp_it(*this);
                --(*this);
                return  tmp_it;
            }

            operator rb_tree_iterator<Type, const Type*, const Type&>() { return rb_tree_iterator<Type, const Type*, const Type&>(_ptr); }
    };

    template<class Type, class Ptr, class Ref>
    bool    operator==(rb_tree_iterator<Type, Ptr, Ref> const &lIt, rb_tree_iterator<Type, Ptr, Ref> const &rIt) {
        return  lIt.base() == rIt.base();
    }

    template<class Type, class Ptr, class Ref>
    bool    operator!=(rb_tree_iterator<Type, Ptr, Ref> const &lIt, rb_tree_iterator<Type, Ptr, Ref> const &rIt) {
        return  lIt.base() != rIt.base();
    }

}

#endif // RB_TREE_ITERATOR_HPP