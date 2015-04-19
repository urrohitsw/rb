#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "tree.h"

using namespace std;

class Tree;

class Node
{
    private:
        int data;
        Node *left;
        Node *right;
        Node *parent;
    public:
        Node();
        Node(int data);
        /*
         * Function for printing a nodes's data.
         * */
        void print_node(ofstream &file);
        /*
         * Finding the node in the tree given the data.
         * */
        Node * find_node(int data);
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
};

#endif
