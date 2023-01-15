/*
    Problem Statement-
    Given a sorted rotated array 'arr' of size 'n', find the index of an element 'k' 
    in the array.

    Ex - 
    A = [4, 5, 6, 7, 1, 2, 3]
    k = 5
    Answer - 1 (5 is on 2nd position)
*/

// Solution

// Approach 1 - Brute force
class Solution {
    public:

    int findIndex(int arr[], int n, int k) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == k) {
                return i;
            }
        }
        return -1;
    }
};
// Time Complexity - O(n)
// Space Complexity - O(n)
// Auxiliary space - O(1)


// Approach 2 - Binary Search
class Solution {
    public:

    int findIndex(int arr[], int n, int k) {
        int pivot = 0, elementIndex = 0;
        int l = 0, r = n - 1;

        // find pivot element using binary search
        while (l <= r) {
            int mid = (l+r)/2;
            int leftDiff = abs(arr[mid] - arr[l]);
            int rightDiff = abs(arr[mid] - arr[r]);
            
            if (mid == l || arr[mid] < arr[mid-1]) {
                pivot = mid;
                break;
            } else if (rightDiff > leftDiff) {
                l = mid;
            } else {
                r = mid;
            }
        }

        // re-adjust l and r
        l = 0;
        r = n - 1;
        
        // find the subarray where element k is present
        if (k >= arr[pivot] && k <= arr[r]) {
            l = pivot;
        } else {
            r = pivot - 1;
        }

        // find element in the subarray where element k is present, using binary search
        while (l <= r) {
            int mid = (l+r)/2;

            if (arr[mid] == k) {
                elementIndex = mid;
                break;
            } else if (arr[mid] > k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return elementIndex;
    }
};
// Time Complexity - O(log n)
// Space Complexity - O(n)
// Auxiliary space - O(1)
