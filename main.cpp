#include "tree.h"

int main()
{
    Tree bst = Tree();
    int choice;
    Node * input_node;
    Node * output_node;
    int input_data;

    cout<<"Choices : 1. Insert 2. Delete 3. Print"<<endl;
    while(1)
    {
        cin>>choice;

        switch(choice)
        {
            case 1:
#if 0
                cin>>input_data;
                input_node = new Node(input_data);
                input_node->insert_node(&bst);
#else
                bst.insert_into_tree();
#endif
                break;
            case 2:
#if 0
                cin>>input_data;
                output_node = bst.get_root()->delete_node(input_data);
                bst.set_root(output_node);
#else
                bst.delete_from_tree();
#endif
                break;
            case 3:
                bst.print_tree();
                break;
            default:
                cout<<"More cases coming soon"<<endl;
        }
    }

    return 0;
}
