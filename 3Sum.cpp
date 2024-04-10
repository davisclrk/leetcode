#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> nums;

    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for (int i=0;i<nums.size()-1;i++){
        if (i != 0 && nums[i] == nums[i-1]) continue;
        int target = -nums[i];
        int p1 = i+1, p2 = nums.size()-1;
        while (p1 < p2){
            if (p1 >= p2) break;
            int sm = nums[p1]+nums[p2];
            if (sm == target){
                vector<int> v = {nums[i],nums[p1],nums[p2]};
                ans.push_back(v);
                while (p1 < p2 && nums[p1] == nums[p1 + 1]) p1++;
                p1++;
                while (p1 < p2 && nums[p2] == nums[p2 - 1]) p2--;
                p2--;
            } else if (sm > target) p2--;
            else p1++;
        }
    }
    // return ans;

    // this problem uses the concept of two pointers by fixing one of the three addends and running two pointers on the other two.
    // p1 = i+1 as you do not need to check the numbers before since they would be duplicates (the numbers before were already fixed and thus all solutions involving that number are found already)
}