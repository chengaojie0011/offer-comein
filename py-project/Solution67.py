# -*- coding:utf-8 -*-

g_status = 1

class Solution:
    def StrToInt(self, s):
        # write code here
        l = len(s)
        if l<1 or not s:
            g_status = 0
            return 0
        w = 1
        n = 0
        if s[0] == '+' or s[0] =='-':
            if s[0] == '-': w = -1
            start = 1
        else:
            start = 0
        res = 0
        for i in range(start,l):
            if s[i]>'9' or s[i]<'0':
                g_status = 0
                return 0
            res = res*10 + ord(s[i]) - ord('0')
        res = res*w
        if res <= pow(2,31)-1 and res >= -1*pow(2,31):
            return res
        else:
            g_status = 0
            return 0



if __name__ == '__main__':
    solution = Solution()
    # a = "+2147483647"
    a = '-2147483648'
    b = solution.StrToInt(a)
    print(b)