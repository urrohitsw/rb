#include "rbnode.h"
#include "rbtree.h"

RBNode::RBNode():Node()
{
    this->color = RED;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

RBNode::RBNode(int data):Node(data)
{
    this->color = RED;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

RBNode::RBNode(int data,Color color):Node(data)
{
    this->color = color;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

#if 0
void RBNode::insert_node(RBTree *t)
{
    RBNode *cur_node = t->get_root();
    RBNode *prev_node;
    while(NULL != cur_node)
    {
        prev_node = cur_node;
        if(this->data < cur_node->data)
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
        cur_node = this;
        t->set_root(cur_node);
    }
    else
    {
        if(this->data < prev_node->data)
        {
            prev_node->left = this;
        }
        else
        {
            prev_node->right = this;
        }
        this->parent = prev_node;
    }
}
#endif

void RBNode::insert_fixup(RBTree *rbt)
{
    RBNode * cur_node = this;
    RBNode * uncle = this;

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
                    cur_node->left_rotate_node(rbt);
                }

                cur_node->parent->color = BLACK;
                cur_node->parent->parent->color = RED;

                cur_node->parent->parent->right_rotate_node(rbt);
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
                    cur_node->right_rotate_node(rbt);
                }

                cur_node->parent->color = BLACK;
                cur_node->parent->parent->color = RED;

                cur_node->parent->parent->left_rotate_node(rbt);
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

#if 0
void RBNode::left_rotate_node(RBTree *t)
{
    RBNode *cur_node = this;

    RBNode * new_parent = cur_node->right;
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

void RBNode::right_rotate_node(RBTree *t)
{
    RBNode *cur_node = this;

    RBNode * new_parent = cur_node->left;
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
#endif
