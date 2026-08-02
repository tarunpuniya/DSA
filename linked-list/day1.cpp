#include<iostream>
using namespace std;

class node{
    public:
    int value;
    node*next;

    node(int data){
        value=data;
        next=NULL;
    }
};

void insertAthead(node*&head , int value){
    node*new_node=new node(value);
    new_node->next=head;
    head=new_node;
}

void insertatposition(node*&head,int value,int position){
    if(position==0){
        insertAthead(head,  value);
        return;
    }

    node*new_node = new node(value);
    node*temp=head;
    int current_position=0;
    while(current_position!=position-1){
        temp=temp->next;
        current_position++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}

void insertattail(node*&head,int value){
    node*new_node=new node(value);
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;

}

void updateatposition(node*&head,int k , int value){
    node*temp=head;
    int current_pos=0;
    while(current_pos!=k){
        temp=temp->next;
        current_pos++;
    }
    temp->value=value;
}

void deleteathead(node*&head){
    node*temp=head;
    head=head->next;
    free(temp);

}

void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}


int main(){
    node*head=NULL;
    insertAthead(head,6);
    display(head);
    insertAthead(head,5);
    display(head);
    insertattail(head, 8);
    display(head);
    insertatposition(head,  7,  2);
    display(head);
    updateatposition(head, 2, 9);
    display(head);

    deleteathead(head);
    display(head);
    return 0;
}