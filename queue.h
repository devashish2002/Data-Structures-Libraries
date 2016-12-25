/*A queue works on the principle of FIFO(first in-first out)
The first data to be passed into the queue is the first one to be out*/

#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
#include<iostream>
using namespace std;

template<typename T>

class queue{
    Node<T>*head;
    Node<T>*tail;

public:
    queue(){                 //constructor
        head=NULL;
        tail=NULL;
    }

    void push_back(T data){          //function for pushing the data node into the queue
        Node<T>*n=new Node<T>(data);
        if(head==NULL){
            head=tail=n;
        }
        else{
            tail->next=n;
            tail=n;
        }
    }

    void pop_back(){               //function for deleting the data node out of the queue
        Node<T>*temp=head->next;
        delete head;
        head=temp;
    }

    T top(){                   //function for getting the top data node from the queue
        if(head!=NULL){
            return head->data;
        }
        else{
            return NULL;
        }
    }

    bool empty(){            //function for checking if the queue is empty or not
        if(head==NULL){
            return true;
        }
        else{return false;}
    }
};

#endif // QUEUE_H
