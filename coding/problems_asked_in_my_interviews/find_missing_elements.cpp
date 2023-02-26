// Given an array of integers of size n containing integers lying between [1..n]. 
// Return an array of all the integers in the range [1, n] that do not appear in nums.

// Example -
// input = [1,2,4,4,5,6,6,7]
// output = [3,8]

// input = [4,3,1,7,8,1,3,1]
// output = [2,5,6]


// Approach 1
vector<int> returnMissingElements(vector<int> arr, int n) {
    vector<int> result;
    counter = 1;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != counter) {
            result.push_back(counter);
        }
        counter++;
    }

    return result;
}
// Time Complexity - O(nlogn)
// Space Complexity - O(n)
// Auxiliary space - O(1)


// Approach 2
vector<int> returnMissingElements(vector<int> arr, int n) {
  map<int, bool> visited;
  vector<int> result;
  
  for (int i = 0; i < arr.size(); i++) {
    visited[arr[i]] = true;
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      result.push_back(i);
    }
  }

  return result;
}
// Time Complexity - O(n)
// Space Complexity - O(n)
// Auxiliary space - O(n)

