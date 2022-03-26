#ifndef RB_TREE_ITERATOR_HPP
#define RB_TREE_ITERATOR_HPP

#include "../utils/node.hpp"
#include "../iterator/iterator.hpp"

namespace   ft {
    
    template<class Type, class Ptr, class Ref>
    class rb_tree_iterator : public iterator<bidirectional_iterator_tag, Type> {
        public:
            typedef Type                                value_type;
            typedef Ptr                                 pointer;
            typedef Ref                                 reference;
            typedef bidirectional_iterator_tag          iterator_category; // в целом-то он не нужен
            typedef std::ptrdiff_t                      difference_type;
            typedef rb_tree_iterator<Type, Ptr, Ref>    rb_iter;
        private:
            node<value_type>                            *_ptr;
        public:
            rb_tree_iterator() : _ptr(NULL) {}
            virtual ~rb_tree_iterator() {}
            explicit    rb_tree_iterator(node<value_type> *ptr) : _ptr(ptr) {}
            rb_tree_iterator(rb_iter const &it) : _ptr(it.base()) {}
            
            node<value_type>    *base() const { return _ptr }

            rb_iter &operator=(rb_iter const &iter) {
                if (this == &iter)
                    return *this;
                _ptr = iter.base();
                return *this;
            }

            reference   operator*() const { return *_ptr->value; }
            pointer     operator->() const { return _ptr->value; }

            rb_iter     &operator++() {
                if (_ptr->right != NULL) {
                    _ptr = _ptr->right;
                    while (_ptr->left)
                        _ptr = _ptr->left;
                } else {
                    
                }
                
            }
    };

}

#endif // RB_TREE_ITERATOR_HPP