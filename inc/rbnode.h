#ifndef RB_NODE_H
#define RB_NODE_H

#include <iostream>
#include "node.h"

enum Color
{
    RED,
    BLACK
};

class RBTree;

class RBNode: public Node
{
    protected:
        /* TODO Try to use Nodes pointers */
        RBNode *left;
        RBNode *right;
        RBNode *parent;
        Color color;
    public:
        RBNode();
        RBNode(int data);
        RBNode(int data,Color color);
        void insert_fixup(RBTree *rbt);
        //void delete_fixup(Tree *t);
        //void print_node();
};
#endif
