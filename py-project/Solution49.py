# -*- coding:utf-8 -*-
import functools
import sys


class Solution:
    def GetUglyNumber_Solution(self, index):
        # write code here
        if index<7:
            return index
        res = [-1 for i in range(index)]
        res[0] = 1
        t2=0
        t3=0
        t5=0
        for i in range(1,index):
            res[i] = min(res[t2]*2,min(res[t3]*3,res[t5]*5))
            if res[i]==res[t2]*2:
                t2 +=1
            if res[i]==res[t3]*3:
                t3 +=1
            if res[i]==res[t5]*5:
                t5 +=1
        return res[-1]

if __name__ == '__main__':
    l = 1500
    # print(len(l))
    solution1 = Solution()
    a = solution1.GetUglyNumber_Solution(l)
    print(a)