#include<iostream>
#include<vector> 


using namespace std;

vector<int> sortedSquare(vector<int> &nums){
    int n = nums.size();
    vector<int> ans(n);
    int l=0; 
    int r=n-1;
    int idx = n-1;
    while(l<=r){
        int leftsq = nums[l]*nums[l];
        int rightsq = nums[r]*nums[r];

        if(leftsq>rightsq){
            ans[idx]=leftsq;
            l++;
        }else{
            ans[idx]=rightsq;
            r--;
        }
        idx--;
    }
    return ans;
    
}

int main(){
    int n; cout<<"Enter the size: "; cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++){
        int ele; cout<<"Enter the elements: "; cin>>ele;
        nums.push_back(ele);
    }
    vector<int>result = sortedSquare(nums);
    for (int x : result) {
    cout << x << " ";
}

}