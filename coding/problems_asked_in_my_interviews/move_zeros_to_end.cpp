Move all zeroes to end of array
===============================

Given an array of random numbers, Push all the zero’s of a given array to the end of the array.
Expected time complexity is O(n) and extra space is O(1).

Input :  arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0};

Input : arr[]  = {1, 2, 0, 0, 0, 3, 6};
Output : arr[] = {1, 2, 3, 6, 0, 0, 0};

// sno -ve number in array
// must maintain the order of non-zero elements

// Solution
void moveZerosToEnd(vector<int>& arr) {
  int slow = 0, fast = 0;
  
  while (fast < arr.size()) {
    if (arr[slow] == 0) {
      swap(arr[slow], arr[fast]);
    } else {
      slow++;
    }
    fast++;
  }

}