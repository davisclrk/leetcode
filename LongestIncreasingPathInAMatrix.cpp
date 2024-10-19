#include <iostream>
#include <vector>

using namespace std;

int dp[202][202];
bool vis[202][202];
pair<int,int> dir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int main(){
    vector<vector<int>> matrix;

    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int i=0;i<matrix.size();i++){
        for (int j=0;j<matrix[0].size();j++){
            if (!vis[i][j]){
                int pathVal = findMaxPath(matrix, {i,j});
                ans = max(ans, pathVal);
            }
        }
    }
    // return ans;
}

int findMaxPath(vector<vector<int>>& matrix, pair<int,int> cur){
    int x = cur.first, y = cur.second;
    bool flag = false;
    int maxChild = 0;
    vis[x][y] = 1;
    for (auto i:dir){
        int nx = x + i.first, ny = y + i.second;
        if (nx >= 0 && ny >= 0 && nx < matrix.size() && ny < matrix[0].size() && matrix[nx][ny] > matrix[x][y]){
            flag = true;
            if (vis[nx][ny]){
                maxChild = max(maxChild, dp[nx][ny]);
            } else {
                int val = findMaxPath(matrix, {nx, ny});
                maxChild = max(maxChild, val);
            }
        }
    }

    if (!flag){
        dp[x][y] = 1;
        return 1;
    }
    dp[x][y] = maxChild + 1;
    return maxChild + 1;
}

// dfs + memoization to create a top-down dp solution
// utilizes a dp table to avoid recalculating max path value for a cell
// "base case" is when a cell has no neighbors that are greater than it, in which case the max path value is 1
// otherwise, the max path value is 1 + the max path value of the neighbor with the greatest max path value

// runtime is O(n*m) since we can skip over cells that have already been visited 
// (as their max paths have already been calcuated and contributed towards the answer) 
// in the main function for loop