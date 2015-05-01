#include "inode.h"

template <class Node>
Node * INode::find_node(Node *cur_node, int data)
{
    while(NULL != cur_node)
    {
        if(data == cur_node->data)
        {
            return cur_node;
        }
        else if(data < cur_node->data)
        {
            cur_node = cur_node->left;
        }
        else
        {
            cur_node = cur_node->right;
        }
    }
    return cur_node;
}

template <class Node, class Tree>
void INode::insert_node(Node *new_node, Tree *t)
{
    Node *cur_node = t->get_root();
    Node *prev_node;
    while(NULL != cur_node)
    {
        prev_node = cur_node;
        if(new_node->data < cur_node->data)
        {
            cur_node = cur_node->left;
        }
        else
        {
            cur_node = cur_node->right;
        }
    }

    if(NULL == t->get_root())
    {
        cur_node = new_node;
        t->set_root(cur_node);
    }
    else
    {
        if(new_node->data < prev_node->data)
        {
            prev_node->left = new_node;
        }
        else
        {
            prev_node->right = new_node;
        }
        new_node->parent = prev_node;
    }
}

template <class Node, class Tree>
void INode::delete_node(Node *cur_node, Tree *t)
{
    Node *prev_node = cur_node->parent;
    Node *match_node = cur_node;

    if(NULL == cur_node->left &&
            NULL == cur_node->right)
    {
        if(cur_node == cur_node->parent->left)
        {
            cur_node->parent->left = NULL;
        }
        else
        {
            cur_node->parent->right = NULL;
        }

        if(t->get_root() == cur_node)
        {
            delete(cur_node);
            t->set_root(NULL);
        }
        else
        {
            delete(cur_node);
            cur_node = NULL;
        }
    }
    else if(NULL == cur_node->left)
    {
        cur_node->right->parent = prev_node;
        if(NULL != prev_node)
        {
            if(cur_node == prev_node->left)
            {
                prev_node->left = cur_node->right;
            }
            else
            {
                prev_node->right = cur_node->right;
            }
            delete(cur_node);
        }
        else
        {
            t->set_root(cur_node->right);
            delete(cur_node);
        }
    }
    else if(NULL == cur_node->right)
    {
        cur_node->left->parent = prev_node;
        if(NULL != prev_node)
        {
            if(cur_node == prev_node->left)
            {
                prev_node->left = cur_node->left;
            }
            else
            {
                prev_node->right = cur_node->left;
            }
            delete(cur_node);
        }
        else
        {
            t->set_root(cur_node->left);
            delete(cur_node);
        }
    }
    else
    {
        prev_node = cur_node;
        cur_node = cur_node->left;
        while(NULL != cur_node)
        {
            prev_node = cur_node;
            cur_node = cur_node->right;
        }

        match_node->data = prev_node->data;
        if(prev_node == prev_node->parent->left)
        {
            prev_node->parent->left = prev_node->left;
        }
        else
        {
            prev_node->parent->right = prev_node->left;
        }
        if(NULL != prev_node->left)
        {
            prev_node->left->parent = prev_node->parent;
        }
        delete(prev_node);
        prev_node = NULL;
    }
}

template <class Node, class Tree>
void INode::left_rotate_node(Node* cur_node, Tree* t)
{
    Node * new_parent = cur_node->right;
    cur_node->right = new_parent->left;

    if(NULL != new_parent->left)
    {
        new_parent->left->parent = cur_node;
    }
    new_parent->parent = cur_node->parent;

    if(t->get_root() == cur_node)
    {
        t->set_root(new_parent);
    }
    else if(cur_node == cur_node->parent->left)
    {
        cur_node->parent->left = new_parent;
    }
    else
    {
        cur_node->parent->right = new_parent;
    }
    new_parent->left = cur_node;
    cur_node->parent = new_parent;
}

template <class Node, class Tree>
void INode::right_rotate_node(Node *cur_node, Tree *t)
{
    Node * new_parent = cur_node->left;
    cur_node->left = new_parent->right;

    if(NULL != new_parent->right)
    {
        new_parent->right->parent = cur_node;
    }
    new_parent->parent = cur_node->parent;

    if(t->get_root() == cur_node)
    {
        t->set_root(new_parent);
    }
    else if(cur_node == cur_node->parent->left)
    {
        cur_node->parent->left = new_parent;
    }
    else
    {
        cur_node->parent->right = new_parent;
    }

    new_parent->right = cur_node;
    cur_node->parent = new_parent;
}

