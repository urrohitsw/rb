#include "tree.h"

int main()
{
    Tree bst = Tree();
    int choice;
#ifndef ENABLE_RANDOM_OPERATIONS
    Node * input_node;
    int input_data;
#endif

    while(1)
    {
#ifndef ENABLE_RANDOM_OPERATIONS
    cout<<"Choices : 1. Insert 2. Delete 4. Print 5. Exit"<<endl;
#else
    cout<<"Choices : 1. Insert 2. Delete 3. Left Rotate 4. Print 5. Exit"<<endl;
#endif
        cin>>choice;

        switch(choice)
        {
            case 1:
#ifndef ENABLE_RANDOM_OPERATIONS
                cout<<"Enter the data to be inserted: "
                cin>>input_data;
                input_node = new Node(input_data);
                input_node->insert_node(&bst);
#else
                bst.insert_into_tree();
#endif
                break;
            case 2:
#ifndef ENABLE_RANDOM_OPERATIONS
                cout<<"Enter the data to be deleted: "
                cin>>input_data;
                bst.get_root()->find_node(input_data)->delete_node(&bst);
#else
                bst.delete_from_tree();
#endif
                break;
            case 3:
#ifndef ENABLE_RANDOM_OPERATIONS
                cin>>input_data;
                bst.get_root()->find_node(input_data)->left_rotate_node(&bst);
#else
                cout<<"Not supported in random operations mode !!";
#endif
                break;
            case 4:
                bst.print_tree();
                break;
            case 5:
                exit(0);
            default:
                cout<<"More cases coming soon"<<endl;
        }
    }

    return 0;
}
