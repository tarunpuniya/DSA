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
        count++;
        temp=temp->next;
    }
    return count;
 }

 int search(node*head , int val){
    node*temp=head;
    while(temp!=nullptr){
        if(temp->value==val) return val;
        temp=temp->next;
    }
    return -1;

 }

 node* removeathead(node*&head){
    if(head==nullptr) return head;
    node*temp=head;
    head=head->next;
    delete temp;
    return head;
 }

 node*removeattaile(node*&head){
    if(head==nullptr ) return nullptr;
    if(head->next==nullptr){
        delete head;
        head=nullptr;
        return head;
    }
    node*temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
 }

 node*removek(node*&head,int k){
    if(head==nullptr) return nullptr;
    if(k==1){
        node*temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int count=0;
    node*temp=head;
    node*prev=nullptr;
    while(temp!=nullptr){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;


 }

 int main(){
    node*n = new node(1);
    node*m = new node(2);
    node*o = new node(3);
    node*p = new node(4);
    node*q = new node(5);
    node*r = new node(6);

    node*head = n;

    n->next=m;
    m->next=o;
    o->next=p;
    p->next=q;
    q->next=r;
    
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
    cout << endl; 

    head = removeathead(head);
    temp=head;
    while(temp!=nullptr){
        
        cout<<temp->value<<" ";
        temp=temp->next;
    }

    cout<<endl;

    head=removeattaile(head);
    temp=head;
    while(temp!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->next;
    }

    cout<<endl;

    head=removek(head,1);
    temp=head;
    while(temp!=nullptr){
        cout<<temp->value<<" ";
        temp=temp->next;
    }

    cout << "\nLength: " << length(head);
    cout << "\nSearch: " << search(head, 7);
    
 }