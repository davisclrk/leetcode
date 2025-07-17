// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }

        return false;
    }
};

// tortoise and hare, solves in O(n) at worse because at max, fast pointer is n-1 nodes away from slow pointer
// and since the fast pointer gains 1 step on slow pointer (since it goes fast->next->next whereas slow is slow->next)
// fast will catch up in n-1 steps max so O(n) (neetcode has a video on this if i forget this)