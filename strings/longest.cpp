// longest common prefix

#include<bits/stdc++.h>

std::string common(std::vector<std::string>&str){
    if(str.empty()) return "";
    std::string ans = "";
    for(int i=0; i<str[0].size(); i++){
        for(const std::string &s:str){
            if(i==s.size() || s[i]!=str[0][i]){
                return ans;
            }
        }
        ans+=str[0][i];
    }
    return ans;
}

int main(){
    std::vector<std::string> str = {"flower","flow","flight"};
    std::string result = common(str);
    std::cout<<result;

}