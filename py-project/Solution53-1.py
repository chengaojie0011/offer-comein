# -*- coding:utf-8 -*-
class Solution:
    def GetFirstOfK(self, data, k,start,end):
        if start>end:
            return -1
        mid = (end+start)//2
        if data[mid]==k:
            if (mid>0 and data[mid-1] !=k) or mid == 0:
                return mid
            else:
                end = mid-1
        elif data[mid]<k:
            start = mid+1
        else:
            end = mid -1
        return self.GetFirstOfK(data, k,start,end)

    def GetLastOfK(self, data, k,start,end):
        if start>end:
            return -1
        mid = (end+start)//2
        if data[mid]==k:
            if ( mid<len(data)-1 and data[mid+1] !=k) or mid == len(data)-1:
                return mid
            else:
                start = mid+1
        elif data[mid]<k:
            start = mid+1
        else:
            end = mid -1
        return self.GetLastOfK(data, k,start,end)

    def GetNumberOfK(self, data, k):
        # write code here
        count = 0
        length = len(data)
        if data ==None or length<0:
            return 0
        first = self.GetFirstOfK(data, k,0,length-1)
        last = self.GetLastOfK(data,k,0,length-1)
        if first>-1 and last>-1:
            count = last - first +1
        return count


if __name__ == '__main__':
    l = [1,2,3,3,3,3]
    k = 3
    # print(len(l))
    solution1 = Solution()
    a = solution1.GetNumberOfK(l,k)
    print(a)