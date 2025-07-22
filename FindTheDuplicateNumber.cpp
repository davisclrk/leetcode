#include <vector>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0; // represents indicies in the array
        while (true){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if (slow == fast) break;
        }

        int newslow = 0;
        while (newslow != slow){
            slow = nums[slow];
            newslow = nums[newslow];
        }

        return newslow;
    }
};

// very unintuitive tortoise and hare solution, this problem is acutally a linked list problem
// since every number is in the range 1-n and we have n+1 nodes there must be a cycle
// and also since 0 is not in the range of possible numbers index 0 is guaranteed to not be part of the cycle so we can start there
// utilize tortoise and hare to find the cycle, and then the unintuitive part here is that we set another slow pointer to index 0
// the math works out and shows that the distance between the slow pointer that found the cycle to the start of the cycle (aka the number we want to return since its the duplicate)
// and the distance between the start of the list and the start of the cycle, is actually the exact same

// we can say the dist between ind 0 and start of cycle is p, dist of slow == fast and start of cycle is x, and rest of cycle is c - x where c is length of cycle
// because the fast pointer travels 2 times the slow pointer, we can write fast = 2*slow
// then if we sub values in, we see that p + 2c - x = p + 2c - 2x = 2*slow (we have 2c since fast travels around the cycle 1 extra time than slow)
// p + 2c - x = 2(p + c - x) = 2p + 2c - 2x
// thus p = x