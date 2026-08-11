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

node*addtwonumber(node*head1,node*head2){
    node*temp1 = head1;
    node*temp2 = head2;
    node*dummynode=new node(-1);
    node*current = dummynode;
    int carry = 0;

    while(temp1!=nullptr || temp2!=nullptr){
        int sum = carry;
        if(temp1) sum+=temp1->value;
        if(temp2) sum+=temp2->value;
        carry=sum/10;

        current->next = new node(sum%10);
        current = current->next;

        if(temp1) temp1=temp1->next;
        if(temp2) temp2=temp2->next;
    }

    if(carry){
        current->next=new node(carry);
    }
    return dummynode->next;
}

void printList(node* head) {

    while (head != nullptr) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {

    // 342
    node* l1 = new node(2);
    l1->next = new node(4);
    l1->next->next = new node(3);

    // 465
    node* l2 = new node(5);
    l2->next = new node(6);
    l2->next->next = new node(4);

    node* result = addtwonumber(l1, l2);
    printList(result);

    return 0;
}