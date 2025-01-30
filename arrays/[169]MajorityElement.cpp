// Optimized Approach: Boyer-Moore Voting Algorithm
// If you're solving Leetcode’s "Majority Element" problem, there's a faster approach with O(n) time and O(1) space:
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


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m; // Key: Number, Value: Frequency

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        int majority = nums[0]; // Assume first number is majority
        int maxCount = 0;

        for (auto it : m) {
            if (it.second > maxCount) { // Find max frequency
                maxCount = it.second;
                majority = it.first;
            }
        }

        return majority;
    }
};