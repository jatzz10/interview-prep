// Problem - https://leetcode.com/problems/set-matrix-zeroes/

// Approach 1 - Brute force
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, bool> row;
        unordered_map<int, bool> col;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
// Time complexity - O(m*n)
// Space comlexity - O(m*n)
// Auxiliary space - O(m_n)