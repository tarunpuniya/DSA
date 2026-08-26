#include<iostream>
#include<vector>

std::vector<int> nextgreater(std::vector<int> nums){
    int n = nums.size();
    std::vector<int> ans;
    for(int i=0; i<n; i++){
        bool found = false;
        for(int j= i+1; j<n; j++){
            if(nums[i]<nums[j]){
                ans.push_back(nums[j]);
                found = true;
                break;
            }
        }
        if(!found){
            ans.push_back(-1);
        }
       
    }
    return ans;
}

int main(){
    std::vector<int> nums={4,3,9,1,6,8,2};
    std::vector<int> result = nextgreater(nums);
    for(int x: result){
        std::cout<<x<<" ";
    }
    return 0;
}