#ifndef BSNODE_H
#define BSNODE_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "inode.h"

using namespace std;

class BSNode:public INode
{
    protected:
        int data;
        BSNode *left;
        BSNode *right;
        BSNode *parent;
    public:
        BSNode();
        BSNode(int data);
        /*
         * Function for printing a nodes's data.
         * */
        void print_node(ofstream &file);
#if 0
        /*
         * Finding the node in the tree given the data.
         * */
        BSNode * find_node(int data);
        /*
         * Function for inserting a node in Tree.
         * */
        void insert_node(Tree *t);
        /*
         * Left Rotate the node with which this function is called.
         * */
        void left_rotate_node(Tree *t);
        /*
         * Right Rotate the node with which this function is called.
         * */
        void right_rotate_node(Tree *t);
        /*
         * Delete the calling node
         * */
        void delete_node(Tree *t);
#endif
};

#endif
