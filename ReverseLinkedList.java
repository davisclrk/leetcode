
//  Definition for singly-linked list.
public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode prevNode = new ListNode(head.val);
        ListNode cur = head.next;
        while (cur != null){
            ListNode newNode = new ListNode(cur.val, prevNode);
            prevNode = newNode;
            cur = cur.next;
        }
        return prevNode;
    }
}
