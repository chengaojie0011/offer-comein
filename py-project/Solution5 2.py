# -*- coding:utf-8 -*-
class Solution5_1:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        s=s.replace(' ','%20')
        return s
    
class Solution5_2:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        s = list(s)
        for index,i in enumerate(s):
            if i == ' ':
                s[index] = '%20'
         ##先变成列表，再合并，使用join（）                          
        return ''.join(s)

if __name__ == "__main__": 
    data = 'We are happy!'
    data1 = list(data)        
    number = 7
    solution = Solution5_2()
    output = solution.replaceSpace(data)
    print("output of this topic is :",output)
    