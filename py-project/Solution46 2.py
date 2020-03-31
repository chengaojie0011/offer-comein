# -*- coding:utf-8 -*-
import functools
import sys

class Solution:
    # def GetTranslationCountDetail(self, numbers):
    #     return 0

    def GetTranslationCount(self, numbers):
        num_str = str(numbers)
        count_all = 0
        length = len(num_str)
        counts = [1 for i in range(length)]
        i = length-1
        while i>=0:

            if i ==length-1:
                count =1
            else:
                count = counts[i+1]
            if i<length-1:
                number1 = int(num_str[i])
                number2 = int(num_str[i+1])
                num = number1*10+number2
                if num>=0 and num<=25:
                    if i<length-2:
                        count = count+counts[i+2]
                    else:
                        count +=1
            counts[i] = count
            i = i-1
        count_all = counts[0]
        return  count_all

if __name__ == '__main__':
    l = 12258
    solution1 = Solution()
    a = solution1.GetTranslationCount(l)
    print(a)