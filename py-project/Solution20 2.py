# -*- coding:utf-8 -*-
class Solution:
    # s字符串
    def isNumeric(self, s):
        # write code here
        if not s:
            return False
        ## A[.[B]][E|eC]
        ## A有数字则为true
        a_flag,sa= self.scanInt(s)
        flag = a_flag

        if len(sa)!=0:
            if sa[0]=='.':
                #A没数字，B有
                #A有，B没有
                #都有
                b_flag,sb = self.scanUnsignedInt(sa[1:])
                flag = a_flag or b_flag
            else:
                sb = sa
        else:
            sb =  sa


        if len(sb)!=0:
            if sb[0] =='e' or sb[0] =='E':
                c_flag, sc = self.scanInt(sb[1:])
                flag = flag and c_flag
            else:
                sc = sb
        else:
            sc = sb
        ##必须走完才可以
        return flag and len(sc)==0

    def scanUnsignedInt(self,s):
        i=0
        while(i<len(s) and s[i]>='0' and s[i]<='9'):
            i +=1
        return i>0,s[i:]

    def scanInt(self,s):
        if len(s)==0:
            return self.scanUnsignedInt(s)
        if s[0]=='+' or s[0] =='-':
            return self.scanUnsignedInt(s[1:])
        else:
            return self.scanUnsignedInt(s)

class Solution1:
    # s字符串
    def isNumeric(self, s):
        # write code here
        try:
            ss = float(s)
            return True
        except:
            return False

if __name__ == "__main__":
    solution1 = Solution()
    a = solution1.isNumeric('1a3.14')
    # a = solution1.isNumeric("123.45e+6")
    print(a)
