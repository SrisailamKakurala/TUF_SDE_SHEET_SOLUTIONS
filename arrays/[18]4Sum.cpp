class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        int n = v.size();
        set<vector<int>> s;
        vector<vector<int>> ans;
        sort(v.begin(), v.end());

        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && v[i] == v[i - 1]) continue;  // Avoid duplicates
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && v[j] == v[j - 1]) continue;  // Avoid duplicates
                int l = j + 1, r = n - 1;
                while(l < r) {
                    // Use long long for sum to avoid overflow
                    long long sum = (long long)v[i] + v[j] + v[l] + v[r];
                    if(sum == target) {
                        s.insert({v[i], v[j], v[l], v[r]});
                        l++; r--;
                    } else if(sum > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }

        // Convert set to vector
        ans.assign(s.begin(), s.end());

        return ans;
    }
};
