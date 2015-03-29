#include "tree.h"

int main()
{
    Tree bst = Tree();
    int choice;
#ifndef ENABLE_RANDOM_OPERATIONS
    Node * input_node;
    Node * output_node;
    int input_data;
#endif

    cout<<"Choices : 1. Insert 2. Delete 3. Print 4. Exit"<<endl;
    while(1)
    {
        cin>>choice;

        switch(choice)
        {
            case 1:
#ifndef ENABLE_RANDOM_OPERATIONS
                cin>>input_data;
                input_node = new Node(input_data);
                input_node->insert_node(&bst);
#else
                bst.insert_into_tree();
#endif
                break;
            case 2:
#ifndef ENABLE_RANDOM_OPERATIONS
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
            case 4:
                exit(0);
            default:
                cout<<"More cases coming soon"<<endl;
        }
    }

    return 0;
}
