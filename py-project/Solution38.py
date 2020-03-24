# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.res = []

    def Permutation2(self, str1, num):
        if num == len(str1)-1:
            str_s = "".join(str1)
            if str_s not in self.res:
                self.res.append(str_s)
                self.res.sort()
        else:
            i = num
            while i<len(str1):
                # str1 = list(str1)
                temp = str1[num]
                str1[num] = str1[i]
                str1[i] = temp
                self.Permutation2(str1,num+1)
                temp = str1[num]
                str1[num] = str1[i]
                str1[i] = temp
                i += 1

    def Permutation(self, ss):
        # write code here
        if ss is None:
            return None
        num = 0
        ss = list(ss)
        self.Permutation2(ss,num)
        return self.res


if __name__ == '__main__':
    str = "abc"
    # x_list = str.split('')
    # x_list = list(str)
    # print(x_list)
    # x_str = ''.join(x_list)
    # print(x_str)

    solution1 = Solution()
    a = solution1.Permutation(str)
    print(a)