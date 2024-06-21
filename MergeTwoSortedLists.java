// Definition for singly-linked list.
public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
 
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) return list2;
        else if (list2 == null) return list1;

        ListNode cur1 = list1, cur2 = list2;
        ListNode head = new ListNode();
        ListNode prev = head;
        while (cur1 != null || cur2 != null){
            if (cur1 == null){
                prev.next = cur2;
                prev = cur2;
                cur2 = cur2.next;
            } else if (cur2 == null){
                prev.next = cur1;
                prev = cur1;
                cur1 = cur1.next;
            } else {
                if (cur1.val <= cur2.val){
                    prev.next = cur1;
                    prev = cur1;
                    cur1 = cur1.next;
                } else {
                    prev.next = cur2;
                    prev = cur2;
                    cur2 = cur2.next;
                }
            }
        }
        return head.next;

        // if either of the lists is at the end then use the other list
        // otherwise take the min value and move the pointer of that list up
    }
}