#include <bits/stdc++.h>
using namespace std;
int heights[105][105];
int visited[105][105];
int longest[105][105];
int row, col;
int dfs(int i,int j){
    if(visited[i][j] != 0){
        return longest[i][j];
    }
    visited[i][j] = 1;
    int res = 1;
    if(heights[i][j] > heights[i-1][j] && i > 1){
        res = max(res, dfs(i-1,j)+1);
    }
    if(heights[i][j] > heights[i+1][j] && i < row){
        res = max(res, dfs(i+1,j)+1);
    }
    if(heights[i][j] > heights[i][j-1] && j > 1){
        res = max(res, dfs(i,j-1)+1);
    }
    if(heights[i][j] > heights[i][j+1] && j < col){
        res = max(res, dfs(i,j+1)+1);
    }
    longest[i][j] = res;
    return res;
}

int main(){
    cin >> row >> col;
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            cin >> heights[i][j];
        }
    }
    int res = 0;
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            if(!visited[i][j])
                // res = dfs(i,j);// 最长路径
                res = max(res, dfs(i,j));
        }
    }
    cout << res;
}