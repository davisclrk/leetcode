#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main(){
    vector<char> tasks;
    int n;

    int totaltasks = tasks.size();
    int ans = 0;
    unordered_map<char, int> tasksLeft;
    for (auto i:tasks) tasksLeft[i]++;

    priority_queue<pair<int,char>> pq;
    queue<pair<int, char>> q;
    for (auto &i:tasksLeft) pq.push({i.second, i.first});
    
    while (totaltasks > 0){
        ans++;
        if (!pq.empty()){
            auto cur = pq.top(); // cur = {freq[char], char}

            pq.pop();
            tasksLeft[cur.second]--;
            totaltasks--;

            if (tasksLeft[cur.second] > 0) q.push({ans, cur.second});
        }

        while (!q.empty()){ // {lastupdated, char}
            auto qcur = q.front();
            if (ans - n >= qcur.first){ // ans - n >= lastupdated
                q.pop();
                pq.push({tasksLeft[qcur.second], qcur.second});
            } else break;
        }
    }

    return ans;

    // ans stores how many seconds have passed
    // greedily always pick the task with most tasks remaining with priority queue
    // use secondary queue to store tasks that are still on cooldown (ans - n < lastupdated, less than n seconds have passed since task last used)
    // the secondary queue is sorted by minimum lastUpdated values by default so we can break if the first ans - n < lastupdated
    // if ans - n >= lastupdated, then the task is ready to be used by cpu again since n seconds have passed since the last update
    // thus we push back {tasksLeft[char], char} into pq.

    // there is an o(n) solution too that i am not aware of yet
}