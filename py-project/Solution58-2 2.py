# -*- coding:utf-8 -*-
class Solution:
    def LeftRotateString(self, s, n):
        # write code here
        length = len(s)
        if length <=1 or n<=0 or n>=length:
            return s
        l_s = list(s)
        l_s = self.Reverse(l_s, 0, n-1)
        l_s = self.Reverse(l_s, n, length-1)
        l_s = self.Reverse(l_s, 0, length-1)
        return ''.join(l_s)


    def Reverse(self, s , start, end):
        while start<end:
            temp = s[start]
            s[start] = s[end]
            s[end] = temp
            start +=1
            end -=1
        return s

class Solution2:
    def LeftRotateString(self, s, n):
        # write code here
        length = len(s)
        if length <=1 or n<=0 or n>=length:
            return s
        l_s = list(s)
        return ''.join(l_s[n:]+l_s[0:n])


if __name__ == '__main__':
    k =  "abcdefg"
    n = 2
    # x = list(k)
    # print(''.join(x))
    solution1 = Solution()
    a = solution1.LeftRotateString(k,n)
    print(a)