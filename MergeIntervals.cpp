#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<vector<int>> intervals;

    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> ans;
    int left = intervals[0][0], right = intervals[0][1];
    for (int i=0;i<n-1;i++){
        if (intervals[i+1][0] <= right){
            right = max(right,intervals[i+1][1]);
        }else{
            ans.push_back({left, right});
            left = intervals[i+1][0];
            right = intervals[i+1][1];
        }
    }
    ans.push_back({left, right});
    // return ans;

    // pretty simple, keep track of left and rights and since for loop goes to n-1 push back at the end too
    // right = max(right, intervals[i+1][1]) because second interval might be fully contained in the first
}