// Leetcode problem link -> https://leetcode.com/problems/two-sum/

// Solutions -

// 1. brute force - 
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> op;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0, j < nums.size(): j++)
                if (i != j && (nums[i]+nums[j]) == target) {
                    op.clear();
                    op.push_back(visited[i]);
                    op.push_back(j);
                    break;
                }
            }
            if (!op.empty()) {
                break;
            }
        }
        return op;
    }
};
// Time complexity - O(n^2)
// Space complexity - O(n)


// 2. two pointers -
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> op;
        int left = 0, right = nums.size()-1;
        sort(nums.begin(), nums.end());
        while (i < j) {
            if (nums[left]+nums[right] == target) {
                op.clear();
                op.push_back(visited[target-nums[i]]);
                op.push_back(i);
                break;
            }
            else if (nums[left]+nums[right] < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return op;
    }
};
// Time complexity - O(nlog(n))
// Space complexity - O(n)


// 3. hashmap -
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> op;
        map<int, int> visited;
        for (int i = 0; i < nums.size(); i++) {
            if (visited.find(target-nums[i]) != visited.end()) {
                op.clear();
                op.push_back(visited[target-nums[i]]);
                op.push_back(i);
                break;
            }
            visited[nums[i]] = i;
        }
        return op;
    }
};
// Time complexity - O(n)
// Space complexity - O(n)
// Best approach