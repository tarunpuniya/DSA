#include<iostream>
#include<vector>

std::vector<int>rangesum(std::vector<int>nums,std::vector<std::vector<int>>queries){
    int n = nums.size();

    std::vector<int>prefix(n+1,0);
    for(int i=0; i<n; i++){
        prefix[i+1] = prefix[i]+nums[i];
    }

    std::vector<int>query;

    for(int i=0; i<queries.size(); i++){
        int l = queries[i][0];
        int r = queries[i][1];

        int sum = prefix[r+1] - prefix[l];
        query.push_back(sum);
    }
    return query;
}

int main(){
    std::vector<int>nums = {2,4,6,8,5};
    std::vector<std::vector<int>>queries = {{0,2},{1,3},{2,4}};
    std::vector<int>ans = rangesum(nums,queries);
    for(int i=0; i<ans.size(); i++){
        std::cout<<ans[i]<<" ";
    }
    return 0;
}