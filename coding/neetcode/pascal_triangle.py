# Problem - https://leetcode.com/problems/pascals-triangle

# Solutions

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascal_list = [[1]]

        for _ in range(numRows-1):
            li = [1]
            for j in range(len(pascal_list[-1])-1):
                li.append(pascal_list[-1][j] + pascal_list[-1][j+1])
            li.append(1)
            pascal_list.append(li)

        return pascal_list
