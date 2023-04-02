// Leetcode problem link - https://leetcode.com/problems/number-of-islands

// Solutions -

// 1. BFS
// (similar logic as flood_fill.cpp problem)

// 2. DFS
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        if (i > 0 && grid[i-1][j] == '1')
            dfs(grid, i-1, j);
        if (j > 0 && grid[i][j-1] == '1')
            dfs(grid, i, j-1);
        if (i < grid.size()-1 && grid[i+1][j] == '1')
            dfs(grid, i+1, j);
        if (j < grid[0].size()-1 && grid[i][j+1] == '1')
            dfs(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
// Time Complexity - O(m*n)
// Space Complexity - O(m*n)
// Auxiliary space - O(m*n)
// Auxiliary space is due to "size of the implicit call stack"


// Solution in Python
class Solution:
    def dfs(self, grid, i, j):
        grid[i][j] = '0'

        if (j+1 < len(grid[0]) and grid[i][j+1] == '1'):
            self.dfs(grid, i, j+1)
        if (i+1 < len(grid) and grid[i+1][j] == '1'):
            self.dfs(grid, i+1, j)
        if (j-1 >= 0 and grid[i][j-1] == '1'):
            self.dfs(grid, i, j-1)
        if (i-1 >= 0 and grid[i-1][j] == '1'):
            self.dfs(grid, i, j+1)

    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    self.dfs(grid, i, j)
                    count += 1

        return count
// Time Complexity - O(m*n)
// Space Complexity - O(m*n)
// Auxiliary space - O(m*n)
// Auxiliary space is due to "size of the implicit call stack"