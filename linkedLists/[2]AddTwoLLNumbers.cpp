// METHOD -1 
// Possible issue: 
// The error std::out_of_range in your code occurs because the 
// stoi function is being called on strings that are too large to be converted to integers. 
// This happens when the linked lists represent very large numbers that exceed the range of int or even long long.
#include<string>
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        string s1, s2;
        
        // Convert the first list to string
        while(temp1 != nullptr) {
            s1 = s1 + to_string(temp1->val);
            temp1 = temp1->next;
        }
        
        // Convert the second list to string
        while(temp2 != nullptr) {
            s2 = s2 + to_string(temp2->val);
            temp2 = temp2->next;
        }

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        
        // Sum the two numbers
        int num = stoi(s1) + stoi(s2);
        
        // Create the result list in reverse order
        ListNode* result = nullptr;
        while (num > 0) {
            int digit = num % 10;
            ListNode* newNode = new ListNode(digit);
            newNode->next = result;
            result = newNode;
            num /= 10;
        }

        // If the sum is zero, create a node with value 0
        if (result == nullptr) {
            result = new ListNode(0);
        }

        // Reverse the result list to get the correct order
        return reverseList(result);
    }
};


// METHOD -2
// Time Complexity: O(max(m, n)), where m and n are the lengths of the two linked lists.
// Space Complexity: O(max(m, n))
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy head node to simplify the code.
        // This dummy node helps avoid edge cases (e.g., empty result list).
        ListNode* dummyHead = new ListNode(0);
        
        // `curr` is a pointer to the current node in the result list.
        ListNode* curr = dummyHead;
        
        // `carry` stores the carry-over value when the sum of two digits is >= 10.
        int carry = 0;

        // Traverse both linked lists and add the digits.
        // The loop continues until:
        // 1. Both lists are fully traversed.
        // 2. There is no carry left to add.
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Start with the carry value from the previous iteration.
            int sum = carry;

            // If `l1` is not null, add its value to `sum` and move to the next node.
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            // If `l2` is not null, add its value to `sum` and move to the next node.
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Calculate the new carry value.
            // If `sum` is >= 10, carry will be 1; otherwise, it will be 0.
            carry = sum / 10;

            // Create a new node with the digit value (sum % 10) and add it to the result list.
            curr->next = new ListNode(sum % 10);

            // Move the `curr` pointer to the newly added node.
            curr = curr->next;
        }

        // Return the result list, starting from the node after the dummy head.
        return dummyHead->next;
    }
};