# -*- coding:utf-8 -*-
class Solution1:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        if not rotateArray:
            return 0
        else:
            return min(rotateArray)

class Solution2:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        if not rotateArray:
            return 0
        else:
            rotateArray.sort()
            return rotateArray[0]

class Solution3:
    def minInOrder(self,rotateArray,l,r):
        for i in range(l,r):
            # print(i,r)
            if  rotateArray[i]>rotateArray[i+1]:
                return rotateArray[i+1]
        return rotateArray[r]

    def minNumberInRotateArray(self, rotateArray):
        # write code here
        if not rotateArray:
            return 0
        else:
            left = 0
            right = len(rotateArray)-1
            mid = 0
            while rotateArray[left]>=rotateArray[right]:
                if right-left ==1:
                    mid = right
                    break
                mid = int(left+(right-left)/2)
                if rotateArray[mid] ==rotateArray[right] and rotateArray[mid] ==rotateArray[left]:
                    return self.minInOrder(rotateArray,left,right)
                if rotateArray[mid] >= rotateArray[right]:
                    left = mid
                elif rotateArray[mid] <= rotateArray[left]:
                    right = mid
            return rotateArray[mid]

if __name__ == "__main__":
    list1 = [3,4,5,1,2]
    list2 = [1,1,1,0,1]
    list3 = [1,0,1,1,1]
    list4 = [6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,9359,9719,9895,9896,9913,9962,154,293,334,492,1323,1479,1539,1727,1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,5142,5437,5448,5668,5706,5725,6300,6335]
    solution1 = Solution3()
    a = solution1.minNumberInRotateArray(list2)
    print(a)
