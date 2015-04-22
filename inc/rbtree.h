#ifndef RB_TREE_H
#define RB_TREE_H
#include <iostream>
#include "tree.h"

using namespace std;

class RBTree: public Tree
{
    public:
        RBTree();
        void insert_into_tree();
        //void delete_from_tree();
};
#endif
