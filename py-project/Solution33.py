# -*- coding:utf-8 -*-
class Solution:
    def VerifySquenceOfBST(self, sequence):
        # write code here
        length = len(sequence)
        if length <=0 or sequence ==None:
            return False
        root = sequence[-1]
        for i in range(length):
            if sequence[i] > root:
                break

        for j  in range(i,length):
            if sequence[j]<root:
                return False

        left = True
        if i>0:
            left = self.VerifySquenceOfBST(sequence[0:i])

        right = True
        if i<length-1:
            right = self.VerifySquenceOfBST(sequence[i:-1])

        return left and right

if __name__ == '__main__':
    s = [5,7,6,9,11,10,8]
    # print(len(s[0:3]))
    solution1 = Solution()
    a = solution1.VerifySquenceOfBST(s)
    print(a)