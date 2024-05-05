#include <vector>

using namespace std;

int main(){
    vector<int> nums;
    
    int l = 0, r = nums.size() - 1, ans = nums[0];
    while (l <= r){
        int mid = l + (r-l)/2;
        if (nums[l] <= nums[r]){
            ans = min(ans, nums[l]);
            break;
        }
        if (nums[l] <= nums[mid]){
            ans = min(ans, nums[l]);
            l = mid + 1;
        }
        else{
            ans = min(ans, nums[mid]);
            r = mid - 1;
        }
    }
    // return ans;

    // the idea is to run a modified binary search 
    // if nums[l] <= nums[r] then the array portion currently looked at is sorted and we can just return nums[l] because its the smallest
    // if nums[l] <= nums[mid] then mid is not the smallest yet because its still greater than l, so we update ans to be the minimum of ans and nums[l] and move l to mid + 1
    // if nums[l] > nums[mid] then mid is the smallest so far, so we update ans to be the minimum of ans and nums[mid] and move r to mid - 1
}