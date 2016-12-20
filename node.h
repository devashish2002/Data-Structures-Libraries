/*
Node class for data structures.A Node is defined here as a container in which data of various
data types can be stored.
*/


#ifndef NODE_H
#define NODE_H

template<typename T>     //Node containinfg data of type 'T'
class Node{
public:
    T data;
    Node*next;

    Node(T data){        //constructor
        data=data;
        next=NULL;
    }

};


#endif // NODE_H
