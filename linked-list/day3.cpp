#include<iostream>
 using namespace std;

 class node{
    public:
    int value;
    node*next;

    node(int data){
        value=data;
        next=nullptr;
    }
 };

 int length(node*head){
    int count=0;
    node*temp=head;
    while(temp!=nullptr){
        temp=temp->next;
        count++;
    }
    return count;
 }

 int search(node*head , int val){
    node*temp=head;
    while(temp!=nullptr){
        if(temp->value==val) return val;
        temp=temp->next;
    }
    return 1;
 }

 int main(){
    node*n = new node(2);
    node*m = new node(3);
    node*o = new node(4);
    node*p = new node(5);

    node*head = n;

    n->next = m;
    m->next = o;
    o->next = p;
    
    node*temp = head;
    while(temp!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->next;
    }

    cout<<length(head)<<" ";
    cout<<search(head,6)<<" ";
    
 }