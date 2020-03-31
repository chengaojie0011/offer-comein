# -*- coding:utf-8 -*-
## python3
from queue import PriorityQueue
## python2
# from Queue import PriorityQueue

class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        # write code here
        res = []
        size = len(tinput)
        if k > size or k * size == 0:
            return []

        q = PriorityQueue(k)
        for num in tinput:
            temp = num
            if q.qsize() >= k:
                temp = min(num, q.get()[1])
            q.put((-temp, temp))

        while not q.empty():
            res.append(q.get()[1])

        return res[::-1]


if __name__ == '__main__':
    str = "abc"
    # x_list = str.split('')
    # x_list = list(str)
    # print(x_list)
    # x_str = ''.join(x_list)
    # print(x_str)
    l = [4,5,1,6,2,7,3,8]
    solution1 = Solution()
    a = solution1.GetLeastNumbers_Solution(l, 4)
    print(a)