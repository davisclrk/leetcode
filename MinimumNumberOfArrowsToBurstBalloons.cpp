#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    vector<vector<int>> points;

    sort(points.begin(), points.end(), [](auto &left, auto &right) {
        return left[1] < right[1];
    });

    if (points.size() == 1) return 1;

    int prev_end = points[0][1];
    int ans = 1;
    for (int i=1;i<points.size();i++){
        if (points[i][0] > prev_end){
            prev_end = points[i][1];
            ans++;
        }
    }

    return ans;

    // line sweep
    // every balloon must be popped, so we can sort the balloons by x_end and pop as many balloons as possible with one arrow for the end of that balloon
    // we cant iterate through the range of every balloon as that might iterate through all values of x
    // instead, simply iterate through all balloons while keeping track of a "current end" for the balloon
    // if the start of the balloon is <= prev_end, then it is in the range and will be popped. otherwise, update the current end to the new balloon as the new balloon is past the old balloon which we popped.
}