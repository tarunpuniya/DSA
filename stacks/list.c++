// Implementation of stack using linked list
#include <bits/stdc++.h>
class node{
    public:
    int value;
    node*next;

    node(int data){
        value=data;
        next=nullptr;

    }
};

class stack{
    public:
    node*head;
    int capacity;
    int currentsize;
    stack(int c){
        this->capacity=c;
        this->currentsize=0;
        head=nullptr;
    }
    bool isempty(){
        return this->head==nullptr;
    }
    bool isfull(){
        return this->currentsize==this->capacity;
    }

    void push(int value){
        if(this->currentsize==this->capacity){
            std::cout<<"Overflow";
            return;
        }
        node*new_node = new node(value);
        new_node->next=head;
        head=new_node;
        this->currentsize++;
    }

    void pop(){
        if(head==nullptr){
            std::cout<<"Underflow";
            return;
        }
        node*temp=head;
        head=head->next;
        delete temp;
    }

    int getTop(){
        if(head==nullptr){
            std::cout<<"Stack is empty";
            return -1;
        }
        return head->value;
    }
};

int main() {

    stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << s.getTop() << std::endl;

    s.pop();

    std::cout << s.getTop() << std::endl;

    s.pop();

    std::cout << s.getTop() << std::endl;

    return 0;
}