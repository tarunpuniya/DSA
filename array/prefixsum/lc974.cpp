#include<iostream>
#include<vector>
#include<unordered_map>

int result(std::vector<int>nums,int k){
    int n = nums.size();
    int sum = 0;
    int ans = 0;

    std::unordered_map<int,int>freq;
    freq[0]=1;

    for(int i=0; i<n; i++){
        sum+=nums[i];
        int rem = ((sum%k)+k)%k;
        ans+=freq[rem];
        freq[rem]++;
    }
    return ans;
}
int main(){
    int n; std::cout<<"Enter the size: "; std::cin>>n;
    std::vector<int> nums(n);

    for(int i=0; i<n; i++){
    std::cin>>nums[i];
   }
   int k; std::cin>>k;
   int ans = result(nums,k);
   std::cout<<ans;
   return 0;
}