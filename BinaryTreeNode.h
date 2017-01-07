/*Node class for a binary tree*/

#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H
#include<cstddef>

template<typename T>

class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode*left;
    BinaryTreeNode*right;
    BinaryTreeNode(T d){
        data=d;
        left=right=NULL;
    }
};

#endif // BINARY_TREE_NODE_H
