/*A hash table (hash map) is a data structure used to implement
an associative array, a structure that can map keys to values*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include "hashNode.h"
#include<cstring>
#include<iostream>
using namespace std;

template<typename T>

class hashTable{
private:
    int current_size;
    int table_size;
    hashNode<T>* *buckets;

    void rehash(){                          //rehash function used to increase the table size when load factor exceeds 0.7
        int old_table_size = table_size;
				hashNode<T>**oldBuckets = buckets;

				current_size=0;
				table_size = 2*table_size;
				buckets = new hashNode<T>*[table_size];

				for(int i=0;i<table_size;i++){
					buckets[i] = NULL;
				}

			    for(int i=0;i<old_table_size;i++){
					if(oldBuckets[i]!=NULL){
						hashNode<T>*temp = oldBuckets[i];
						while(temp!=NULL){
							insert(temp->key,temp->value);
							temp = temp->next;
						}
						delete oldBuckets[i];
					}
				}
				delete [] oldBuckets;
    }

    int hashFunction(char*key){          // hash function to compute an index into an array of buckets or slots
        int ans=0;
        int L=strlen(key);
        int power=1;
        for(int i=0;i<L;i++){
            ans=ans+key[L-i-1]*power;
            ans=ans%table_size;
            power=power*37;
            power%=table_size;
        }
        return ans;
    }

public:
    hashTable(){                         //constructor
        current_size=0;
        table_size=3;
        buckets=new hashNode<T>*[table_size];
        for(int i=0;i<table_size;i++){
            buckets[i]=NULL;
        }
    }

    void insert(char*key,T value){                //function for inserting the nodes into the table at specified key
        int index=hashFunction(key);
        hashNode<T>*myNode=new hashNode<T>(key,value);
        myNode->next=buckets[index];
        buckets[index]=myNode;
        current_size++;

        float load_factor=current_size/float(table_size);
        if(load_factor>0.7){
            cout<<"load factor is "<<load_factor;
            rehash();
        }
    }

    T find(char*key){                         //finding a particular node in the table
        int index=hashFunction(key);
        hashNode<T>*temp=buckets[index];
        while(temp!=NULL){
              if(strcmp(temp->key,key)==0){
                  return temp->key;
              }
              temp=temp->next;
        }
        T defaultObject;
        return defaultObject;
    }

    void print(){                         //print function for printing the hash table
        for(int i=0;i<table_size;i++){
            cout<<"Bucket "<<i<<"-->";
            if(buckets[i]!=NULL){
                hashNode<T>*temp=buckets[i];
                while(temp!=NULL){
                    cout<<temp->key<<"-->";
                    temp=temp->next;
                }
            }
            cout<<endl;
        }
    }
};

#endif // HASH_TABLE_H
