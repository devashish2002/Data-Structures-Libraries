/*Implementation of a binary tree*/
/*A data structure in which a record is linked to two successor records, usually referred to as the left
 record and the right record */

#include "BinaryTreeNode.h"
#include<iostream>
#include<queue>
using namespace std;

template<typename T>
BinaryTreeNode<T>* takeInput(){              //function for taking input for the binary tree
    int data;
    cout<<"enter data for root node: ";
    cin>>data;
    queue<BinaryTreeNode<T> *> q;
    BinaryTreeNode<T>* root=new BinaryTreeNode<T>(data);
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<T>*front=q.front();
        q.pop();
        int rightData,leftData;
        cout<<"enter the children of "<<front->data<<": ";
        cin>>leftData>>rightData;

        if(leftData!=-1){
            front->left=new BinaryTreeNode<T>(leftData);
            q.push(front->left);
        }
        if(rightData!=-1){
            front->right=new BinaryTreeNode<T>(rightData);
            q.push(front->right);
        }
    }

return root;
}

void print(BinaryTreeNode<int>*root){           //print function for printing the tree
    if(root==NULL){
        return;
    }
    cout<<"parent: "<<root->data;
    cout<<"children: ";
    if(root->left!=NULL){
        cout<<root->left->data;
    }
    cout<<",";
    if(root->right!=NULL){
        cout<<root->right->data;
    }
    cout<<endl;

    print(root->left);
    print(root->right);
}

void levelOrderPrint(BinaryTreeNode<int>*root){       //level order printing of the tree starting from root node
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        BinaryTreeNode<int>*front=q.front();
        if(front==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data;
            q.pop();
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }
}

void preOrderPrint(BinaryTreeNode<int> *root){         //pre order printing
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

void postOrderPrint(BinaryTreeNode<int> *root){        //post order printing
   if(root==NULL){
        return;
   }
   postOrderPrint(root->left);
   postOrderPrint(root->right);
   cout<<root->data<<" ";
}

void inOrderPrint(BinaryTreeNode<int> *root){         //in-order printing
    if(root==NULL){
        return;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}

int main(){                                          //main function
    BinaryTreeNode<int> *root=NULL;
    root=takeInput<int>();
    preOrderPrint(root);
return 0;
}
