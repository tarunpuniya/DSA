#include<iostream>
#include<string>
#include<stack>

bool isvalid(std::string str){
    std::stack<char> s;
    for(int i=0; i<str.size(); i++){
        char ch = str[i];
        if(ch=='(' or ch=='[' or ch=='{'){
            s.push(ch);
        }else{
            if(ch==')' and !s.empty() and s.top()=='('){
                s.pop();
            }else if(ch==']' and !s.empty() and s.top()=='['){
                s.pop();
            }else if(ch=='}' and !s.empty() and s.top()=='{'){
                s.pop();
            }else{
                return false;
            }
        }
    }
    return s.empty();
}

int main(){
    std::string str = "()(}(())";
    std::cout<<isvalid(str)<<"\n";
    return 0;

}