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

    node*removemiddle(node*head){
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return nullptr;

        if(head->next->next==nullptr){
            delete head->next;
            head->next=nullptr;
            return head;
        }

        int count = 0;
        node*temp=head;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        int mid = count/2;
        node*prev = head;
        for(int i=0; i<mid-1; i++){
            prev=prev->next;
        }

        node*del=prev->next;
        prev->next=del->next;
        delete del;
        return head;
    }
};

int main(){
    int n; cout<<"Enter the number of nodes:  "; cin>>n;
    node*head=nullptr;
    node*tail=nullptr;

    for(int i=0; i<n; i++){
        int value; cout<<"Enter the value of node:  "; cin>>value;
        node*newnode=new node(value);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    }

    // Print original linked list
    cout<<"Original linked list:  ";
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->next;
    }

    // Linked list after removing the middle node
    cout<<"\nLinked list after removing the middle node:  ";
    if(head!=nullptr){
        head=head->removemiddle(head);
    }
    temp=head;
    while(temp!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->next;
    }

    return 0;

}