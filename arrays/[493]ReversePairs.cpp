// TLE
class Solution {
public:
    int reversePairs(vector<int>& a) {
        int count = 0;
        for(int i=0; i<a.size()-1; i++) {
            for(int j=i+1; j<a.size(); j++) {
                if(i<j && a[i]>2*a[j]){
                    count++;
                    cout<<i<<"-"<<j<<endl;
                }
            } 
        }
        return count;
    }
};

// Method - 2 (merge sort)
class Solution {
public:
    // Function to count reverse pairs during the merge step
    int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        
        // Count reverse pairs: nums[i] > 2 * nums[j]
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) {  // Use 2LL to cast to long long
                j++;
            }
            count += (j - (mid + 1)); // Count how many j's satisfy the condition
        }

        // Merge the two sorted halves
        vector<int> temp;
        int i = left, j2 = mid + 1;
        while (i <= mid && j2 <= right) {
            if (nums[i] <= nums[j2]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j2++]);
            }
        }

        // Add the remaining elements
        while (i <= mid) temp.push_back(nums[i++]);
        while (j2 <= right) temp.push_back(nums[j2++]);

        // Copy the sorted subarray back to the original array
        for (int i = left; i <= right; i++) {
            nums[i] = temp[i - left];
        }

        return count;
    }

    // Merge sort function that also counts reverse pairs
    int mergeSortAndCount(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        int count = mergeSortAndCount(nums, left, mid) + mergeSortAndCount(nums, mid + 1, right);
        
        count += mergeAndCount(nums, left, mid, right);
        
        return count;
    }

    // Main function that calls mergeSortAndCount
    int reversePairs(vector<int>& nums) {
        return mergeSortAndCount(nums, 0, nums.size() - 1);
    }
};

