# -*- coding:utf-8 -*-

class Solution:
    # 返回[a,b] 其中ab是出现一次的两个数字
    def FindNumsAppearOnceOtherthrice(self, array):
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
    a = solution1.FindNumsAppearOnceOtherthrice(l)
    print(a)