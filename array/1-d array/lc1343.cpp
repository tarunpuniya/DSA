#include<iostream>
#include<vector>

int result(std::vector<int> nums,int k,int threshold){
    int n = nums.size();
    int left = 0;
    int sum = 0;
    int count=0;
    int ans = 0;

    for(int right=0; right<k; right++){
        sum+=nums[right];
    }
    ans=sum/k;
    if(ans>=threshold) count++;

    for(int right=k; right<n; right++){
        sum-=nums[left];
        sum+=nums[right];
        left++;

        ans = sum/k;
        if(ans>=threshold) count++;
    }
    return count;
 
}

int main(){
    std::vector<int> nums = {11,12,13,14,6,7,8,4};
    int k; std::cout<<"Enter k: "; std::cin>>k;
    int threshold; std::cout<<"Enter threshold: "; std::cin>>threshold;

    int ans = result(nums,k,threshold);
    std::cout<<ans<<" ";
    return 0;
}