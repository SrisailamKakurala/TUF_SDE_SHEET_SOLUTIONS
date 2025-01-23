#include<bits/stdc++.h>
class Solution {
public:
    void transpose(vector<vector<int>>& m) {
        int n = m.size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(i != j) {
                    swap(m[i][j], m[j][i]);
                }
            }
        }
    }

    void help(vector<vector<int>>& m, int i, int j) {
        for(int k=0; k<m.size(); k++) {
            // cout<<m[k][i]<<"-"<<m[k][j]<<"\n";
            swap(m[k][i], m[k][j]);
        }
    }

    void swapCols(vector<vector<int>>& m) {
        int i=0, j=m[0].size()-1;
        // cout<<i<<j;
        while(i<j) {
            help(m, i, j);
            i++; j--;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        swapCols(matrix);
    }
};