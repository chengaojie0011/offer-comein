# -*- coding:utf-8 -*-
class Solution:
    # s, pattern都是字符串
    def match(self, s, pattern):
        # write code here
        if len(s)==0 and len(pattern) ==0:
            return True
        elif len(s)==0 and len(pattern)!=0:
            if len(pattern)>1 and pattern[1] =='*':
                ##e.g.  a*a*a*a*，可以都出现0次
                return self.match(s,pattern[2:])
            else:
                return False
        elif len(s)!=0 and len(pattern)==0:
            return False
        else:
            if len(pattern) >1 and pattern[1] =='*':
                if s[0] != pattern[0] and pattern[0] !='.':
                    # s与pattern的第一个元素不同，则s不变，pattern后移两位，相当于pattern前两位当成空
                    return self.match(s,pattern[2:])
                else:
                    # 如果s[0]与pattern[0]相同，且pattern[1]为*，这个时候有三种情况,如果pattern[0] =='.'，也可以视作相同
                    # pattern后移2个，s不变；相当于把pattern前两位当成空，匹配后面的
                    # pattern后移2个，s后移1个；相当于pattern前两位与s[0]匹配
                    # pattern不变，s后移1个；相当于pattern前两位，与s中的多位进行匹配，因为*可以匹配多位
                    if self.match(s, pattern[2:]) or self.match(s[1:], pattern[2:]) or self.match(s[1:], pattern):
                        return True
                    else:
                        return False
            else:
                # pattern第二个字符不为*的情况
                if s[0] == pattern[0] or pattern[0] == '.':
                    return self.match(s[1:],pattern[1:])
                else:
                    return False
        return -1

if __name__ == "__main__":
    solution1 = Solution()
    a = solution1.match("aa",".*a")
    print(a)
