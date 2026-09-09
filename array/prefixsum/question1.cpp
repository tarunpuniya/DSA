// you have given an array called nums return the prefix sum of an arry 
// nums = [2,3,5,3,6,7]
// output = [2,5,10,13,19,26]

#include<iostream>
#include<vector>

std::vector<int>result(std::vector<int>nums){
    int n = nums.size();
    std::vector<int>prefix(n);
    prefix[0]=nums[0];

    for(int i=1; i<n; i++){
        prefix[i]=prefix[i-1]+nums[i];
    }
    return prefix;
}

int main(){
    std::vector<int>nums={2,3,5,3,6,7};
    std::vector<int>ans=result(nums);
    for(int i=0; i<ans.size(); i++){
        std::cout<<ans[i]<<" ";
    }
    return 0;

}