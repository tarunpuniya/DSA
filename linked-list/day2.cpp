#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node*next;

    // constructor
    node(int data){
        val=data;
        next=NULL;
    }
};
