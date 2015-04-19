#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <time.h>
#include <algorithm>

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
         * Function for printing a nodes's data
         * */
        void print_node(ofstream &file);
        Node * find_node(int data);
        void insert_node(Tree *t);
        void left_rotate_node(Tree *t);
        void delete_node(Tree *t);
};

class Tree
{
    protected:
        Node * root;
        list<int> treedata;
    public:
        Tree();
        /*
         * Getter function.
         * */
        Node * get_root();
        /*
         * Setter function.
         * */
        void set_root(Node *root_node);
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

