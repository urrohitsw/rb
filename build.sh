#!/bin/bash

echo "Enter 'y' for random number insertion/deletion:";
read choice;
if [ $choice == y ]
then
    export ENABLE_RANDOM_OPERATIONS=true;
else
    export ENABLE_RANDOM_OPERATIONS=false;
fi

export ENABLE_GRAPH_OPERATIONS=true;

dpkg -l | grep graphviz 2>/dev/null 1>/dev/null;
if [ $? == 0 ]
then
    echo "Grapviz is present on your system."
else
    echo "Please install graphviz for this to work."
fi
#    echo "Please enter 'y' for graphical representation of Tree:"
#    read choice;
#    if [ $choice == y ]
#    then
#        export ENABLE_GRAPH_OPERATIONS=true;
#    else
#        export ENABLE_GRAPH_OPERATIONS=false;
#    fi
#else
#    echo "Grapviz is not installed on your system. Graphical representation not supported."
#    ENABLE_GRAPH_OPERATIONS=FALSE;
#fi
