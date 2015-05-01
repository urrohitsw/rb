#include"bstree.h"
#include"rbnode.h"

BSNode::BSNode()
{
    this->data = 0;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

BSNode::BSNode(int data)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

void BSNode::print_node(ofstream &file)
{
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
