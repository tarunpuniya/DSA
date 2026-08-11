#include<iostream>
 class node{
    public:
        int value;
        node*next;

        node(int data){
            value=data;
            next=nullptr;
        }
 };

node*insertathead(node*head,int value){
    node*newnode=new node(value);
    newnode->next=head;
    return newnode;
}

node* insertAtTail(node* head, int val) {
    if (head == nullptr) {
        node* newNode = new node(val);
        return newNode;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    node* newNode = new node(val);
    temp->next = newNode;
    return head;
}

node*insertatk(node*head,int el,int k){
    if(head==nullptr){
        if(k==1){
            return new node(el);
        }
        else{
            return head;
        }
    }
      if(k==1){
            node*newnode=new node(el);
            newnode->next=head;
            return newnode;
        }

    int count = 0;
    node*temp=head;
    while(temp!=nullptr){
        count++;
        if(count==k-1){
            node*x=new node(el);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

node*insertbeforevalue(node*head,int els , int vals){
    if(head==nullptr) return nullptr;
    if(head->value==vals){
        node*newnode=new node(els);
        newnode->next=head;
        return newnode;
    }
    node*temp=head;
    while(temp->next!=nullptr){
        if(temp->next->value==vals){
            node*x=new node(els);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    int n; std::cout<<"Enter the number of nodes:  "; std::cin>>n;
    node*head=nullptr;
    node*tail=nullptr;

    for(int i=0; i<n; i++){
        int value; std::cout<<"Enter the value of node:  "; std::cin>>value;
        node*newnode=new node(value);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    }

    int value; std::cout<<"Enter the value: "; std::cin>>value;
    head=insertathead(head,value);
    node*temp=head;
    while(temp!=nullptr){
        std::cout<<temp->value<<" ";
        temp=temp->next;
    }

    std::cout<<std::endl;

    int val; std::cout<<"Enter the val: "; std::cin>>val;
    head=insertAtTail(head,val);
    temp=head;
    while(temp!=nullptr){
        std::cout<<temp->value<<" ";
        temp=temp->next;
    }

    std::cout<<std::endl;
    int el; std::cout<<"Enter the el: "; std::cin>>el;
    int k; std::cout<<"Enter k: "; std::cin>>k;
    head=insertatk(head,el,k);
    temp=head;
    while(temp!=nullptr){
        std::cout<<temp->value<<" ";
        temp=temp->next;
    }

    std::cout<<std::endl;
    int els; std::cout<<"Enter the els: "; std::cin>>els;
    int vals; std::cout<<"Enter vals: "; std::cin>>vals;
    head=insertatk(head,els,vals);
    temp=head;
    while(temp!=nullptr){
        std::cout<<temp->value<<" ";
        temp=temp->next;
    }
    return 0;
}