# Problem - https://practice.geeksforgeeks.org/problems/subset-sums2234/1

# Approach 1 - Recursive
class Solution:
	def findSubsetSums(self, arr, l, r, sum, result):
	    if l == r:
	        result.append(sum)
	        return
	        
	    self.findSubsetSums(arr, l + 1, r, sum + arr[l], result)
	    self.findSubsetSums(arr, l + 1, r, sum, result)
	
	def subsetSums(self, arr, N):
	    result = []
	    self.findSubsetSums(arr, 0, N, 0, result)
	    return result
# Time complexity - O(2^n)
# Space comlexity - O(n)
# Auxiliary space - O(n)