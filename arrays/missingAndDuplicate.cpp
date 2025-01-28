class Solution {
public:
    vector<int> repeatedNumber(const vector<int> &A) {
        int n = A.size();
        vector<int> result(2); // To store the duplicate and missing numbers
        
        // Step 1: Find the duplicate number using the marking technique
        int duplicate = -1;
        vector<int> nums = A; // Copy input array to avoid modifying the original
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;  // Convert to zero-based index
            if (nums[index] < 0) {
                duplicate = abs(nums[i]);  // Found the duplicate
                break;
            }
            nums[index] = -nums[index]; // Mark the index as visited
        }

        // Step 2: Calculate expected sum and actual sum
        long long expectedSum = (long long)n * (n + 1) / 2;
        long long actualSum = 0;
        for (int i = 0; i < n; i++) {
            actualSum += A[i];
        }

        // Step 3: Find the missing number
        long long diff = abs(expectedSum - actualSum);
        int missing = duplicate + diff;

        // Step 4: Return the result
        result[0] = duplicate;
        result[1] = missing;
        return result;
    }
};
