# -*- coding:utf-8 -*-

## 剑指offer的不稳定
class Solution1:
    def isEven(self,x):
        if x%2 ==0:
            return True
        else:
            return False

    def reOrderArray(self, array):
        # write code here
        if len(array)<=1:
            return array
        left = 0
        right = len(array)-1
        while left < right:
            # a = self.isEven(array1[left])
            while not self.isEven(array[left]) and left <right :
                left +=1
            while self.isEven(array[right]) and left <right:
                right -=1

            if left < right:
                temp = array[left]
                array[left] = array[right]
                array[right] = temp

        return array
## 牛客上要考虑稳定性，顺序不变
## time:O(n),space:O(n)
class Solution2:
    def isEven(self,x):
        if x%2 ==0:
            return True
        else:
            return False

    def reOrderArray(self, array):
        # write code here
        a_len = len(array)
        if a_len<=1:
            return array
        even = []
        i =0
        j= 0
        while j <a_len:
            if self.isEven(array[i]):
                even.append(array[i])
                array.pop(i)
            else:
                i +=1
            j += 1
        return array+even

## time:O(n2),space:O(1)
class Solution:
    def isEven(self,x):
        if x%2 ==0:
            return True
        else:
            return False

    def reOrderArray(self, array):
        # write code here
        a_len = len(array)
        if a_len<=1:
            return array
        for i in range(a_len):
            # print(array)
            for x in range(a_len):
                j = a_len-x-1
                if j>i:
                    if not self.isEven(array[j]) and self.isEven(array[j-1]):

                        temp = array[j-1]
                        array[j - 1] = array[j]
                        array[j] = temp

        return array




if __name__ == "__main__":
    list = [1,2,3,4,5,6,7,8]
    solution1 = Solution()
    a = solution1.reOrderArray(list)
    # a = solution1.isNumeric("123.45e+6")
    print(a)