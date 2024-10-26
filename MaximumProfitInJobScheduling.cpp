#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> startTime, endTime, profit;

    int n = startTime.size();
    vector<pair<pair<int,int>, int>> v;
    for (int i=0;i<n;i++){
        v.push_back({{endTime[i], startTime[i]}, profit[i]});
    }

    sort(v.begin(), v.end());

    for (int i=0;i<n;i++){
        endTime[i] = v[i].first.first;
        startTime[i] = v[i].first.second;
        profit[i] = v[i].second;
    }
    
    int dp[n];
    dp[0] = profit[0];
    for (int i=1;i<n;i++){
        int l = upper_bound(endTime.begin(), endTime.begin() + i, startTime[i]) - endTime.begin() - 1;

        int prof = profit[i];
        if (l != -1) prof += dp[l];

        dp[i] = max(prof, dp[i-1]);
    }

    return dp[n-1];

    // dp + binary search solution. dp[i] represents max profit of first i tasks
    // upper_bound on endTime, endTime + i to find first task that ends before the start of the current task
    // limit to endTime + i so that we only consider tasks that have already been processed
    // subtract one to get index of first task that ends before the start of the current task (upper bound gives >, subtracting 1 gives <=)
    // if l == -1, then there are no tasks that end before the start of the current task. else add profit of that task (first one that ends before cur start) to cur profit
    // dp[i] = max of profit and profit of not including the current task (dp[i-1])
}