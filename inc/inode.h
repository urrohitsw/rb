#ifndef INODE_H
#define INODE_H

class INode
{
#if 1
    /*
     * Finding the node in the tree given the data.
     * */
    template <class Node>
        Node * find_node(int data);
    /*
     * Function for inserting a node in Tree.
     * */
    template <class Node, class Tree>
        void insert_node(Node* cur_node, Tree* t);
    /*
     * Left Rotate the node with which this function is called.
     * */
    template <class Node, class Tree>
        void left_rotate_node(Node* cur_node, Tree *t);
    /*
     * Right Rotate the node with which this function is called.
     * */
    template <class Node, class Tree>
        void right_rotate_node(Node* cur_node, Tree *t);
    /*
     * Delete the calling node
     * */
    template <class Node, class Tree>
        void delete_node(Node* cur_node, Tree *t);
#endif
};
#endif