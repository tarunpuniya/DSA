#include<iostream>
#include<vector>
using namespace std;

bool searchmatrix(vector<vector<int>>&matrix , int target){
    if(matrix.empty() || matrix[0].empty()) return false;
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0;
    int col = m-1;
    while(row<n && col>=0){
        if(matrix[row][col]==target) return true;
        else if(matrix[row][col]>target) col--;
        else row++;
    }
    return false;
    
}

int main(){
    int n; cout<<"Enter the row: "; cin>>n; 
    int m; cout<<"Enter the column: "; cin>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }

    int target; cout<<"Enter the target: "; cin>>target;
    bool result = searchmatrix(matrix, target);
    if(result) cout<<"Target found in the matrix."<<endl;
    else cout<<"Target not found in the matrix."<<endl;
}