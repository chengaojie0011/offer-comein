# -*- coding:utf-8 -*-

class Solution:
    def FindNumbersWithSum(self, array, tsum):
        # write code here
        res = []
        length = len(array)
        if length <=1:
            return res
        f = 0
        s = length-1
        while f<s:
            temp = array[f] +array[s]
            if temp==tsum:
                res.append(array[f])
                res.append(array[s])
                return res
            elif temp>tsum:
                s -=1
            else:
                f +=1
        return res



if __name__ == '__main__':
    l = [1,2,4,7,11,15]
    k = 15
    # print(len(l))
    solution1 = Solution()
    a = solution1.FindNumbersWithSum(l,k)
    print(a)