# -*- coding:utf-8 -*-
class Solution1:
    def ReverseSentence(self, s):
        # write code here
        length = len(s)
        if length <=1:
            return s
        l_s = list(s)
        r_s = self.Reverse(l_s, 0, length-1)
        i = 0
        while i < length:
            while i < length and r_s[i] ==' ':
                i +=1
            s1 = e1 =i
            while i < length and r_s[i] !=' ':
                i +=1
                e1 +=1
            r_s = self.Reverse(r_s , s1, e1 - 1)
        return ''.join(r_s)


    def Reverse(self, s , start, end):
        while start<end:
            temp = s[start]
            s[start] = s[end]
            s[end] = temp
            start +=1
            end -=1
        return s

class Solution:
    def ReverseSentence(self, s):
        # write code here
        length = len(s)
        if length <=1:
            return s
        stacklist = s.split(" ")
        res = []
        while len(stacklist) > 0:
            res.append(stacklist.pop())
        return ' '.join(res)


if __name__ == '__main__':
    k =  "I am a student."
    # x = list(k)
    # print(''.join(x))
    solution1 = Solution()
    a = solution1.ReverseSentence(k)
    print(a)