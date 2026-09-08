// question 3 = variable sized window
// Given an array of positive integers nums and an integer target, 
// find the minimum length of a contiguous subarray whose sum is greater than or equal to target.
// Agar koi valid subarray nahi milta, return 0.
// Example:
// nums = [2,3,1,2,4,3]
// target = 7
// Possible windows:
// [2,3,1,2] = 8  → length 4
// [3,1,2,4] = 10 → length 4
// [4,3]     = 7  → length 2 ✅
// Output: 2

#include<iostream>
#include<vector>
#include<algorithm>

int result(std::vector<int>nums,int target){
    int n = nums.size();
    int sum = 0;
    int left = 0;
    int mincount = n+1;

    for(int right=0; right<n; right++){
        sum+=nums[right];

        while(sum>=target){
            int length = right-left+1;
            mincount=std::min(mincount,length);

            sum-=nums[left];
            left++;
        }
    }
    if(mincount==n+1) return 0;
    return mincount;
}

int main(){
    std::vector<int>nums={2,3,1,2,4,3};
    int target; std::cout<<"Enter target: "; std::cin>>target;
    int ans = result(nums,target);
    std::cout<<ans;
    return 0;
}


// question 4 = Longest Subarray With Sum ≤ K
// Given an array of positive integers nums and an integer k, 
//find the maximum length of a contiguous subarray whose sum is less than or equal to k.
// Example
// nums = [1, 2, 1, 0, 1, 1, 0]
// k = 4
// Valid windows mein se longest:
// [1, 2, 1, 0] → sum = 4 → length = 4
// Output: 4

#include<iostream>
#include<vector>
#include<algorithm>

int result(std::vector<int>nums,int k){
    int n = nums.size();
    int sum = 0;
    int left = 0;
    int maxcount = 0;

    for(int right=0; right<n; right++){
        sum+=nums[right];
        while(sum>k){
            sum-=nums[left];
            left++;   
        }
         int length = right-left+1;
        maxcount=std::max(maxcount,length); 
    }
    return maxcount;
}
int main(){
    std::vector<int>nums={1,2,1,0,1,1,0};
    int k; std::cout<<"Enter k: "; std::cin>>k;
    int ans = result(nums,k);
    std::cout<<ans;
    return 0;

}


// Question 5 = Longest Subarray With At Most K Odd Numbers

// Given an integer array nums and an integer k, 
//find the length of the longest contiguous subarray containing at most k odd numbers.

// Example
// nums = [2,1,4,3,6,8,5]
// k = 2
// output = 6;


#include<iostream>
#include<vector>
#include<algorithm>

int result(std::vector<int>nums,int k){
    int n = nums.size();
    int left = 0;
    int oddcount = 0;
    int maxlength= 0;
    
    for(int right=0; right<n; right++){
        if(nums[right]%2!=0)  oddcount++;
        while(oddcount>k){
            if(nums[left]%2!=0) oddcount--;
            left++;
        }
        int length = right-left+1;
        maxlength = std::max(maxlength,length);
    }
    return maxlength;
}
int main(){
    std::vector<int>nums={2,1,4,3,6,8,5};
    int k; std::cout<<"enter k: "; std::cin>>k;
    int ans = result(nums,k);
    std::cout<<ans;
    return 0;
}


// Question 6
// nums = [1, 2, 1, 2, 3]
// k = 2
// output = 4
// Hume longest continuous window find karni hai jisme maximum 2 different/distinct numbers hon.

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

int ans(std::vector<int>nums,int k){
    int n = nums.size();
    int left = 0;
    int count = 0;
    int maxcount = 0;
    std::unordered_map<int,int> frequency;

    for(int right=0; right<n; right++){
         frequency[nums[right]]++;
        while(frequency.size()>k){
            frequency[nums[left]]--;
            if(frequency[nums[left]]==0){
                frequency.erase(nums[left]);
            }
            left++;
        }
        int length = right-left+1;
        maxcount = std::max(maxcount,length);
}
return maxcount;
}
int main(){
    std::vector<int>nums={1,2,1,2,3};
    int k; std::cout<<"Enter k: "; std::cin>>k;
    int result = ans(nums,k);
    std::cout<<result;
    return 0;
}