/*
    Problem Statement:
    There is a array of size N having both positive as well as negative elements.
    You have to find maximum sum of contiguous array elements.

    Example: A = [-1, 5, 2, -2, 6]
    Max sum will be = 5 + 2 + (-2) + 6 = 11
*/

// Solutions -

// 1. Brute force
class Solution {
    public:
    
    int returnMaxSum(int arr[], int N) {
        int maxSum = arr[0];

        for (int i = 0; i < N; i++) {
            int tempSum = 0;
            for (int j = i; j < N; j++) {
                tempSum += arr[j];

                if (tempSum > maxSum) {
                    maxSum = tempSum;
                }
            }
        }

        return maxSum;
    }
};
// Time Complexity - O(N^2)
// Space Complexity - O(N)
// Auxiliary space - O(1)


// 2. More optimized approach
class Solution {
    public:

    int returnMaxSum(int arr[], int N) {
        int tempSum = 0, maxSum = arr[0];

        for (int i = 0; i < N; i++) {
            tempSum += arr[i];

            if (arr[i] > tempSum) {
                tempSum = arr[i];
            }

            if (tempSum > maxSum) {
                maxSum = tempSum;
            }
        }

        return maxSum;
    }
}
// Time Complexity - O(N)
// Space Complexity - O(N)
// Auxiliary space - O(1)