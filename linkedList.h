/*A linked list is an ordered set of data elements,
  each containing a link to its successor  */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include<iostream>
using namespace std;

template<typename T>

class linkedList{
public:
    int data;
    Node<T>*head;
    Node<T>*tail;
    int size;

public:
    linkedList(){                //constructor
        head=tail=NULL;
        size=0;
    }
    void insertAtEnd(T data){          //function for inserting data at end of list
        Node<T>*n=new Node<T>(data);
        if(head==NULL){
            head=tail=n;
        }
        else{
            tail->next=n;
            tail=n;
        }
    }
    void insertAtFront(T data){        //function for inserting data at front of list
        Node<T>*n=new Node<T>(data);
        if(head==NULL){
            head=tail=n;
        }
        else{
            n->next=head;
            head=n;
        }
    }
    void insert(T data,int position){   //function for inserting data at a particular position
        if(position==0){
            insertAtFront(data);
        }
        else{
            Node<T>*temp=head;
            int count=1;
            while(count<position){
                temp=temp->next;
                count++;
            }
            Node<T>*nextNode=temp->next;
            Node<T>*newNode=new Node<T>(data);
            temp->next=newNode;
            newNode->next=nextNode;
        }

    }
    void print(){                //function for printing the list
        Node<T>*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
        cout<<endl;
    }

};

#endif // LINKEDLIST_H
