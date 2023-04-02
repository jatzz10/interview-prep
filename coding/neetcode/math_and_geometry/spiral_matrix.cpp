// Problem - https://leetcode.com/problems/spiral-matrix

// Solution
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool visited[m][n];
        vector<int> result;
        int x = 0, y = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }

        while (1) {
            bool isMovePossible = false;
            
            // move right
            for (int i = y+1; i < n; i++) {
                if (!visited[x][i]) {
                    visited[x][i] = true;
                    y = i;
                    result.push_back(matrix[x][i]);
                    isMovePossible = true;
                } else {
                    break;
                }
            }

            // move down
            for (int i = x+1; i < m; i++) {
                if (!visited[i][y]) {
                    visited[i][y] = true;
                    x = i;
                    result.push_back(matrix[i][y]);
                    isMovePossible = true;
                } else {
                    break;
                }
            }

            // move left
            for (int i = y-1; i >= 0; i--) {
                if (!visited[x][i]) {
                    visited[x][i] = true;
                    y = i;
                    result.push_back(matrix[x][i]);
                    isMovePossible = true;
                } else {
                    break;
                }
            }

            // move up
            for (int i = x-1; i >= 0; i--) {
                if (!visited[i][y]) {
                    visited[i][y] = true;
                    x = i;
                    result.push_back(matrix[i][y]);
                    isMovePossible = true;
                } else {
                    break;
                }
            }

            if (!isMovePossible) {
                break;
            }
        }

        return result;
    }
};
// Time complexity - O(m*n)
// Space complexity - O(m*n)
// Auxiliary space - O(m*n)