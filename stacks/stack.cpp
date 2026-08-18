// Implementation of stacks using array

#include<iostream>
class stack{
    private:
    int capacity;
    int*arr;
    int top;
    public:
    stack(int c){
        this->capacity=c;
        arr = new int[c];
        this->top = -1;
    }

    void push(int data){
        if(this->top==this->capacity-1){
            std::cout<<"Overflow";
            return;
        }
        this->top++;
        this->arr[this->top]=data;
    }

    void pop(){
    if(this->top == -1){
        std::cout << "Underflow";
        return;
    }

    this->top--;
}

    int gettop(){
        if(this->top==-1){
            std::cout<<"Stack is empty";
            return -1;
        }
        return this->arr[this->top];
    }

    bool isempty(){
        return this->top == -1;
    }
};

int main(){
    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout<<s.gettop()<<'\n';
    s.push(4);
    s.push(5);
    std::cout<<s.gettop()<<'\n';
    s.push(6);

    return 0;

}