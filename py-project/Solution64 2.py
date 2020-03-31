# -*- coding:utf-8 -*-
class Solution1:
    def Sum_Solution(self, n):
        # write code here
        return sum(range(1,n+1))

class Solution2:
    def Sum_Solution(self, n):
        # write code here
        # a = n and (n+self.Sum_Solution(n-1))
        return n and ( n+self.Sum_Solution(n-1))

class Solution3:
    def Sum_Solution(self, n):
        # write code here
        # a = n and (n+self.Sum_Solution(n-1))
        return int((pow(n,2)+n)>>1)

if __name__ == '__main__':
    solution = Solution3()
    a = solution.Sum_Solution(4)
    print(a)