#include<iostream>
#include<fstream>

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
        void print_node();
        void insert_node(Tree *t);
};

class Tree
{
    private:
        Node * root;
    public:
        Tree();
        //delete_node(Node *input_node);
        Node * get_root();
        void set_root(Node *root_node);
        void print_tree();
};

using namespace std;
