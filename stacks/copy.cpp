// Copy contents of one stack to another in same order

#include<iostream>
#include<stack>

std::stack<int> copystack(std::stack<int> &input){
    std::stack<int> temp;
    while(!input.empty()){
        int current = input.top();
        input.pop();
        temp.push(current);
    }
    std::stack<int> result;
    while(!temp.empty()){
        int current = temp.top();
        temp.pop();
        result.push(current);
    }
    return result;
}

int main(){
    std::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    std::stack<int> result = copystack(st);
    while(not result.empty()){
        int curr = result.top();
        result.pop();
        std::cout<<curr<<" ";
    }
    return 0;

}