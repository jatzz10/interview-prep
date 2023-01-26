// Problem - https://leetcode.com/problems/valid-sudoku

// Solutions

// Approach 1
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, map<int, map<char, int>>> subGrid;
        
        // scan rows for repetition
        for (int i = 0; i < board.size(); i++) {
            map<char, int> rowMap;
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') continue;
                
                // rows check
                rowMap[board[i][j]]++;
                if (rowMap[board[i][j]] > 1) return false;

                // subgrid check
                int x = i/3, y = j/3;
                subGrid[x][y][board[i][j]]++;
                if (subGrid[x][y][board[i][j]] > 1) return false;
            }
        }

        // scan columns for repitition
        for (int i = 0; i < board.size(); i++) {
            map<char, int> columnMap;
            for (int j = 0; j < board.size(); j++) {
                if (board[j][i] == '.') continue;
                columnMap[board[j][i]]++;
                if (columnMap[board[j][i]] > 1) return false;
            }
        }

        return true;
    }
};
// Time complexity - O(n^2) [where 'n' is size of matrix board]
// Space complexity - O(n^2)
// Auxiliary space - O(1)


// Approach 2: Check how bitmasks can help here