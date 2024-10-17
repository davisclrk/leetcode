#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    vector<vector<int> > matrix;

    // for (int i=0;i<4;i++){
    //     for (int j=0;j<4;j++){
    //         cin >> matrix[i][j];
    //     }
    // }

    int rows = matrix.size(), cols = matrix[0].size();
    pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    queue<pair<int,int> > q;
    bool vis[rows][cols];
    int dis[rows][cols];
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));

    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            if (matrix[i][j] == 0){
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }

    while (!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        for (pair<int,int> i:dir){
            int newx = x + i.first, newy = y + i.second;
            if (newx < 0 || newy < 0 || newx >= rows || newy >= cols || vis[newx][newy] || matrix[newx][newy] == -1) continue;
            vis[newx][newy] = 1;
            dis[newx][newy] = dis[x][y] + 1;
            q.push({newx,newy});
        }
    }

    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }

    // return dis;
}