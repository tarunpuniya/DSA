// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2:
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

// Example 3:
// Input: intervals = [[4,7],[1,4]]
// Output: [[1,7]]
// Explanation: Intervals [1,4] and [4,7] are considered overlapping.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals){
    if(intervals.empty()) return {};
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    int n = intervals.size();
    for(int i=1; i<n; i++){
        if(ans.back()[1]>=intervals[i][0]){
            ans.back()[1] = max(ans.back()[1],intervals[i][1]);
        }
        else{
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}
int main(){
    int m; cout<<"Enter the size: "; cin>>m;
    vector<vector<int>> intervals(m,vector<int>(2));
    for(int i=0; i<m; i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }

    vector<vector<int>> result = merge(intervals);
    for(auto &v : result){
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    return 0;
}
 