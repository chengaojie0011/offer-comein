# -*- coding:utf-8 -*-
class Solution:
    def maxInWindows(self, num, size):
        # write code here
        max_in_windows, index= [], []
        if len(num)<size or size<1:
            return max_in_windows

        for i in range(0,size):
            while len(index) >0 and num[i] >=num[index[-1]]:
                index.pop()
            index.append(i)

        max_in_windows.append(num[index[0]])

        for j in range(size,len(num)):
            while len(index) >0 and num[j] >=num[index[-1]]:
                index.pop()
            if len(index) >0 and index[0]<= j-size:
                index.pop(0)
            index.append(j)
            max_in_windows.append(num[index[0]])
        return max_in_windows

class Solution2:
    def maxInWindows(self, num, size):
        # write code here
        max_in_windows, index= [], []
        if len(num)<size or size<1:
            return max_in_windows
        for i in range(0,len(num)-size+1):
            max_in_windows.append(max(num[i:i+size]))
        return max_in_windows


if __name__ == '__main__':
    k = [2,3,4,2,6,2,5,1]
    n = 3
    # x = list(k)
    # print(''.join(x))
    solution1 = Solution2()
    a = solution1.maxInWindows(k,n)
    print(a)