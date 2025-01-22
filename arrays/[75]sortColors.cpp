// Problem: Sort Colors

// APPROACH 1: Counting
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==0) zeros++;
            if(nums[i]==1) ones++;
            if(nums[i]==2) twos++;
        }

        for(int i=0; i<zeros; i++) {
            nums[i] = 0;
        }
        for(int i=zeros; i<zeros+ones; i++){
            nums[i] = 1;
        }
        for(int i=zeros+ones; i<zeros+ones+twos; i++){
            nums[i] = 2;
        }
    }
};


// APPROACH 2: Dutch National Flag Algorithm
void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]); // Place 0 at the correct position
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++; // Leave 1 in place
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]); // Place 2 at the correct position
                high--;
            }
        }
}
