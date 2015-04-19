#include"tree.h"
#include"node.h"

Node::Node()
{
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

Node::Node(int data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

void Node::insert_node(Tree *t)
{
    Node *cur_node = t->get_root();
    Node *prev_node;
    while(nullptr != cur_node)
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


    if(nullptr == t->get_root())
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

void Node::delete_node(Tree *t)
{
    Node *prev_node = this->parent;
    Node *match_node = this;
    Node *cur_node = this;

    if(nullptr == cur_node->left &&
            nullptr == cur_node->right)
    {
        if(cur_node == cur_node->parent->left)
        {
            cur_node->parent->left = nullptr;
        }
        else
        {
            cur_node->parent->right = nullptr;
        }

        if(t->get_root() == cur_node)
        {
            delete(cur_node);
            t->set_root(nullptr);
        }
        else
        {
            delete(cur_node);
            cur_node = nullptr;
        }
    }
    else if(nullptr == cur_node->left)
    {
        cur_node->right->parent = prev_node;
        if(nullptr != prev_node)
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
    else if(nullptr == cur_node->right)
    {
        cur_node->left->parent = prev_node;
        if(nullptr != prev_node)
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
        while(nullptr != cur_node)
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
        if(nullptr != prev_node->left)
        {
            prev_node->left->parent = prev_node->parent;
        }
        delete(prev_node);
        prev_node = nullptr;
    }
}

Node * Node::find_node(int data)
{
    Node *cur_node = this;

    while(nullptr != cur_node)
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

void Node::left_rotate_node(Tree *t)
{
    Node *cur_node = this;

    Node * new_parent = cur_node->right;
    cur_node->right = new_parent->left;

    if(nullptr != new_parent->left)
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

void Node::right_rotate_node(Tree *t)
{
    Node *cur_node = this;

    Node * new_parent = cur_node->left;
    cur_node->parent = new_parent;

    cur_node->left = new_parent->right;

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

void Node::print_node(ofstream &file)
{
    if(nullptr != this->left)
    {
        file<<"     "<<this->data<<" -> "<<this->left->data<<";\n";
        file<<"     "<<this->left->data<<" -> "<<this->data<<" [style=dotted,color=red];\n";
        this->left->print_node(file);
    }
    if(nullptr != this->right)
    {
        file<<"     "<<this->data<<" -> "<<this->right->data<<";\n";
        file<<"     "<<this->right->data<<" -> "<<this->data<<" [style=dotted,colr=red];\n";
        this->right->print_node(file);
    }

}
