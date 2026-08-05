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
        if(head->next==nullptr){
            
            return nullptr;
        }

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
    node*n = new node(1);
    node*m = new node(3);
    node*o = new node(4);
    node*p = new node(7);
    node*q = new node(1);
    node*r = new node(2);
    node*s = new node(6);

    node*head = n;
    n->next=m;
    m->next=o;
    o->next=p;
    p->next=q;
    q->next=r;
    r->next=s;

    head=head->removemiddle(head);
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->next;
    }

    return 0;
}