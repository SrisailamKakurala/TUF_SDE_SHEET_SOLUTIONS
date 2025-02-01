class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int n = a.size();
        int minfreq = n/3;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++) {
            m[a[i]]++;
        }

        vector<int> ans;
        for(auto it: m) {
            if(it.second > minfreq) 
                ans.push_back(it.first);
        }

        return ans;
    }
};