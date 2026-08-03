#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <climits>

using namespace std;

string winner(vector<int> &stones){
    int n = stones.size();
    vector<int> dp(n+1);
    for(int i=n-1; i>=0; --i){
        int best = INT_MIN;
        int runningsum = 0;

        for(int k=1; k<=3; k++){
            if(i+k>n) break;
            runningsum+=stones[i+k-1];
            best = max(best,runningsum-dp[i+k]);
        }
        dp[i]=best;

    }
    if (dp[0]>0) return "Alice";
    else if (dp[0]<0) return "Bob";
    else return "tie";
}

int main(){
    int n; cout<<"Enter the size: "; cin>>n;
    vector<int> stones;
    for(int i=0; i<n; i++){
        int ele; cout<<"Enter the elements: "; cin>>ele;
        stones.push_back(ele);
    }

    string result = winner(stones);
    cout<<result<<" ";
}