#include <vector>

using namespace std;

int main(){
    vector<int> nums;
    int target;

    int l = 0, r = nums.size() - 1;
    while (l <= r){
        int mid = l + (r-l)/2;
        if (target == nums[mid]) return mid;
        if (nums[l] <= nums[mid]){
            // run regular binary search since you are looking in the sorted portion
            if (nums[l] <= target && target <= nums[mid]) r = mid-1;
            else l = mid+1;
        }else{
            // reverse the above
            if (nums[mid] <= target && target <= nums[r]) l = mid+1;
            else r = mid-1;
        }
    }
    // return -1;
}