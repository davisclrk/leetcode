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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;

        ListNode* head = list1->val <= list2->val ? list1 : list2;
        ListNode* prev = head;
        while (list1 != nullptr || list2 != nullptr){
            ListNode* cur;
            if (list1 == nullptr) {
                cur = list2;
                list2 = list2->next;
            }
            else if (list2 == nullptr) {
                cur = list1;
                list1 = list1->next;
            }
            else {
                if (list1->val <= list2->val){
                    cur = list1;
                    list1 = list1->next;
                } else {
                    cur = list2;
                    list2 = list2->next;
                }
            }
            
            prev->next = cur;
            prev = cur;
        }

        return head;
    }
};

// pretty easy, just like merging two sorted arrays but using pointer logic instead