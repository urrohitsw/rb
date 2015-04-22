#include "tree.h"
#include "rbtree.h"
#include "rbnode.h"

int main()
{
    Tree bst = Tree();
    RBTree rbt = RBTree();
    int choice;
#ifndef ENABLE_RANDOM_OPERATIONS
#if 0
    Node * input_node;
    Node * output_node;
#else
    RBNode * rb_input_node;
    RBNode * rb_output_node;
#endif
    int input_data;
#endif

    while(1)
    {
#ifndef ENABLE_RANDOM_OPERATIONS
    cout<<"Choices : 1. Insert 2. Delete 5. Print 6. Exit"<<endl;
#else
    cout<<"Choices : 1. Insert 2. Delete 3. Left Rotate 4. Right Rotate 5. Print 6. Exit"<<endl;
#endif
        cin>>choice;

        switch(static_cast<Operations>(choice))
        {
            case Operations::INSERT:
#ifndef ENABLE_RANDOM_OPERATIONS
                cout<<"Enter the data to be inserted: ";
                cin>>input_data;
#if 0
                input_node = new Node(input_data);
                input_node->insert_node(&bst);
#else
                rb_input_node = new RBNode(input_data);
                rb_input_node->insert_node(&rbt);
                rb_input_node->insert_fixup(&rbt);
#endif
#else
#if 0
                bst.insert_into_tree();
#else
                rbt.insert_into_tree();
#endif
#endif
                break;
            case Operations::DELETE:
#if 0
#ifndef ENABLE_RANDOM_OPERATIONS
                cout<<"Enter the data to be deleted: ";
                cin>>input_data;
                output_node = bst.get_root()->find_node(input_data);
                if(nullptr == output_node)
                {
                    cout<<"Data entered doesn't exist in the tree "<<endl;
                }
                else
                {
                    output_node->delete_node(&bst);
                }
#else
                bst.delete_from_tree();
#endif
#endif
                break;
            case Operations::LEFT_ROTATE:
#if 0
#ifndef ENABLE_RANDOM_OPERATIONS
                cout<<"Enter the data to be rotated to the left: ";
                cin>>input_data;
                output_node = bst.get_root()->find_node(input_data);
                if(nullptr == output_node)
                {
                    cout<<"Data entered doesn't exist in the tree "<<endl;
                }
                else
                {
                    output_node->left_rotate_node(&bst);
                }
#else
                cout<<"Not supported in random operations mode !!"<<endl;
#endif
#endif
                break;
            case Operations::RIGHT_ROTATE:
#if 0
#ifndef ENABLE_RANDOM_OPERATIONS
                cout<<"Enter the data to be rotated to the right: ";
                cin>>input_data;
                output_node = bst.get_root()->find_node(input_data);
                if(nullptr == output_node)
                {
                    cout<<"Data entered doesn't exist in the tree."<<endl;
                }
                else
                {
                    output_node->right_rotate_node(&bst);
                }
#else
                cout<<"Not supported in random operations mode !!"<<endl;
#endif
#endif
                break;
            case Operations::PRINT:
                //bst.print_tree();
                break;
            case Operations::EXIT:
                exit(0);
            default:
                cout<<"More cases coming soon"<<endl;
        }
    }

    return 0;
}
