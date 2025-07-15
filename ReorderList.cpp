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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rev = slow->next;
        slow->next = nullptr;
        ListNode* node = nullptr;

        while (rev != nullptr){
            ListNode* temp = rev->next;
            rev->next = node;
            node = rev;
            rev = temp;
        }
        
        rev = node;
        while (rev != nullptr){
            ListNode* nxt = head->next;
            head->next = rev;
            ListNode* revNxt = rev->next;
            rev->next = nxt;
            head = nxt;
            rev = revNxt;
        }
    }
};

// tortoise and hare solution to find the midpoint of the linked list
// then we reverse the links of the second half of the list, and set the ends of each of the lists to nullptr
// then we do an easy merge on both lists, and the loop condition is rev != nullptr beceause the second list will always have equal or less than nodes compared to the first half
