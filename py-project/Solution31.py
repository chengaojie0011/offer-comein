# -*- coding:utf-8 -*-
class Solution:
    def IsPopOrder(self, pushV, popV):
        # write code here
        # res = False
        stack = []
        if pushV and popV:
            for i in pushV:
                stack.append(i)
                while stack[-1] == popV[0]:
                    stack.pop()
                    popV.pop(0)
                    if not popV:
                        return True
        return False

if __name__ == "__main__":
    pushv = [1,2,3,4,5]
    popv = [4,5,3,2,1]
    solution1 = Solution()
    a = solution1.IsPopOrder(pushv,popv)
    print(a)