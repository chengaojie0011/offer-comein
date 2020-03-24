# -*- coding:utf-8 -*-
class Solution:
    def FindContinuousSequence(self, tsum):
        # write code here
        res = []
        if tsum<3:
            return res
        small = 1
        big = 2
        mid = (tsum+1)//2
        sum = small+big
        while small<mid:
            if sum ==tsum:
                res.append(self.PrintSumOnce(small, big))
            while sum>tsum and small<mid:
                sum -= small
                small +=1
                if sum == tsum:
                    res.append(self.PrintSumOnce(small, big))
            big +=1
            sum +=big

        return res

    def PrintSumOnce(self,n1,n2):
        res_in = []
        for i in range(n1,n2+1):
            res_in.append(i)

        return res_in


if __name__ == '__main__':
    l = [1,2,4,7,11,15]
    k = 15
    # print(len(l))
    solution1 = Solution()
    a = solution1.FindContinuousSequence(k)
    print(a)