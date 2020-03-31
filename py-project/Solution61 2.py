# -*- coding:utf-8 -*-
class Solution:
    def IsContinuous(self, numbers):
        # write code here
        if not numbers or len(numbers) != 5:
            return 0
        numbers = sorted(numbers,reverse=False)
        # print(numbers)
        num0=0
        for i,v in enumerate(numbers[:-1]):
            if v>13 or v<0: return 0
            if v==0:
                num0+=1
            else:
                temp = numbers[i+1] -v
                if temp == 0:
                    return 0
                num0 = num0 -(temp-1)
                if num0<0: return 0
        return 1

if __name__ == '__main__':
    n = [1,3,2,5,4]
    #1,3,2,5,4
    #1,0,0,5,0
    solution1 = Solution()
    a = solution1.IsContinuous(n)
    print(a)