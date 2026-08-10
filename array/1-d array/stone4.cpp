#include<iostream>
#include<vector>

bool winner(int n){
    std::vector<bool>dp(n+1,false);
    for(int i=0; i<=n; i++){
        for(int j=1; j*j<=i; j++){
            if(dp[i-j*j]==false){
                dp[i]=true;
                break;
            }
        }
    }
    return dp[n];
}
int main(){
    int n; std::cout<<"Enter the n: "; std::cin>>n;
    bool result=winner(n);
    std::cout << std::boolalpha << result << std::endl;
    return 0;
   
}