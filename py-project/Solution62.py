# -*- coding:utf-8 -*-
class Solution:
    def LastRemaining_Solution(self, n, m):
        # write code here
        res = 0
        if n<1 or m<1:
            return -1
        numbers = list(range(n))
        cur = 0
        while len(numbers)>1:
            for i in range(0,m-1):
                cur +=1
                if cur == len(numbers):
                    cur = 0
            numbers.remove(numbers[cur])
            if cur == len(numbers):
                cur = 0
            # print(numbers[cur])
        res = numbers[0]
        return res

class Solution2:
    def LastRemaining_Solution(self, n, m):
        # write code here
        res = 0
        if n<1 or m<1:
            return -1
        last = 0
        for i in range(2, n + 1):
            last = (last + m) % i
        return last

if __name__ == "__main__":
   solution1 = Solution2()
   a = 5
   b = 3
   x = solution1.LastRemaining_Solution(a,b)
   print(x)

   # 0,1,2,3,4

