# -*- coding:utf-8 -*-
class Solution1:
    def jumpFloor(self, number):
        # write code here
        if number<=0:
            return 0
        elif number==1:
            return 1
        elif number ==2:
            return 2
        else:
            return self.jumpFloor(number-1)+self.jumpFloor(number-2)

class Solution:
    def jumpFloor(self, number):
        # write code here
        if number<=0:
            return 0
        elif number==1:
            return 1
        elif number ==2:
            return 2
        num1 = 1
        num2 = 2
        sum = 0
        for i in range(3,number+1):
            sum = num1+num2
            num1 = num2
            num2 = sum
        return sum

if __name__ == "__main__":
    solution = Solution()
    b = solution.jumpFloor(10)
    print(b)