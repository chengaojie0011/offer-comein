# -*- coding:utf-8 -*-
class Solution:
    def print1ToMax(self, n):
        # write code here
        if n<0:
            return 0;
        number = ["0" for i in range(n)]
        for i in range(10):
            number[0] = str(i)
            self.getIndex1To9(number,n,0)
        print(number)
        return 0

    def getIndex1To9(self,number,n,index):
        if index ==n-1:
            self.printNumber(number)
            return 0
        for i in range(10):
            number[index+1] = str(i)
            self.getIndex1To9(number,n,index+1)
        return 0

    def printNumber(self,number):
        begin = False
        for i in range(len(number)):
            if begin== False and number[i] != '0':
                begin = True
            if begin:
                print(int(number[i]),end="")
        print('\n')
        return 0


if __name__ == "__main__":
    solution1 = Solution()
    a = solution1.print1ToMax(2)
    # print(a)
