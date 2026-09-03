#include<bits/stdc++.h>

std::vector<std::vector<int>> foursum(std::vector<int>&nums,int target){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    std::vector<std::vector<int>> result;

    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j>i+1 and nums[j]==nums[j-1]) continue;
            int k = j+1;
            int l = n-1;

            while(k<l){
                int sum = nums[i]+nums[j]+nums[k]+nums[l];
                if(sum<target) k++;
                else if(sum>target) l--;
                else{
                    result.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;
                    l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                }
            }
        }
        
    }
    return result;
}

int main(){
    int n; std::cout<<"Enter the size: "; std::cin>>n;
    std::vector<int> nums;
    for(int i=0; i<n; i++){
        int ele; std::cout<<"Enter the elements: "; std::cin>>ele;
        nums.push_back(ele);
    }
    int target; std::cout<<"enter the target: "; std::cin>>target;

    std::vector<std::vector<int>> ans = foursum(nums,target);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            std::cout<<ans[i][j]<<" ";
        }
        std::cout << "\n";
    }
    return 0;
}