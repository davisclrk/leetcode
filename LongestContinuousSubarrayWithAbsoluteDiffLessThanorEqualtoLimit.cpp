#include <vector>
#include <deque>
#include <algorithm>

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 1, l = 0;
        int minimum = nums[0], maximum = nums[0];
        deque<int> minq, maxq;
        minq.push_back(nums[0]);
        maxq.push_back(nums[0]);
        
        for (int r=1;r<nums.size();r++){
            while (!minq.empty() && minq.back() > nums[r]) minq.pop_back();
            minq.push_back(nums[r]);
            while (!maxq.empty() && maxq.back() < nums[r]) maxq.pop_back();
            maxq.push_back(nums[r]);

            minimum = minq.front();
            maximum = maxq.front();
            while (l < r && maximum - minimum > limit){
                if (nums[l] == minq.front()) {
                    minq.pop_front();
                    minimum = minq.front();
                }
                if (nums[l] == maxq.front()) {
                    maxq.pop_front();
                    maximum = maxq.front();
                }
                l++;                
            }
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

// sliding window using monotonic deques to track the next max/min if the cur slides out of the window