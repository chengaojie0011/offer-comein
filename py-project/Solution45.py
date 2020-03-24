# -*- coding:utf-8 -*-
import functools
import sys
class Solution:
    def compare(self, num1, num2):
        x1 = str(num1)+str(num2)
        x2 = str(num2) + str(num1)
        if x1>x2:
            return 1
        elif x1<x2:
            return -1
        else:
            return 0

    def PrintMinNumber(self, numbers):
        # write code here
        if numbers == None or len(numbers)==0:
            return  ""
        # sort_l = sorted(numbers,cmp = self.compare)
        #python3
        if sys.version_info[0] == 3:
            sort_l = sorted(numbers, key = functools.cmp_to_key(self.compare))
        else:
            sort_l = sorted(numbers, cmp=self.compare)
        output =''
        for i in sort_l:
            output += str(i)
        return int(output)



if __name__ == '__main__':
    l = [3,32,321]
    solution1 = Solution()
    a = solution1.PrintMinNumber(l)
    print(a)