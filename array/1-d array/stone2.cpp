#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstring>

class solution{
    public:   
        int n;
        int t[2][101][101];
        int solveforAlice(std::vector<int>&piles,int person,int i , int M){
            if(i>=n) return 0;
            if(t[person][i][M]!=-1) return t[person][i][M];
            int result = person==1?-1:INT_MAX;
            int stones = 0;
            for(int x=1;x<=std::min(2*M,n-i);x++){
                stones+=piles[i+x-1];
                if(person==1){
                    result=std::max(result,stones+solveforAlice(piles,0,i+x,std::max(M,x)));
                }else{
                    result=std::min(result,solveforAlice(piles,1,i+x,std::max(M,x)));
                }
            }
            return t[person][i][M]=result;

        }
        int stoneGameII(std::vector<int>&piles){
            n=piles.size();
           std::memset(t,-1,sizeof(t));
            return solveforAlice(piles,1,0,1);
        }
};

int main(){
    int n; std::cout<<"Enter the no. of piles: "; std::cin>>n;
    std::vector<int> piles;
    for(int i=0; i<n; i++){
        int ele; std::cout<<"Enter the stones in pile: "; std::cin>>ele;
        piles.push_back(ele);
    }
    solution sol;
    int result = sol.stoneGameII(piles);
    std::cout << "Maximum stones Alice can get: " << result << std::endl;
    return 0;
}