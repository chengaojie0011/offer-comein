# -*- coding:utf-8 -*-
import functools
import sys
import copy as cp

class Solution:
    def __init__(self):
        self.gp_data = []
        self.gp_copy= []

    def InversePairCore(self,start,end):
        if start==end:
            self.gp_copy[start] = self.gp_data[start]
            return 0
        length = (end-start)//2
        left = self.InversePairCore(start, start+length)%1000000007
        right = self.InversePairCore(start+length+1, end)%1000000007
        count = 0
        p1 = start+length
        p2 = end
        index = end
        while p1>=start and p2>= start+length+1:
            if self.gp_data[p1] > self.gp_data[p2]:
                self.gp_copy[index] = self.gp_data[p1]
                index -=1
                p1 -=1
                count += p2-start-length
                if count >= 1000000007:
                    count %= 1000000007
            else:
                self.gp_copy[index] = self.gp_data[p2]
                index -=1
                p2 -=1
        while p1>=start:
            self.gp_copy[index] = self.gp_data[p1]
            index -= 1
            p1 -= 1
        while p2>=start+length+1:
            self.gp_copy[index] = self.gp_data[p2]
            index -= 1
            p2 -= 1
        self.gp_data =  cp.deepcopy(self.gp_copy)
        return (left+right+count)%1000000007

    def InversePairs(self, data):
        # write code here
        length = len(data)
        if data == None or length<=0:
            return 0
        self.gp_copy = cp.deepcopy(data)
        self.gp_data = cp.deepcopy(data)
        count = self.InversePairCore(0, length-1)
        return count

if __name__ == '__main__':
    l = [7,5,6,4]
    # print(len(l))
    solution1 = Solution()
    a = solution1.InversePairs(l)
    print(a)