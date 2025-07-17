// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        map<Node*, Node*> mp;
        Node* headNew = new Node(head->val);
        Node* cur = head;
        Node* curNew = headNew;
        while (cur->next != nullptr){
            mp[cur] = curNew;
            Node* nextNode = new Node(cur->next->val);
            curNew->next = nextNode;
            curNew = nextNode;
            cur = cur->next;
        }

        curNew->next = nullptr;
        mp[cur] = curNew;

        Node* curOriginal = head;
        curNew = headNew;
        while (curOriginal != nullptr){
            if (curOriginal->random == nullptr){
                curNew->random = nullptr;
            } else{
                Node* rdm = curOriginal->random;
                curNew->random = mp[rdm];
            }
            curNew = curNew->next;
            curOriginal = curOriginal->next;
        }
        
        return headNew;
    }
};

// pretty simple, first generate deep copy of list
// then create a mapping from old LL node to new LL node so that we can assign random nodes in the new list by referencing the old random node