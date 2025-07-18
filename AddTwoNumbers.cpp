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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode((l1->val + l2->val) % 10);
        bool carry = l1->val + l2->val >= 10;

        ListNode* prev = head;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 != nullptr && l2 != nullptr){
            int val = l1->val + l2->val;
            if (carry) val++;
            if (val >= 10) carry = true;
            else carry = false;
            val %= 10;
            ListNode* node = new ListNode(val);
            prev->next = node;
            prev = node;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr){
            int val = l1->val;
            if (carry) val++;
            if (val >= 10) carry = true;
            else carry = false;
            val %= 10;
            ListNode* node = new ListNode(val);
            prev->next = node;
            prev = node;
            l1 = l1->next;
        }

        while (l2 != nullptr){
            int val = l2->val;
            if (carry) val++;
            if (val >= 10) carry = true;
            else carry = false;
            val %= 10;
            ListNode* node = new ListNode(val);
            prev->next = node;
            prev = node;
            l2 = l2->next;
        }

        if (carry){
            ListNode* node = new ListNode(1);
            prev->next = node;
        }

        return head;
    }
};

// rather simple, add nodes from the left to right since theyre in increasing magnitude
// calculate carries where mecessary, and process lists alone at end since not necessarily same len