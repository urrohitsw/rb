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

class RBNode
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
        //void insert_node(RBTree *rbt);
        void insert_fixup(RBTree *rbt);
        //void delete_fixup(Tree *t);
        void print_node(ofstream &file);
        //void left_rotate_node(RBTree *rbt);
        //void right_rotate_node(RBTree *rbt);
};
#endif
