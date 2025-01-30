# **Boyer-Moore Voting Algorithm - README Notes**  

## **Introduction**  
The **Boyer-Moore Voting Algorithm** is an efficient algorithm used to find the **majority element** in an array. It operates in **O(n) time complexity** and uses **O(1) extra space**, making it one of the best solutions for this problem.  

## **Definition**  
A **majority element** is an element that appears **more than ⌊n/2⌋ times** in an array. If such an element exists, the Boyer-Moore algorithm guarantees finding it.

## **Algorithm Steps**  
1. **Initialize** two variables:
   - `candidate` → Stores the potential majority element.
   - `count` → Tracks the frequency of the candidate.

2. **Iterate through the array**:
   - If `count == 0`, set `candidate = nums[i]`.
   - If `nums[i] == candidate`, increase `count`.
   - Otherwise, decrease `count`.

3. **Return `candidate`** as the majority element.

## **Code Implementation**
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        
        for (int num : nums) {
            if (count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
```

## **Why It Works**  
- When we find a new candidate, we assume it’s the majority.
- If we see the same number again, we increase its count.
- If a different number appears, we decrease the count.
- Since the majority element appears **more than n/2 times**, it will always remain in the lead.

## **Complexity Analysis**  
| Aspect  | Complexity |
|---------|-----------|
| **Time** | O(n) → Single pass through the array |
| **Space** | O(1) → Uses only two variables |

## **Example Walkthrough**  
Given `nums = [3, 3, 4, 2, 3, 3, 2, 3, 3]`, let's apply the algorithm:

| Step | num | candidate | count |
|------|-----|-----------|-------|
| 1    | 3   | 3         | 1     |
| 2    | 3   | 3         | 2     |
| 3    | 4   | 3         | 1     |
| 4    | 2   | 3         | 0     |
| 5    | 3   | 3         | 1     |
| 6    | 3   | 3         | 2     |
| 7    | 2   | 3         | 1     |
| 8    | 3   | 3         | 2     |
| 9    | 3   | 3         | 3     |

Final **majority element = 3** ✅

## **Applications of Boyer-Moore Voting Algorithm**
The algorithm has several practical applications:

### **1. Finding the Majority Element in an Array**  
- Used in competitive programming and interviews to determine the most frequent element appearing more than ⌊n/2⌋ times.

### **2. Election/Voting Systems**  
- Helps determine the most popular candidate in a simple voting system where a majority (more than 50%) is required.

### **3. Data Stream Processing**  
- In large-scale datasets or real-time streaming applications, the algorithm can efficiently track the most occurring element.

### **4. Bioinformatics (DNA Sequence Analysis)**  
- Can help detect dominant patterns in DNA sequences by identifying the most common nucleotide.

### **5. Market Research and Consumer Analytics**  
- Used to find the most popular product, service, or trend based on consumer behavior data.

### **6. Spam Detection and Text Classification**  
- Identifies dominant words in spam emails or reviews to classify content.

## **Key Takeaways**  
✔ **Efficient** → Runs in O(n) time  
✔ **Space-Optimized** → Uses only O(1) extra space  
✔ **Guaranteed to Work** if a majority element exists  

🚀 **Great for solving "Majority Element" problems in coding interviews!**