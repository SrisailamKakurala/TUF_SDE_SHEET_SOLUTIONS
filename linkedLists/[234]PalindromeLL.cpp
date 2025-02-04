// METHOD - 1

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;

        ListNode* temp = head;

        string s = "";
        while(temp) {
            s += to_string(temp->val);
            temp = temp->next;
        }
        
        string m = s;
        reverse(m.begin(), m.end());
        return s == m;
    }
};

// METHOD - 2

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        while(head) {
            values.push_back(head->val);
            head = head->next;
        }
        
        for(int i = 0, j = values.size() - 1; i < j; i++, j--) {
            if(values[i] != values[j]) return false;
        }
        
        return true;
    }
};


// METHOD - 3

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        
        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse second half
        ListNode* secondHalf = reverseList(slow->next);
        ListNode* firstHalf = head;
        
        // Compare
        while(secondHalf) {
            if(firstHalf->val != secondHalf->val) return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        
        return prev;
    }
};