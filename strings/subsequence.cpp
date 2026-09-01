#include<iostream>
#include<string>

bool result(std::string s , std::string t){
    int i=0 , j=0;
    while(i<s.size() && j<t.size()){
        if(s[i]==t[j]){
            i++;
            j++;
        }else{
            j++;
        }
    }
    return i==s.size();
}

int main(){
    std::string s = "abc";
    std::string t = "adbghc";

    bool ans = result(s,t);
    std::cout<<std::boolalpha<<ans;
}