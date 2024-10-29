#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    vector<vector<char>> grid;
    
    int islands = 0;
    int rows = grid.size(), cols = grid[0].size();
    pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool vis[rows][cols];
    memset(vis,0,sizeof(vis));
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            if (!vis[i][j] && grid[i][j] == '1'){
                vis[i][j] = 1;
                islands++;
                queue<pair<int,int>> q;
                q.push({i,j});

                while (!q.empty()){
                    pair<int,int> cur = q.front();
                    q.pop();
                    int x = cur.first, y = cur.second;
                    for (auto k:dir){
                        int nx = x + k.first, ny = y + k.second;
                        if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || vis[nx][ny] || grid[nx][ny] == '0'){
                            continue;
                        }
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    // return islands;

    // extremely basic flood fill to iterate through 2d matrix and run flood fill if not visited by flood fill yet
}