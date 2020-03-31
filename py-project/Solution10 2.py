# -*- coding:utf-8 -*-
class Solution10_1:
    def Fibonacci(self, n):
        # write code here
        if n <= 0:
            return 0
        if n == 1:
            return 1
        return  self.Fibonacci(n-1) + self.Fibonacci(n-2)

class Solution10_2:
    def Fibonacci(self, n):
        # write code here
        if n <= 0:
            return 0
        if n == 1:
            return 1
        else:
            res1 = 0
            res2 = 1
            for i in range(2,n+1):
                res = res1 + res2
                res1 = res2
                res2 = res
            return  res

if __name__ == "__main__":
    solution1 = Solution10_1()
    a = solution1.Fibonacci(10)
    solution2 = Solution10_2()
    b = solution2.Fibonacci(10)
    print(list(range(1,2)))
    print(a)
    print(b)
