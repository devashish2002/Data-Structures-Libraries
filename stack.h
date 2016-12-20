//A 'stack' works on the principle of LIFO(Last in first out).
//The last pushed data will be retrieved first from the stack.

#ifndef STACK_H
#define STACK_H
#include "node.h"         //included 'node' header file
#include<iostream>
using namespace std;

template<typename T>      //data type 'T'

class stack{
    Node<T>*head;
public:
    stack(){              //constructor
        head=NULL;
    }
void push_back(T data){              //'push_back' function for pushing data into the stack.
    Node<T>*n=new Node<T>(data);
    n->next=head;
    head=n;
}

void pop_back(){                    //'pop_back' function for deleting the top node from the stack.
    Node<T>*temp=head->next;
    delete head;
    head=temp;
}

T top(){                           //'top' function for retrieving the top node from the stack.
    if(head!=NULL){
        return head->data;
    }
}

bool empty(){                      //checking if the stack is empty or not.
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}
};

#endif
