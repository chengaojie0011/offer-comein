# -*- coding:utf-8 -*-
import functools
import sys

class Solution:
    def getMaxValueofMatrix(self,matrix):
        max_value = 0
        rows = len(matrix)
        cols = len(matrix[0])
        if matrix ==None or rows<=0 or cols<= 0:
            return 0
        max_values_cols = [1 for i in range(cols)]
        max_values  = [max_values_cols for i in range(rows)]
        print(max_values)
        for i in range(rows):
            for j in range(cols):
                up = 0
                left = 0
                if i>0:
                    up = max_values[i-1][j]
                if j > 0:
                    left = max_values[i][j-1]
                max_values[i][j] = max(up,left)+matrix[i][j]
        max_value = max_values[rows-1][cols-1]
        return max_value

if __name__ == '__main__':
    l = [[1,10,3,8],[12,2,9,6],[5,7,4,11],[3,7,16,5]]
    print(len(l))
    solution1 = Solution()
    a = solution1.getMaxValueofMatrix(l)
    print(a)