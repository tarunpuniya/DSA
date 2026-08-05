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
    int count = 0;
    node*temp=head;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }

    if(m<=0 || m>count){
        cout<<"Invalid node position."<<endl;
        return head;
    }

    if(count==m){
        node*newhead = head;
        head=head->next;
        delete newhead;
        return head;
    }

    int steps = count - m - 1;
    temp = head;
    while(steps-- > 0){
        temp = temp->next;
    }

    node*delnode = temp->next;
    temp->next = delnode->next;
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
