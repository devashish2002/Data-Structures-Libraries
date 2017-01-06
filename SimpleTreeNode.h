/*Node class for a simple tree*/

#ifndef TREENODE_H
#define TREENODE_H
#include<cstddef>

class TreeNode{
public:
    int data;
    int children_count;
    TreeNode**children;
    TreeNode(int d){
        data=d;
        children_count=0;
        children=NULL;
    }
};

#endif // TREENODE_H

