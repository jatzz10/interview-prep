// Leetcode problem - 

class Solution {
public:

    vector<vector<int>> allSubsets;

    void listAllSubsets(vector<int> inputNums, vector<int> outputNums) {
        if (inputNums.size() == 0) {
            allSubsets.push_back(outputNums);
            return;
        }

        int firstNum = inputNums[0];
        inputNums.erase(inputNums.begin());
        
        listAllSubsets(inputNums, outputNums);

        outputNums.push_back(firstNum);
        listAllSubsets(inputNums, outputNums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        listAllSubsets(nums, vector<int> {});
        return allSubsets;
    }
};

// Time Complexity = O(2^N)
// Space Complexity = O(2^N)
