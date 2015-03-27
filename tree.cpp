#include"tree.h"

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

#if 1
void Node::print_node()
{
    if(nullptr != this->left)
    {
        this->left->print_node();
    }
    cout<<this->data<<endl;
    if(nullptr != this->right)
    {
        this->right->print_node();
    }

}
#endif

Node * Tree::get_root()
{
    return root;
}

void Tree::set_root(Node * root_node)
{
    root = root_node;
}

Tree::Tree()
{
    root = nullptr;
}

void Tree::print_tree()
{
    ofstream file;
    file.open("tree.gv",ios::trunc);
    file<<"digraph G {"<<endl;
    root->print_node();
    file<<endl<<"}";
    file.close();
}
