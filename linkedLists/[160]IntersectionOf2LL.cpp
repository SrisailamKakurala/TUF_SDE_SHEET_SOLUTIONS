#include <unordered_set>

// METHOD - 1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr; // If either list is empty, no intersection

        unordered_set<ListNode*> nodes;

        // Traverse listA and store all nodes in the hash set
        ListNode *pA = headA;
        while (pA) {
            nodes.insert(pA);
            pA = pA->next;
        }

        // Traverse listB and check if any node exists in the hash set
        ListNode *pB = headB;
        while (pB) {
            if (nodes.find(pB) != nodes.end()) {
                return pB; // Found the intersection node
            }
            pB = pB->next;
        }

        return nullptr; // No intersection
    }
};

// METHOD - 2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr; // If either list is empty, no intersection

        ListNode *pA = headA;
        ListNode *pB = headB;

        // Traverse both lists
        while (pA != pB) {
            // Move pA to the head of listB if it reaches the end of listA
            pA = pA ? pA->next : headB;
            // Move pB to the head of listA if it reaches the end of listB
            pB = pB ? pB->next : headA;
        }

        // If pA == pB, they have either met at the intersection node or both are nullptr
        return pA;
    }
};