// Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        for (int i=0;i<n;i++) fast = fast->next;
        if (fast == nullptr){ // means that n = list size
            return head->next;
        }

        while (fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        // now slow is 1 node before the node we want to remove
        slow->next = slow->next->next;
        return head;
    }
};

// staggers fast node n nodes ahead such that the slow node will be n nodes from the end of the list when fast node reaches the end