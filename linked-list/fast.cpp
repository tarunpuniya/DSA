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

node*removen(node*head,int m){
    node*fast = head;
    for(int i=0; i<m; i++){
        fast=fast->next;
    }
    if(fast==nullptr) return head->next;
    node*slow=head;
    while(fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next;
    }
    node*delnode = slow->next;
    slow->next=slow->next->next;
    delete delnode;
    return head;
}

int main(){
    int n; cout<<"Enter the nodes: "; cin>>n;
    node*head=nullptr;
    node*tail=nullptr;

    for(int i=0; i<n; i++){
        int ele; cout<<"Enter the value: "; cin>>ele;
        node*newnode=new node(ele);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }

    if(head!=nullptr){
        int m;
        cout<<"Enter which node to delete from the end: ";
        cin>>m;
        head=removen(head,m);
    }

    node*current=head;
    while(current!=nullptr){
        cout<<current->value<<" ";
        current=current->next;
    }
    return 0;
}
