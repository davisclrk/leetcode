#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> nums;
    sort(nums.begin(),nums.end());
    if (nums.empty()) return 0;
    int cnt = 1, max = 1;
    for (int i=1;i<nums.size();i++){
        if (nums[i] == nums[i-1]) continue;
        if (nums[i] == nums[i-1]+1) cnt++;
        else {
            if (cnt > max) max = cnt;
            cnt = 1;
        }
    }
    if (cnt > max) max = cnt;
    // return max;

    // simple solution to first sort the array then simple loop to check if the sequence breaks
    // *note: i think you ignore duplicates which is what line 12 is for
}