#include<iostream>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>>sum(std::vector<int>&nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    std::vector<std::vector<int>>ans;

    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j= i+1;
        int k =n-1;

        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum<0) j++;
            else if(sum>0) k--;
            else{
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]){
                    j++;
                }
            }

        }
    }
    return ans;

}

int main(){
    int n; std::cout<<"Enter the size: "; std::cin>>n;
    std::vector<int> nums;
    for(int i=0; i<n; i++){
        int ele; std::cout<<"Enter the elements: "; std::cin>>ele;
        nums.push_back(ele);
    }

    std::vector<std::vector<int>>ans = sum(nums);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            std::cout<<ans[i][j]<<" ";
        }
        std::cout << "\n";
    }
    return 0;

}