# -*- coding:utf-8 -*-
class Solution:
    def multiply(self, A):
        # write code here
        l = len(A)
        res = [1 for i in range(l)]
        for i in range(1,l):
            res[i] = res[i-1]*A[i-1]
        temp = 1
        for i in range(l-2,-1,-1):
            temp = temp*A[i+1]
            res[i] *= temp
        return res


if __name__ == '__main__':
    solution = Solution()
    a = [1,2,3,4,5]
    # 120, 60, 40, 30, 24
    b = solution.multiply(a)
    print(b)