/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* removeHelper(ListNode* head, int n) {
        ListNode* t = head;
        if(n==1) {
            if(head->next == NULL) {
                ListNode* emptyHead;
                return emptyHead;
            }else {
                head = head->next;
                return head;
            }
        }else {
            int k = n-2;

            while(k--) {
                t = t->next;
            } 
            ListNode* todelete = t->next;
            t->next = t->next->next;
            delete(todelete);

            return head;
        }
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        ListNode* h1 = reverseList(head);
        ListNode* h2 = removeHelper(h1, n);
        ListNode* h3 = reverseList(h2);

        return h3;
    }
};