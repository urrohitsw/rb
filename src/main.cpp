#include "bstree.h"
#include "rbtree.h"
#include "rbnode.h"
#include "inode.cpp"

int main()
{
    BSTree bst = BSTree();
    RBTree rbt = RBTree();

#ifndef ENABLE_RANDOM_OPERATIONS
    BSNode * input_node;
    BSNode * output_node;
    RBNode * rb_input_node;
    RBNode * rb_output_node;
    int input_data;
    INode friend_node;
#endif

    int choice;
    int tree_choice;

    cout<<"Enter 1 for Simple BST, 2 for RBT, Which tree you want ?";
    cin>>tree_choice;

    if(1 != tree_choice || 2 != tree_choice)
    {
        cout<<"Incorrect Choice"<<endl;
    }

    if(1 == tree_choice)
    {
        while(1)
        {
#ifndef ENABLE_RANDOM_OPERATIONS
            cout<<"Choices : 1. Insert 2. Delete 3. Left Rotate 4. Right Rotate 5. Print 6. Exit"<<endl;
#else
            cout<<"Choices : 1. Insert 2. Delete 5. Print 6. Exit"<<endl;
#endif
            cin>>choice;

            switch(choice)
            {
                case INSERT:
#ifndef ENABLE_RANDOM_OPERATIONS
                    cout<<"Enter the data to be inserted: ";
                    cin>>input_data;
                    input_node = new BSNode(input_data);
                    friend_node.insert_node(input_node,&bst);
#else
                    bst.insert_into_tree();
#endif
                    break;
                case DELETE:
#ifndef ENABLE_RANDOM_OPERATIONS
                    cout<<"Enter the data to be deleted: ";
                    cin>>input_data;
                    output_node = friend_node.find_node(bst.get_root(),input_data);
                    if(NULL == output_node)
                    {
                        cout<<"Data entered doesn't exist in the tree "<<endl;
                    }
                    else
                    {
                        friend_node.delete_node(output_node,&bst);
                    }
#else
                    bst.delete_from_tree();
#endif
                    break;
                case LEFT_ROTATE:
#ifndef ENABLE_RANDOM_OPERATIONS
                    cout<<"Enter the data to be rotated to the left: ";
                    cin>>input_data;
                    output_node = friend_node.find_node(bst.get_root(),input_data);
                    if(NULL == output_node)
                    {
                        cout<<"Data entered doesn't exist in the tree "<<endl;
                    }
                    else
                    {
                        friend_node.left_rotate_node(output_node,&bst);
                    }
#else
                    cout<<"Not supported in random operations mode !!"<<endl;
#endif
                    break;
                case RIGHT_ROTATE:
#ifndef ENABLE_RANDOM_OPERATIONS
                    cout<<"Enter the data to be rotated to the right: ";
                    cin>>input_data;
                    output_node = friend_node.find_node(bst.get_root(),input_data);
                    if(NULL == output_node)
                    {
                        cout<<"Data entered doesn't exist in the tree."<<endl;
                    }
                    else
                    {
                        friend_node.right_rotate_node(output_node,&bst);
                    }
#else
                    cout<<"Not supported in random operations mode !!"<<endl;
#endif
                    break;
                case PRINT:
                    bst.print_tree();
                    break;
                case EXIT:
                    exit(0);
                default:
                    cout<<"More cases coming soon"<<endl;
            }
        }
    }
    else
    {

        while(1)
        {
#ifndef ENABLE_RANDOM_OPERATIONS
            cout<<"Choices : 1. Insert 3. Left Rotate 4. Right Rotate 5. Print 6. Exit"<<endl;
#else
            cout<<"Choices : 1. Insert 5. Print 6. Exit"<<endl;
#endif
            cin>>choice;

            switch(choice)
            {
                case INSERT:
#ifndef ENABLE_RANDOM_OPERATIONS
                    cout<<"Enter the data to be inserted: ";
                    cin>>input_data;
                    rb_input_node = new RBNode(input_data);
                    friend_node.insert_node(rb_input_node,&rbt);
                    rb_input_node->insert_fixup(&rbt);
#else
                    rbt.insert_into_tree();
#endif
                    break;
                case LEFT_ROTATE:
#ifndef ENABLE_RANDOM_OPERATIONS
                    cout<<"Enter the data to be rotated to the left: ";
                    cin>>input_data;
                    rb_output_node = friend_node.find_node(rbt.get_root(),input_data);
                    if(NULL == rb_output_node)
                    {
                        cout<<"Data entered doesn't exist in the tree "<<endl;
                    }
                    else
                    {
                        friend_node.left_rotate_node(rb_output_node,&rbt);
                    }
#else
                    cout<<"Not supported in random operations mode !!"<<endl;
#endif
                    break;
                case RIGHT_ROTATE:
#ifndef ENABLE_RANDOM_OPERATIONS
                    cout<<"Enter the data to be rotated to the right: ";
                    cin>>input_data;
                    rb_output_node = friend_node.find_node(rbt.get_root(),input_data);
                    if(NULL == rb_output_node)
                    {
                        cout<<"Data entered doesn't exist in the tree."<<endl;
                    }
                    else
                    {
                        friend_node.right_rotate_node(rb_output_node,&rbt);
                    }
#else
                    cout<<"Not supported in random operations mode !!"<<endl;
#endif
                    break;
                case PRINT:
                    rbt.print_tree();
                    break;
                case EXIT:
                    exit(0);
                default:
                    cout<<"More cases coming soon"<<endl;
            }
        }
    }

    return 0;
}
