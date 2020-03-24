# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1Between1AndN_Solution(self, n):
        # write code here
        if n<=0:
            return 0
        num = 0
        i = 1
        while i<=n:
            div = i*10
            k = n%div
            if k> i*2-1:
                c = i
            elif k<i:
                c = 0
            else:
                c = k-i+1
            num += (n//div)*i+c
            i = i*10
        return  num

if __name__ == '__main__':
    # l = range(1,12)
    # print(l)
    l = 12
    solution1 = Solution()
    a = solution1.NumberOf1Between1AndN_Solution(l)
    print(a)