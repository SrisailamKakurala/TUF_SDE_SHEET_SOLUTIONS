class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> m(numRows);  // Change vector<vector> to vector<vector<int>>
        m[0] = {1};  // Initialize first row
        
        if (numRows > 1) {
            m[1] = {1, 1};  // Initialize second row
        }
        
        for(int i = 2; i < numRows; i++) {
            m[i].resize(i + 1);  // Resize the current row before accessing
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    m[i][j] = 1;
                } else {
                    m[i][j] = m[i-1][j-1] + m[i-1][j];
                }
            }
        }
        
        return m;
    }
};