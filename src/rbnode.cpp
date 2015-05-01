#include "rbnode.h"
#include "rbtree.h"
#include "inode.cpp"

RBNode::RBNode()
{
    this->color = RED;
    this->data = 0;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

RBNode::RBNode(int data)
{
    this->color = RED;
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

RBNode::RBNode(int data,Color color)
{
    this->color = color;
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

void RBNode::insert_fixup(RBTree *rbt)
{
    RBNode * cur_node = this;
    RBNode * uncle = this;
    INode friend_node;

    while(NULL != cur_node->parent && RED == cur_node->parent->color)
    {
        if(cur_node->parent == cur_node->parent->parent->left)
        {
            uncle = cur_node->parent->parent->right;

            if(NULL != uncle && RED == uncle->color)
            {
                uncle->color = BLACK;
                cur_node->parent->color = BLACK;
                cur_node->parent->parent->color = RED;

                cur_node = cur_node->parent->parent;
            }
            else
            {
                if(cur_node == cur_node->parent->right)
                {
                    cur_node = cur_node->parent;
                    friend_node.left_rotate_node(cur_node,rbt);
                }

                cur_node->parent->color = BLACK;
                cur_node->parent->parent->color = RED;

                friend_node.right_rotate_node(cur_node->parent->parent, rbt);
            }
        }
        else
        {
            uncle = cur_node->parent->parent->left;

            if(NULL != uncle && RED == uncle->color)
            {
                uncle->color = BLACK;
                cur_node->parent->color = BLACK;
                cur_node->parent->parent->color = RED;

                cur_node = cur_node->parent->parent;
            }
            else
            {
                if(cur_node == cur_node->parent->left)
                {
                    cur_node = cur_node->parent;
                    friend_node.right_rotate_node(cur_node, rbt);
                }

                cur_node->parent->color = BLACK;
                cur_node->parent->parent->color = RED;

                friend_node.left_rotate_node(cur_node->parent->parent, rbt);
            }
        }
    }
    rbt->root->color = BLACK;
}

void RBNode::print_node(ofstream &file)
{
    if(RED == this->color)
    {
        file<<"     "<<this->data<<" [color=red];\n";
    }
    else
    {
        file<<"     "<<this->data<<" [color=black];\n";
    }
    if(NULL != this->left)
    {
        file<<"     "<<this->data<<" -> "<<this->left->data<<";\n";
        file<<"     "<<this->left->data<<" -> "<<this->data<<" [style=dotted,color=red];\n";
        this->left->print_node(file);
    }
    if(NULL != this->right)
    {
        file<<"     "<<this->data<<" -> "<<this->right->data<<";\n";
        file<<"     "<<this->right->data<<" -> "<<this->data<<" [style=dotted,colr=red];\n";
        this->right->print_node(file);
    }

}
