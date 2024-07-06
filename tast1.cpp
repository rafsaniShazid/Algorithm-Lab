// Number of island
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>&grid,vector<vector<bool>>&visited,
int n,int m,int row,int col){
    visited[row][col]=true;
    if(row!=0 && !visited[row-1][col] && grid[row-1][col]=='1')
        dfs(grid,visited,n,m,row-1,col);
    if(col!=0 && !visited[row][col-1] && grid[row][col-1]=='1')
        dfs(grid,visited,n,m,row,col-1);
    if(row<(n-1) && !visited[row+1][col] && grid[row+1][col]=='1')
        dfs(grid,visited,n,m,row+1,col);
    if(col<m-1 && !visited[row][col+1] && grid[row][col+1]=='1')
        dfs(grid,visited,n,m,row,col+1);
}
int main(){
    int n,m; cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m,0));
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1' && !visited[i][j]){
                dfs(grid,visited,n,m,i,j);
                count++;
            }
        }
    }

    cout<<"\n No of islands: "<<count<<endl;



    return 0;
}