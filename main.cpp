#include "tree.h"

int main()
{
    Tree bst = Tree();
    int choice;
    Node * input_node;
    int input_data;

    cout<<"Choices : 1. Insert 2. Print"<<endl;
    while(1)
    {
        cin>>choice;

        switch(choice)
        {
            case 1:
                cin>>input_data;
                input_node = new Node(input_data);
                input_node->insert_node(&bst);
                break;
            case 2:
                bst.print_tree();
                break;
            default:
                cout<<"More cases coming soon"<<endl;
        }
    }

    return 0;
}
