#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> validsequence(string word1 , string word2){
    int n = word1.size();
    int m = word2.size();
    vector<int> last(m,-1);
    int i = n-1; 
    int j = m-1;
    while(i>=0 && j>=0){
        if(word1[i]==word2[j]){
            last[j]=i;
            j--;
        }
        i--;
    }
    vector<int> ans;
    ans.reserve(m);
    bool canskip = true;
    j = 0;
    for(int i=0; i<n && j<m; i++){
        if(word1[i]==word2[j]){
            ans.push_back(i);
            j++;
        }else if(canskip && (j==m-1 || i<last[j+1])){
            canskip=false;
            ans.push_back(i);
            j++;
        }
    }
    if(j==m){
        return ans;
    }
    return {};
}
int main(){
    string word1; cout<<"Enter the characters in word 1: "; cin>>word1;
    string word2; cout<<"Enter the characters in word 2: "; cin>>word2;
    
    vector<int> result = validsequence(word1,word2);
    for(int i : result){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}