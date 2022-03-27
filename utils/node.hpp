#ifndef NODE_HPP
#define NODE_HPP

#define BLACK   false
#define RED     true

namespace   ft {

    template<class Type>
    struct node {
        Type    *value;
        bool    color;
        node    *left;
        node    *right;
        node    *parent;

        node(Type *val) {
            value = val;
            left = right = parent = NULL;
            color = BLACK;
        }
    };
}

#endif // NODE_HPP