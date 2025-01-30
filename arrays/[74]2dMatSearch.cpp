class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int key) {
        int n = v.size();
        int m = v[0].size();
        int i=0, j=m-1;

        while(i<n && j>=0) {
            if(v[i][j] == key) return true;
            v[i][j] < key ? i++ : j--;
        }

        return false;
    }
};