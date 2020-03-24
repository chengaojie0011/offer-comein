# -*- coding:utf-8 -*-
class Solution:
    def jumpFloorII(self, number):
        # write code here
        if number<=0:
            return 0
        return 1<< (number-1)


if __name__ == "__main__":
    solution = Solution()
    b = solution.jumpFloorII(10)
    print(b)