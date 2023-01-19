// Problem - https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

// Solutions

// 1. Append to another array backwards
class Solutions {
    public:

    vector reversedArray(int arr[], int n) {
        vector<int> newArr;
        for (int i = 0; i < n; i++) {
            newArr.push_back(arr[n-i]);
        }
        return newArr;
    }
};
// Time complexity - O(n)
// Space complexity - O(n)
// Auxiliary space - O(n)
