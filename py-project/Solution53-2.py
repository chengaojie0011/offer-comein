# -*- coding:utf-8 -*-
class Solution:
    def GetMissingNumber(self, data):
        length = len(data)
        if data == None or length<=0:
            return -1
        left = 0
        right = length-1
        while left<=right:
            mid = (right+left)//2
            if data[mid] != mid:
                if data[mid-1] == mid-1 or mid ==0:
                    return mid
                else:
                    right = mid-1
            else:
                left = mid+1
        return -1


if __name__ == '__main__':
    l = [0,1,2,3,4,5,6,7,8,9,10,11,12,14,15,16]
    k = 3
    # print(len(l))
    solution1 = Solution()
    a = solution1.GetMissingNumber(l)
    print(a)