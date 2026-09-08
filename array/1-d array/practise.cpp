// Q1 = Maximum Number of Even Numbers in Any K-Length Window
// Given an array of integers and k, find the maximum number of even numbers present in any contiguous subarray of size k.
// Example:
// nums = [1, 2, 4, 7, 6, 8, 3]
// k = 3
// Output: 3

#include<iostream>
#include<vector>
#include<algorithm>

int result(std::vector<int>nums,int k){
    int n = nums.size();
    int left = 0;
    int count = 0;
    int maxcount = 0;

    for(int right=0; right<k; right++){
        if(nums[right]%2==0) count++;
    }
    maxcount = count;
    for(int right=k; right<n; right++){
         if(nums[right]%2==0) count++;
        if(nums[left]%2==0) count--;
        left++;

        maxcount = std::max(maxcount,count);
    }
    return maxcount;
}
int main(){
    std::vector<int>nums={1,2,4,7,6,8,3};
    int k; std::cout<<"Enter k: "; std::cin>>k;
    int ans = result(nums,k);
    std::cout<<ans;
    return 0;
}


// question 2 = Given an integer array nums, an integer k, and a limit, 
//find the number of contiguous subarrays of exactly size k whose sum is strictly less than limit.

// nums = [1, 4, 2, 6, 3, 1]
// k = 3
// limit = 10
// Output: 1

#include<iostream>
#include<vector>
#include<algorithm>

int result(std::vector<int>nums,int K,int limits){
    int n = nums.size();
    int left = 0;
    int sum = 0;
    int count = 0;

    for(int right = 0; right<K; right++){
        sum+=nums[right];  
    }
    if(sum<limits) count++;
    for(int right=K; right<n; right++){
        sum+=nums[right];
        sum-=nums[left];
        left++;
        if(sum<limits) count++;
    }
    return count;
}
int main(){
    std::vector<int>nums={1,4,2,6,3,1};
    int limits; std::cout<<"Enter limit: "; std::cin>>limits;
    int k; std::cout<<"Enter k: "; std::cin>>k;

    int ans = result(nums,k,limits);
    std::cout<<ans;
    return 0;
}