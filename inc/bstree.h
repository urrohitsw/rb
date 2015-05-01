#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <time.h>
#include <algorithm>
#include "bsnode.h"

using namespace std;

class BSNode;

class BSTree
{
    protected:
        BSNode * root;
        list<int> treedata;
    public:
        BSTree();
        /*
         * Getter function.
         * */
        BSNode * get_root();
        /*
         * Setter function.
         * */
        void set_root(BSNode *root_node);
        /*
         * Used for random insertions in tree.
         * */
        void insert_into_tree();
        /*
         * Used for random deletions in tree.
         * */
        void delete_from_tree();
        /*
         * Test functon for writing the tree data to a file.
         * */
        void print_tree();
};

enum Operations
{
    /*
     * Insert.
     * */
    INSERT=1,
    /*
     * Delete.
     * */
    DELETE,
    /*
     * Left Rotate.
     * */
    LEFT_ROTATE,
    /*
     * Right Rotate.
     * */
    RIGHT_ROTATE,
    /*
     * Print.
     * */
    PRINT,
    /*
     * Exit.
     * */
    EXIT
};

#endif
