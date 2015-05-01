#ifndef RB_TREE_H
#define RB_TREE_H
#include <iostream>
#include "rbnode.h"
#include "bstree.h"

using namespace std;

class RBTree: public BSTree
{
    /* TODO Inheritance not properly used */
    public:
        RBNode *root;
        RBTree();
        RBNode * get_root();
        void set_root(RBNode *root_node);
        void insert_into_tree();
        void print_tree();
        //void delete_from_tree();
};
#endif
