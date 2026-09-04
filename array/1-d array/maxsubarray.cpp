#include<iostream>
#include<vector>
#include<algorithm>

int maxsubarray(std::vector<int>nums,int k){
    int n=nums.size();
    int left = 0;
    int sum = 0;
    int maxsum = 0;

    for(int right=0; right<k; right++){
        sum+=nums[right];
    }
    maxsum = sum;
    for(int right=k; right<n; right++){
        sum-=nums[left];
        sum+=nums[right];
        left++;

        maxsum=std::max(maxsum,sum);
    }
    return maxsum;
}

int main(){
    std::vector<int>nums={4,5,2,8,7,9};
    int k; std::cout<<"Enter the k: "; std::cin>>k;
    int ans = maxsubarray(nums,k);
    std::cout<<ans;
    return 0;
}