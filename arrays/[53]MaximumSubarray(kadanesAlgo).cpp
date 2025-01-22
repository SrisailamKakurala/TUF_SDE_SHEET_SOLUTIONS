class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // if only one element
        if(nums.size()==1) return nums[0];

        // if all elements are negative
        bool allNegative = std::all_of(nums.begin(), nums.end(), [](int x) { return x < 0; });
        if(allNegative) {
            auto max = std::max_element(nums.begin(), nums.end());
            cout<<*max;
            return *max;
        } 

        // -ve's and +ve's
        int ans = 0, sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i]; // cummulative sum
            if(sum < 0) { // restart the sum from 0 if < 0
                sum = 0;
            }else{
                ans = max(ans, sum); // compare and update if not < 0
            }
        }
        return ans;
    }
};