#include"bstree.h"
#include"bsnode.h"

BSNode * BSTree::get_root()
{
    cout<<"bst get";
    return root;
}

void BSTree::set_root(BSNode * root_node)
{
    cout<<"bst set";
    root = root_node;
}

BSTree::BSTree()
{
    root = NULL;

    /* initialize random seed */
    srand (time(NULL));
}

void BSTree::print_tree()
{
#ifdef ENABLE_GRAPH_OPERATIONS
    ofstream file;
    file.open("tree.gv",ios::app);
    file<<"digraph BST {"<<endl;
#endif
    root->print_node(file);
#ifdef ENABLE_GRAPH_OPERATIONS
    file<<"}";
    file.close();
#endif
}

void BSTree::delete_from_tree()
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

        root->find_node(this, delete_data)->delete_node(this);
        print_tree();
    }
    cout<<"Deleted "<<entry_count<<" entries from the BST."<<endl;
}

void BSTree::insert_into_tree()
{
    int entry_count;
    int failure_count = 0;
    int input_data;
    BSNode * input_node;
    list<int>::iterator result;

    cout<<"Enter number of entries:";
    cin>>entry_count;

    for(int index = 0;index < entry_count; index++)
    {
        input_data = rand()%100 + 1;

         result = find(treedata.begin(), treedata.end(), input_data);

        if(result != treedata.end())
        {
            cout<<"BSTree already contains "<<input_data<<endl;
            failure_count++;
        }
        else
        {
            cout<<"Adding "<<input_data<<endl;
            treedata.push_back(input_data);

            input_node = new BSNode(input_data);
            input_node->insert_node(input_node, this);
            print_tree();
        }

    }

    cout<<"Added "<<entry_count - failure_count
        <<" entries to the BST."<<endl;
}
