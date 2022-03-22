#ifndef NODE_HPP
#define NODE_HPP

#define BLACK   true
#define RED     false

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
            color = true;
        }
    };
}

#endif // NODE_HPP