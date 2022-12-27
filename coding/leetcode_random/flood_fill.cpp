// Leetcode problem link - https://leetcode.com/problems/flood-fill/

// Solutions -

// 1. DFS
class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int color, int newColor) {
        if (image[x][y] == color) {
            image[x][y] = newColor;

            if (x > 0 && image[x-1][y] == color) 
                dfs(image, x-1, y, color, newColor);
            if (y > 0 && image[x][y-1] == color)
                dfs(image, x, y-1, color, newColor);
            if (x < image.size()-1 && image[x+1][y] == color)
                dfs(image, x+1, y, color, newColor);
            if (y < image[0].size()-1 && image[x][y+1] == color)
                dfs(image, x, y+1, color, newColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor)
            dfs(image, sr, sc, color, newColor);
        return image;
    }
};
// Time Complexity - O(N)
// Space Complexity - O(N)
// Auxiliary space - O(N)
// Auxiliary space is due to "size of the implicit call stack"