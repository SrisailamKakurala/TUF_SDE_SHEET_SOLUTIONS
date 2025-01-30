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
    /**
     * Merges two sorted singly linked lists into one sorted linked list.
     *
     * @param list1 Pointer to the head of the first sorted linked list.
     * @param list2 Pointer to the head of the second sorted linked list.
     * @return Pointer to the head of the merged sorted linked list.
     *
     * The function iteratively merges the two lists while maintaining sorted order.
     * It compares the values of the nodes from both lists and appends the smaller one
     * to the resulting list. If one list gets exhausted before the other, the remaining
     * elements from the non-empty list are directly appended.
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Handle cases where one or both lists are empty
        if (list1 == nullptr && list2 != nullptr) return list2;
        if (list2 == nullptr && list1 != nullptr) return list1;
        if (list1 == nullptr && list2 == nullptr) return list1; // (nullptr)

        // Pointers for traversing the lists
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        // Pointer for storing the head of the merged list
        ListNode* res;

        // Pointer to track the last node of the merged list
        ListNode* t3;

        // Determine the starting node of the merged list
        if (t1->val <= t2->val) {
            res = t1;
            t1 = t1->next;
        } else {
            res = t2;
            t2 = t2->next;
        }

        t3 = res; // `t3` starts at the first selected node

        // Iteratively merge both lists
        while (t1 != nullptr && t2 != nullptr) {
            if (t1->val <= t2->val) {
                t3->next = t1;  // Link the smaller node to the merged list
                t3 = t3->next;  // Move the tail pointer forward
                t1 = t1->next;  // Advance in list1
            } else {
                t3->next = t2;
                t3 = t3->next;
                t2 = t2->next;
            }
        }

        // If any elements are left in list1, append them
        while (t1 != nullptr) {
            t3->next = t1;
            t3 = t3->next;
            t1 = t1->next;
        }

        // If any elements are left in list2, append them
        while (t2 != nullptr) {
            t3->next = t2;
            t3 = t3->next;
            t2 = t2->next;
        }

        // Return the head of the merged sorted list
        return res;
    }
};
