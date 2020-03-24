# -*- coding:utf-8 -*-
class Solution:
    def GetNumberSameAsIndex(self, data):
        length = len(data)
        if data == None or length<=0:
            return -1
        left = 0
        right = length-1
        while left<=right:
            mid = (right+left)//2
            if data[mid] == mid:
                return mid
            elif data[mid] > mid:
                right = mid-1
            else:
                left = mid+1
        return -1


if __name__ == '__main__':
    l = [-3,-1,1,3,5]
    k = 3
    # print(len(l))
    solution1 = Solution()
    a = solution1.GetNumberSameAsIndex(l)
    print(a)