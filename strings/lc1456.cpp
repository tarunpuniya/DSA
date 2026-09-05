#include<bits/stdc++.h>

std::vector<char>vowel = {'a','e','i','o','u'};
bool isVowel(char ch , std::vector<char>&vowel){
    for(int i=0; i<vowel.size(); i++){
        if(ch==vowel[i]) return true;
    }
    return false;
}

int maxvowels(std::string&s,int k){
    int n = s.size();
    int maxcount = 0;
    int count = 0;
    int left = 0;

    for(int right=0; right<k; right++){
        if(isVowel(s[right],vowel)) count++;
    }
    maxcount = count;

    for(int right=k; right<n; right++){
        if(isVowel(s[left],vowel)) count--;
        left++;
        if(isVowel(s[right],vowel)) count++;
        maxcount = std::max(maxcount,count);
    }
    return maxcount;
}

int main(){
    std::string s; std::cout<<"Enter your string: "; std::cin>>s;
    int k; std::cout<<"Enter k: "; std::cin>>k;
    int ans = maxvowels(s,k);
    std::cout<<ans<<" ";
    return 0;

}