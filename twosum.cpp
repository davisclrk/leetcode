#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 0x3f3f3f3f;
typedef long long ll;

using namespace std;

int main(){
    vector<int> nums, sorted, ans;
    int target;
    for (auto i:nums) sorted.push_back(i);
    sort(sorted.begin(),sorted.end());
    int p1 = 0, p2 = sorted.size()-1;
    while (true) {
        if (sorted[p1]+sorted[p2] == target) {
            for (int i=0;i<nums.size();i++) {
                if (nums[i] == sorted[p1] || nums[i] == sorted[p2]) ans.push_back(i);
            }
            break;
        } else if (sorted[p1]+sorted[p2] > target) p2--;
        else p1++;
    }
    for (auto i:ans) cout << i << " ";
    // this question uses the two pointers technique by first sorting the array and then iterating through the sorted array
    // with two pointers until the sum of the sorted array's indicies add to the target
    // then I iterate through the original array again to recover the original indicies and return them
}