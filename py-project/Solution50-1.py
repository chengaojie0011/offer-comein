# -*- coding:utf-8 -*-
import functools
import sys

# 用字典实现
class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        if s == None:
            return -1
        d = dict()
        # d = {}
        for i in s:
            d[i] =d.get(i,0)+1
        for i in s:
            if d[i] == 1:
                return s.index(i)
        return -1

 #用list实现哈希表
class Solution:
    def FirstNotRepeatingChar(self, s):
        # write code here
        if s == None:
            return -1
        hash = [0]*256
        # d = {}
        for i in s:
            hash[ord(i)] +=1
        for i in s:
            if hash[ord(i)]== 1:
                return s.index(i)
        return -1

if __name__ == '__main__':
    l = "abaccdeff"
    # print(len(l))
    solution1 = Solution()
    a = solution1.FirstNotRepeatingChar(l)
    print(a)