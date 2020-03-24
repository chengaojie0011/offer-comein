# -*- coding:utf-8 -*-
class Solution1:
    def Add(self, num1, num2):
        # write code here
        return sum([num1,num2])


class Solution:
    def Add(self, num1, num2):
        # write code here
        while num2!= 0:
            sum =(num1 ^num2)& 0xffffffff
            c = ((num1 &num2)<<1) & 0xffffffff
            num1 = sum
            num2 = c
        if num1 <= 0x7fffffff:
            result = num1
        else:
            result = ~(num1 ^ 0xffffffff)
        return result

if __name__ == '__main__':
    solution = Solution()
    a = solution.Add(3,4)
    print(a)