#include<iostream>

class node{
    public:
     int value;
     node*next;
     node*prev;

    node(int data){
        value=data;
        next=nullptr;
        prev = nullptr;
    }
};

node*deletehead(node*head){
    if(head==nullptr || head->next ==nullptr) return nullptr;
    node*temp=head;
    head=head->next;
    if(head!=nullptr) head->prev=nullptr;
    delete temp;
    return head;
}

node* deleteTail(node* head) {

    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    node* newTail = tail->prev;
    newTail->next = nullptr;
    delete tail;
    return head;
}

int main() {

    int n;
    std::cout << "Enter number of nodes: ";
    std::cin >> n;

    node* head = nullptr;
    node* tail = nullptr;

    for (int i = 0; i < n; i++) {

        int value;
        std::cout << "Enter value: ";
        std::cin >> value;

        node* newNode = new node(value);

      
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    node*temp=head;
    while(temp!=nullptr){
        std::cout<<temp->value<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;

    head=deletehead(head);
    temp=head;
    while(temp!=nullptr){
        std::cout<<temp->value<<" ";
        temp=temp->next;
    }

    std::cout<<std::endl;
    head=deleteTail(head);
    temp=head;
    while(temp!=nullptr){
        std::cout<<temp->value<<" ";
        temp=temp->next;
    }
    return 0;

}