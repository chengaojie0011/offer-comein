# -*- coding:utf-8 -*-
import functools
import sys


class Solution:
    def longestSubstringWithoutDuplication(self,str):
        length = len(l)
        maxlength = 0
        curlength = 0
        if str ==None or length<=0:
            return 0
        position = [-1 for i in range(26)]
        for i in range(length):
            preindex = position[ord(str[i])-ord('a')]
            d = i-preindex
            if preindex<0 or d > curlength:
                curlength +=1
            else:
                if curlength > maxlength:
                    maxlength = curlength
                curlength = i-preindex
            position[ord(str[i]) - ord('a')] = i
        if curlength > maxlength:
            maxlength = curlength
        return maxlength

if __name__ == '__main__':
    l = 'arabcacfr'
    print(len(l))
    solution1 = Solution()
    a = solution1.longestSubstringWithoutDuplication(l)
    print(a)