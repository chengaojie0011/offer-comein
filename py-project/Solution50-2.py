# -*- coding:utf-8 -*-
import functools
import sys

class Solution:
    # 返回对应char
    def __init__(self):
        self.d={}
        self.s= ""

    def FirstAppearingOnce(self):
        # write code here
        for i in self.s:
            if self.d[i]==1:
                return i
        return '#'

    def Insert(self, char):
        # write code here
        self.s = self.s + char
        self.d[char] = self.d.get(char, 0) + 1



if __name__ == '__main__':
    l = "abaccdeff"
    # print(len(l))
    solution1 = Solution()
    # solution1.s = l
    solution1.Insert('a')
    solution1.Insert('b')
    solution1.Insert('a')
    solution1.Insert('c')
    solution1.Insert('c')
    solution1.Insert('d')
    print(solution1.s)
    a = solution1.FirstAppearingOnce()
    print(a)