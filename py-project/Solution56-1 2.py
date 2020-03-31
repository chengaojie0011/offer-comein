# -*- coding:utf-8 -*-
class Solution1:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        if len(array)<2 or array ==None:
            return None
        xor_res = 0
        for i in array:
            xor_res ^= i
        idx = self.FirstOneIndex(xor_res)
        num1 = 0
        num2 = 0
        for i in array:
            if self.IsBitOne(i,idx):
                num1 ^=i
            else:
                num2 ^=i
        return [num1, num2]

    def FirstOneIndex(self, num):
        index = 0
        while num&1 == 0:
            num = num>>1
            index +=1
        return index

    def IsBitOne(self, num,index):
        num = num>>index
        return num&1

class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnce(self, array):
        # write code here
        if len(array)<2 or array ==None:
            return None
        d = dict()
        xor_res = 0
        for i in array:
            d[i] =d.get(i,0)+1
        num = []
        for i in array:
            if d[i] == 1:
                num.append(i)
        return  num

if __name__ == '__main__':
    l = [2,4,3,6,3,2,5,5]
    k = 3
    # print(len(l))
    solution1 = Solution()
    a = solution1.FindNumsAppearOnce(l)
    print(a)