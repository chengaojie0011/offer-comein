# -*- coding:utf-8 -*-
from heapq import *
class Solution:
    def __init__(self):
        self.heaps = [],[]
    def Insert(self, num):
        # write code here
        small, large = self.heaps
        heappush(small,-heappushpop(large,num))
        if len(large) < len(small):
            heappush(large,-heappop(small))

    def GetMedian(self,ss):
        # write code here
        small,large = self.heaps
        if len(small) != len(large):
            return float(large[0])
        return (large[0]-small[0])/2.0

# 构造小根堆时，对数组元素取负值来构造
# heappush(heap,data),将deat放入大根堆中
# heapposh(heap),弹出heap中的最小值
# heappushpop(heap,data),将data放入大根堆中，再弹出堆heap的最小值


if __name__ == '__main__':
    str = "abc"
    # x_list = str.split('')
    # x_list = list(str)
    # print(x_list)
    # x_str = ''.join(x_list)
    # print(x_str)
    l = [4, 5, 1, 6, 2, 7, 3, 8]
    solution1 = Solution()
    solution1.Insert(3)
    solution1.Insert(1)
    solution1.Insert(5)
    solution1.Insert(4)
    solution1.Insert(2)
    a = solution1.GetMedian(1)
    print(a)