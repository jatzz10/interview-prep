#include <bits/stdc++.h>
using namespace std;


vector<int> insertInSortedList(vector<int> nums, int ele) {
    // Base condition
    if (nums.size() == 0 || nums.back() <= ele) {
        nums.push_back(ele);
        return nums;
    }
    
    // Hypothesis
    int lastElement = nums.back();
    nums.pop_back();
    nums = insertInSortedList(nums, ele);
    
    // Induction
    nums.push_back(lastElement);

    return nums;
}

vector<int> sortYolo(vector<int> nums) {
    // Base condition
    if (nums.size() == 1) {
        return nums;
    }
    
    // Hypothesis
    int lastElement = nums.back();
    nums.pop_back();
    nums = sortYolo(nums);
    
    // Induction
    nums = insertInSortedList(nums, lastElement);
    
    return nums;
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
