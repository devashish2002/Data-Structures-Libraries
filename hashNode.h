/*Node class for hash table*/

#ifndef HASH_NODE_H
#define HASH_NODE_H
#include<cstring>

template<typename T>

class hashNode{
public:
    T value;
    hashNode<T>*next;
    char *key;

    hashNode(char*name,T val){
        key=new char[strlen(name)+1];
        strcpy(key,name);
        value=val;
        next=NULL;
    }
};

#endif // HASH_NODE_H
