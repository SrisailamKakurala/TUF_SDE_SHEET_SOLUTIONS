### Floyd's Tortoise and Hare (Cycle Detection) - README Notes

Floyd's Tortoise and Hare algorithm is an efficient technique used for detecting cycles in sequences or linked lists. It operates in **O(n)** time complexity and uses **O(1)** space. Below are the key points to understand the algorithm:

---

### **Concept**
- The algorithm is designed to detect cycles in a sequence by using two pointers:
  - **Tortoise**: Moves one step at a time.
  - **Hare**: Moves two steps at a time.
- If there’s a cycle, the two pointers will eventually meet within the cycle.
- If there’s no cycle, the hare will reach the end of the sequence.

---

### **Steps to Detect a Cycle**
1. **Initialization**:
   - Start with two pointers: `slow` (tortoise) and `fast` (hare), both pointing to the first element of the sequence.
   
2. **Move Pointers**:
   - Move the `slow` pointer by one step and the `fast` pointer by two steps in each iteration.

3. **Cycle Detection**:
   - If `slow` and `fast` meet, a cycle is detected.
   - If `fast` or `fast.next` becomes `null`, no cycle exists.

4. **Finding the Start of the Cycle** (Optional):
   - Reset `slow` to the start of the sequence.
   - Move both `slow` and `fast` one step at a time.
   - The point where they meet is the start of the cycle.

---

### **Use Cases**
1. **Linked Lists**:
   - Detect if a linked list has a cycle and find the cycle's start point.
2. **Duplicate Number in an Array**:
   - Find the duplicate number in an array where:
     - The array represents a sequence of indices.
     - Each element points to the next index (like a linked list).

---

### **Example Code (Finding Duplicate in an Array)**

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        
        // Phase 1: Detect the cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find the starting point of the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow; // The duplicate number
    }
};
```

---

### **Complexity**
- **Time Complexity**: O(n)
  - Both pointers traverse the sequence in linear time.
- **Space Complexity**: O(1)
  - No additional data structures are used.

---

### **Advantages**
- Highly efficient for problems with limited memory constraints.
- Can find cycles and their entry points effectively.

### **Disadvantages**
- Works only for problems where elements form a sequence or chain (like a linked list or index-based cycles).
- Cannot handle sequences without any defined structure.