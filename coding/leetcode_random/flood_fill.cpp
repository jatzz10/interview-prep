// Leetcode problem link - https://leetcode.com/problems/flood-fill/

// Solutions -

// 1. BFS
class Solution {
public:
    void bfs(vector<vector<int>>& image, int x, int y, int color, int newColor) {
        queue<vector<int>> q;
        vector<int> pixelIndices{x,y};
        q.push(pixelIndices);

        while (!q.empty()) {
            vector<int> firstElement = q.front();
            int x = firstElement[0], y = firstElement[1];
            image[x][y] = newColor;
            q.pop();

            if (x > 0 && image[x-1][y] == color) {
                vector<int> temp{x-1, y};
                q.push(temp);
            }
            if (y > 0 && image[x][y-1] == color) {
                vector<int> temp{x, y-1};
                q.push(temp);
            }
            if (x < image.size()-1 && image[x+1][y] == color) {
                vector<int> temp{x+1, y};
                q.push(temp);
            }
            if (y < image[0].size()-1 && image[x][y+1] == color) {
                vector<int> temp{x, y+1};
                q.push(temp);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor)
            bfs(image, sr, sc, color, newColor);
        return image;
    }
};
// Time Complexity - O(m*n)
// Space Complexity - O(m*n)
// Auxiliary space - O(m*n)
// Here, auxiliary space is due to "size of the queue"


// 2. DFS
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
// Time Complexity - O(m*n)
// Space Complexity - O(m*n)
// Auxiliary space - O(m*n)
// Auxiliary space is due to "size of the implicit call stack"