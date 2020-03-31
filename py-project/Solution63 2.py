# -*- coding:utf-8 -*-

class Solution:
    def MaxDiff(self,n):
        if len(n)<2 or not n:
            return -1
        min = n[0]
        maxdiff = n[1]-min
        for i in range(2,len(n)):
            if n[i-1]<min:
                min = n[i-1]
            temp = n[i] - min
            if temp > maxdiff:
                maxdiff = temp
        return  maxdiff

if __name__ ==  '__main__':
    solution = Solution()
    a = [9,11,8,5,7,12,16,14]
    n1 = solution.MaxDiff(a)
    print(n1)


