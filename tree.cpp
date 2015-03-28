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
void Node::print_node(ofstream &file)
{
    if(nullptr != this->left)
    {
        file<<"     "<<this->data<<" -> "<<this->left->data<<";\n";
        file<<"     "<<this->left->data<<" -> "<<this->data<<" [style=dotted,color=red];\n";
        this->left->print_node(file);
    }
    //cout<<this->data<<endl;
    if(nullptr != this->right)
    {
        file<<"     "<<this->data<<" -> "<<this->right->data<<";\n";
        file<<"     "<<this->right->data<<" -> "<<this->data<<" [style=dotted,colr=red];\n";
        this->right->print_node(file);
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

    /* initialize random seed: */
    srand (time(NULL));
}

void Tree::print_tree()
{
    ofstream file;
    file.open("tree.gv",ios::app);
    file<<"digraph BST {"<<endl;
    root->print_node(file);
    file<<"}";
    file.close();
}

Node * Node::delete_node(int data)
{
    Node *cur_node = this;
    Node *root = this;
    Node *prev_node;
    Node *match_node;

    while(nullptr != cur_node)
    {
        prev_node = cur_node;
        if(data == cur_node->data)
        {
            match_node = cur_node;
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

                if(root == cur_node)
                {
                    delete(cur_node);
                    cur_node = nullptr;
                    return nullptr;
                }
                else
                {
                    delete(cur_node);
                    cur_node = nullptr;
                }
            }
            else if(nullptr == cur_node->left)
            {
                cur_node = cur_node->right;

                prev_node = cur_node;
                while(nullptr != cur_node)
                {
                    prev_node = cur_node;
                    cur_node = cur_node->left;
                }

                match_node->data = prev_node->data;

                if(nullptr != prev_node->right)
                {
                    /* Case where match_node is same as
                     * prev_node->parent->right */
                    prev_node->parent->right = prev_node->right;
                    prev_node->right->parent = prev_node->parent;
                }
                else if(prev_node == prev_node->parent->left)
                {
                    prev_node->parent->left = nullptr;
                }
                else
                {
                    prev_node->parent->right = nullptr;
                }
                delete(prev_node);
                prev_node = nullptr;
            }
            else
            {
                cur_node = cur_node->left;
                prev_node = cur_node;
                while(nullptr != cur_node)
                {
                    prev_node = cur_node;
                    cur_node = cur_node->right;
                }

                match_node->data = prev_node->data;

                if(nullptr != prev_node->left)
                {
                    prev_node->parent->left = prev_node->left;
                    prev_node->left->parent = prev_node->parent;
                }
                else if(prev_node == prev_node->parent->left)
                {
                    prev_node->parent->left = nullptr;
                }
                else
                {
                    prev_node->parent->right = nullptr;
                }
                delete(prev_node);
                prev_node = nullptr;
            }
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
    return root;
}

void Tree::delete_from_tree()
{
    int entry_count;

    cout<<"Enter number of entries:";
    cin>>entry_count;

    int delete_data;

    for(int index = 0;index < entry_count; index++)
    {

        delete_data = treedata.front();
        treedata.pop_front();
        cout<<"Deleting "<<delete_data<<endl;

        root->delete_node(delete_data);
        print_tree();
    }
    cout<<"Deleted "<<entry_count<<" entries from the BST."<<endl;
}

void Tree::insert_into_tree()
{
    int entry_count;
    int failure_count = 0;
    int input_data;
    Node * input_node;

    cout<<"Enter number of entries:";
    cin>>entry_count;

    for(int index = 0;index < entry_count; index++)
    {
        input_data = rand()%100 + 1;

        auto result = find(treedata.begin(), treedata.end(), input_data);

        if(result != end(treedata))
        {
            cout<<"Tree already contains "<<input_data<<endl;
            failure_count++;
        }
        else
        {
            cout<<"Adding "<<input_data<<endl;
            treedata.push_back(input_data);

            input_node = new Node(input_data);
            input_node->insert_node(this);
            print_tree();
        }

    }

    cout<<"Added "<<entry_count - failure_count
        <<" entries to the BST."<<endl;
}
