#include <bits/stdc++.h>
using namespace std;


vector<int> insertInSortedList(vector<int> nums, int ele) {
    vector<int> newVector;
    bool newElementInserted = false;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > ele && newElementInserted == false) {
            newVector.push_back(ele);
            newElementInserted = true;
        }
        newVector.push_back(nums[i]);
    }
    
    if (newElementInserted == false) {
        newVector.push_back(ele);
    }
    
    return newVector;
}


vector<int> sortYolo(vector<int> nums) {
    if (nums.size() == 1) {
        return nums;
    }
    vector<int> subVector(nums.begin(), nums.end()-1);
    vector<int> sortedVector = sortYolo(subVector);
    vector<int> finalVector = insertInSortedList(sortedVector, nums[nums.size()-1]);
    return finalVector;
}


int main() {
    vector<int> nums{4, 2, 7, 8, 5, 3};
    nums = sortYolo(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}

// Time Complexity = O(N^2)
// Space Complexity = O(N)

