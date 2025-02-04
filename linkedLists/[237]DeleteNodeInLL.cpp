class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* todelete = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete todelete;
    }
};