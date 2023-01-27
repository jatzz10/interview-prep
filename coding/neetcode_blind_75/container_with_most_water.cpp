// Problem - https://leetcode.com/problems/container-with-most-water

// Solutions

// Approach 1
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;

        for (int i = 0; i < height.size()-1; i++) {
            for (int j = i+1; j < height.size(); j++) {
                int area = (j-i)*min(height[i], height[j]);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }

        return maxArea;
    }
};
// Time complexity - O(n^2) [where 'n' is size of vector]
// Space complexity - O(n)
// Auxiliary space - O(1)

// Getting Time Limit Exceeded error - Will need to optimise


// Approach 2
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, left = 0, right = height.size()-1;

        while (left < right) {
            int waterArea = (right - left) * min(height[left], height[right]);

            if (waterArea > maxArea) {
                maxArea = waterArea;
            }

            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return maxArea;
    }
};
// Time complexity - O(n) [where 'n' is size of vector]
// Space complexity - O(n)
// Auxiliary space - O(1)