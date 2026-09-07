#include<iostream>
#include<vector>
#include<algorithm>

int result(std::vector<int>customers,std::vector<int>grumpy,int minutes){
    int n = customers.size();
    int left = 0;
    int sum = 0;
    int maxsum = 0;
    for(int right=0; right<minutes; right++){
        if(grumpy[right]==1) sum+=customers[right];
    }
    maxsum = sum;
    for(int right=minutes; right<n; right++){
        sum+=customers[right]*grumpy[right];
        sum-=customers[left]*grumpy[left];
        left++;
        maxsum = std::max(maxsum,sum);
    }
    int total = maxsum;
    for(int i=0; i<n; i++){
        if(grumpy[i]==0) total+=customers[i];
    }
    return total;
}

int main(){
    std::vector<int>customers = {1,0,1,2,1,1,7,5};
    std::vector<int>grumpy =  {0,1,0,1,0,1,0,1};
    int minutes = 3;
    int ans = result(customers,grumpy,minutes);
    std::cout<<ans<<" ";
}