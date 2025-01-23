
// METHOD - 1
class Solution {
public:
    void fillZeroes(vector<vector<int>> &mat, int row, int col) {
        int n = mat.size(), m = mat[0].size();

        // left side
        for(int i=col; i>=0; i--) {
            if(mat[row][i] != 0) 
                mat[row][i] = 999; // 999 or something that isn't 0
        }

        // right side
        for(int i=col; i<m; i++) {
            if(mat[row][i] != 0)
                mat[row][i] = 999;
        }

        // bottom side
        for(int i=row; i<n; i++) {
            if(mat[i][col] != 0)
                mat[i][col] = 999;
        }

        // top side
        for(int i=row; i>=0; i--) {
            if(mat[i][col] != 0)
                mat[i][col] = 999;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
       for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            if(matrix[i][j] == 0){
                fillZeroes(matrix, i, j);
            }
        }
       } // marks all cols and rows with zero with 999 or any non zero int

       // now replace all 999's with zeros to solve the problem
       for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            if(matrix[i][j] == 999){
                matrix[i][j] = 0;
            }
        }
       }
    }
};


// METHOD - 2
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        bool firstRowZero = false, firstColZero = false;

        // Check if the first row needs to be zeroed
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if the first column needs to be zeroed
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Mark rows and columns to be zeroed using the first row and column
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark row
                    matrix[0][j] = 0; // Mark column
                }
            }
        }

        // Zero out cells based on markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out the first row if needed
        if (firstRowZero) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Zero out the first column if needed
        if (firstColZero) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
