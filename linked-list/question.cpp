//Removed linked list elements 

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

node*remove(node*head,int val){

    while(head!=nullptr && head->value==val){
        node*temp=head;
        head=head->next;
        delete(temp);
    }
    if(head==nullptr) return nullptr;
    node*current=head;
    while(current->next!=nullptr){
        if(current->next->value==val){
            node*temp=current->next;
            current->next=current->next->next;
            delete temp;
        }else{
            current=current->next;
        }
    }
    return head;
}

int main(){

    node*n = new node(1);
    node*m = new node(1);
    node*o = new node(2);
    node*p = new node (3);

    node*head = n;
    n->next = m;
    m->next = o;
    o->next = p;

    head = remove(head,2);
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    return 0;

    
}
