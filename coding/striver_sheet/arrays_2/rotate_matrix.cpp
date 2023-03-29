// Problem - https://leetcode.com/problems/rotate-image

// Approach 1: Transpose + reverse (twice iteration)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                if (i < j) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size()/2; j++) {
                swap(matrix[i][j], matrix[i][matrix.size()-1-j]);
            }
        }
    }
};
// Time complexity - O(2(n^2)) ~ O(n^2)
// Space comlexity - O(n^2)
// Auxiliary space - O(1)


// Approach 2 - Rotate
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < (n+1)/2; i++) {
            for (int j = 0; j < n/2; j++) {
                int temp = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};
// Time complexity - O(n^2)
// Space comlexity - O(n^2)
// Auxiliary space - O(1)
