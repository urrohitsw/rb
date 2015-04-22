#include "rbtree.h"
#include "rbnode.h"

RBTree::RBTree():Tree()
{

}

void RBTree::insert_into_tree()
{
    int entry_count;
    int failure_count = 0;
    int input_data;
    RBNode * input_node;

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

            input_node = new RBNode(input_data,Color::RED);
            input_node->insert_node(this);
            input_node->insert_fixup(this);
            print_tree();
        }

    }

    cout<<"Added "<<entry_count - failure_count
        <<" entries to the BST."<<endl;
}
