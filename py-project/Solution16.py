# -*- coding:utf-8 -*-
class Solution:
    def Power(self, base, exponent):
        # write code here
        if base == 0:
            return 0
        if exponent == 0:
            return 1
        e = abs(exponent)
        res = 1
        temp = base
        while e>0:
            if e&1==1:
            #为奇数，同时代表最后一位是否为1，为1则需要乘,e.g 1110011
            # 则在1出现的位要乘以对应位数的base
                res =res*temp
            e = e>>1 #右移等效于除2
            temp *=temp
        if exponent<0:
            res = 1/res
        return res

class Solution2:
    def Power(self, base, exponent):
        # write code here
        return base**exponent

if __name__ == "__main__":
    solution1 = Solution()
    a = solution1.Power(10,6)
    print(a)
