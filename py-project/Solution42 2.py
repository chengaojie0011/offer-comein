# -*- coding:utf-8 -*-

class Solution:
    def FindGreatestSumOfSubArray(self, array):
        # write code here
        n = len(array)
        dp = [i for i in array]
        for i in range(1, n):
            dp[i] = max(dp[i - 1] + array[i], array[i])

        return max(dp)

if __name__ == '__main__':
    str = "abc"
    # x_list = str.split('')
    # x_list = list(str)
    # print(x_list)
    # x_str = ''.join(x_list)
    # print(x_str)
    l = [1,-2,3,10,-4,7,2,-5]
    solution1 = Solution()
    a = solution1.FindGreatestSumOfSubArray(l)
    print(a)