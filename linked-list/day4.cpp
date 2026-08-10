

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

node*removeathead(node*head){
    if(head == nullptr) return nullptr;
    node*temp=head;
    head=head->next;
    delete temp;
    return head;
}

node*removeattail(node*head){
    if(head==nullptr) return nullptr;
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

node*removeatk(node*head,int k){
    if(head==nullptr || k<=0) return head;
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
            prev->next=temp->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

node*removeanyvalue(node*head,int val){
    if(head==nullptr) return nullptr;
    if(head->value==val){
        node*temp=head;
        head=head->next;
        delete temp;
        return head;
    }

    node*temp=head;
    node*prev=nullptr;
    while(temp!=nullptr){
        if(temp->value==val){
            prev->next=temp->next;
            delete temp;
            break;
        }
        prev=temp;
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

    head=removeathead(head);
    node*temp=head;
    while(temp!=nullptr){
        std::cout<<temp->value<<" ";
        temp=temp->next;
    }

    std::cout<<std::endl;

    head=removeattail(head);
    temp=head;
    while(temp!=nullptr){
        std::cout<<temp->value<<" ";
        temp=temp->next;
    }

    std::cout<<std::endl;
    int k; std::cout<<"Enter k: "; std::cin>>k;
    head=removeatk(head,k);
    temp=head;
    while(temp!=nullptr){
        std::cout<<temp->value<<" ";
        temp=temp->next;
    }

    std::cout<<std::endl;
    int val; std::cout<<"Enter the value: "; std::cin>>val;
    head=removeanyvalue(head,val);
    temp=head;
    while(temp!=nullptr){
        std::cout<<temp->value<<" ";
        temp=temp->next;
    }
    return 0;
}