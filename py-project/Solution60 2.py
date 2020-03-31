# -*- coding:utf-8 -*-
class Solution:
    def FindSum(self, num):
        # write code here
        p = []
        if num<1:
            return p
        arr = [[0 for i in range(6*num+1)] for j in range(num+1)]
        # arr[1] = [1 for i in range(1,6*num+1)]
        for i in range(1,6+1):
            arr[1][i] = 1
        print(arr)
        for i in range(2,num+1):
            for j in range(i,6*i+1):
                arr[i][j] =  arr[i - 1][j - 1] + arr[i - 1][j - 2] + arr[i - 1][j - 3]+\
                             arr[i - 1][j - 4] + arr[i - 1][j - 5] + arr[i - 1][j - 6]
        print(arr)
        total = pow(6, num)
        p = [arr[n][i]/total for i in range(n,n*6+1)]
        return p


if __name__ == '__main__':
    n = 2
    solution1 = Solution()
    a = solution1.FindSum(n)
    print(a)