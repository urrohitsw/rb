#ifndef BSNODE_H
#define BSNODE_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "inode.h"

using namespace std;

class BSNode
{
    protected:
        int data;
        BSNode *left;
        BSNode *right;
        BSNode *parent;
    public:
        BSNode();
        BSNode(int data);
        friend class INode;
        /*
         * Function for printing a nodes's data.
         * */
        void print_node(ofstream &file);
};

#endif
