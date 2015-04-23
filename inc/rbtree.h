#ifndef RB_TREE_H
#define RB_TREE_H
#include <iostream>
#include "tree.h"
#include "rbnode.h"

using namespace std;

class RBTree: public Tree
{
    public:
        RBNode *root;
        RBTree();
        virtual RBNode * get_root();
        virtual void set_root(RBNode *root_node);
        void insert_into_tree();
        //void delete_from_tree();
};
#endif
