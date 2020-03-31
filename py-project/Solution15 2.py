# -*- coding:utf-8 -*-

"""
n = n & 0xffffffff，在Python中，数的大小是可以无限扩大的，
不会像Java或c++中，数超过32位会溢出，而是继续扩张，所以对于一个负数而言，
进行了这个操作，实际上是提取了负数的后32位（在计算机中以补码形式存在），
前面的任意位呢，则变成了0，比如说 -1，一开始是 111.....(n个1)...11111111，
进行与运算之后，得到，00....(n个0)....111111111（32个1），变成了含32个1的正数，
然后就不用担心负数陷入死循环。
"""
class Solution:
    def NumberOf1(self, n):
        # write code here
        count = 0
        if n < 0:
            n = n & 0xffffffff
        while n:
            n = (n-1)&n
            count += 1
        return count

class Solution2:
    def NumberOf1(self, n):
        # write code here
        count = 0
        flag = 1
        if n < 0:
            n = n & 0xffffffff
        while flag and flag<=pow(2,32):
            if n&flag:
                count+=1
            flag = flag <<1
            # flag *=2
        return count

if __name__ == "__main__":
    solution1 = Solution2()
    a = solution1.NumberOf1(-9)
    print(a)