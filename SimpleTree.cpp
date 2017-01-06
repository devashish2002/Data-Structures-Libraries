#include "SimpleTreeNode.h"
#include<iostream>
#include<queue>
using namespace std;

TreeNode* takeInput(){              //Function for taking input for the tree
    int data;
    int count;
    cout<<"enter the node data: ";
    cin>>data;
    cout<<"enter the children count for: "<<data<<" ";
    cin>>count;

    TreeNode*root=new TreeNode(data);
    root->children_count=count;
    root->children=new TreeNode*[count];

    for(int i=0;i<count;i++){
        root->children[i]=takeInput();
    }

    return root;
}

void levelOrderPrint(TreeNode*root){          //Level order printing of the tree starting from root node
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode*front=q.front();
        if(front==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<front->data<<" ";

            for(int i=0;i<front->children_count;i++){
                q.push(front->children[i]);
            }
        }
    }
}


void print(TreeNode*root){                     //printing of the tree depicting the parents and children
    cout<<"Parent: "<<root->data<<endl;
    cout<<"Children: ";

    for(int i=0;i<root->children_count;i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;

    for(int i=0;i<root->children_count;i++){
        print(root->children[i]);
    }

}

void printAtLevelK(TreeNode*root,int k){       //function for printing at a level 'k' (k=0 for root node)
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<endl;
    }

    for(int i=0;i<root->children_count;i++){
        printAtLevelK(root->children[i],k-1);
    }
}

int main(){                          //main function
    TreeNode*root=NULL;
    root=takeInput();
    levelOrderPrint(root);
return 0;
}
