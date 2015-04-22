#include "rbnode.h"
#include "rbtree.h"

RBNode::RBNode():Node()
{
    this->color = Color::RED;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

RBNode::RBNode(int data):Node(data)
{
    this->color = Color::RED;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

RBNode::RBNode(int data,Color color):Node(data)
{
    this->color = color;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

void RBNode::insert_fixup(RBTree *rbt)
{
    RBNode * cur_node = this;
    RBNode * uncle = this;

    while(Color::RED == cur_node->parent->color)
    {
        if(cur_node->parent == cur_node->parent->parent->left)
        {
            uncle = cur_node->parent->parent->right;

            if(Color::RED == uncle->color)
            {
                uncle->color = Color::BLACK;
                cur_node->parent->color = Color::BLACK;
                cur_node->parent->parent->color = Color::RED;

                cur_node = cur_node->parent->parent;
            }
            else
            {
                if(cur_node == cur_node->parent->right)
                {
                    cur_node = cur_node->parent;
                    cur_node->left_rotate_node(rbt);
                }

                cur_node->parent->color = Color::BLACK;
                cur_node->parent->parent->color = Color::RED;

                cur_node->parent->parent->right_rotate_node(rbt);
            }
        }
        else
        {
            uncle = cur_node->parent->parent->left;

            if(Color::RED == uncle->color)
            {
                uncle->color = Color::BLACK;
                cur_node->parent->color = Color::BLACK;
                cur_node->parent->parent->color = Color::RED;

                cur_node = cur_node->parent->parent;
            }
            else
            {
                if(cur_node == cur_node->parent->left)
                {
                    cur_node = cur_node->parent;
                    cur_node->right_rotate_node(rbt);
                }

                cur_node->parent->color = Color::BLACK;
                cur_node->parent->parent->color = Color::RED;

                cur_node->parent->parent->left_rotate_node(rbt);
            }
        }
    }
}
