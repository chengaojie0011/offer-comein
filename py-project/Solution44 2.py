# -*- coding:utf-8 -*-
import math
## 注意，从0开始计数，所以多一位，要后移
class Solution:
    def countOfInt(self, n):
        if n == 1:
            return 10
        return int(9*math.pow(10, n-1))

    def inIndex(self, idx, n):
        n_first = math.pow(10, n-1) if n>1 else 0
        number = n_first + idx//n
        indexfornum = int(n- idx%n-1)
        for i in range(0,indexfornum):
            number /= 10
        return number%10

    def digitAtIndex(self, index):
        if index<0:
            return -1
        digit = 1
        while True:
            numbers =  self.countOfInt(digit)
            if index < numbers*digit:
                return self.inIndex(index,digit)
            index -= numbers*digit
            digit +=1


if __name__ == '__main__':
    l = 1001
    solution1 = Solution()
    a = solution1.digitAtIndex(l)
    print(a)