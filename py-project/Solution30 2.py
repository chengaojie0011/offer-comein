# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.stack = []
        self.s_min = []

    def push(self, node):
        # write code here
        min = self.min()
        if not min or node < min:
            self.s_min.append(node)
        else:
            self.s_min.append(min)
        self.stack.append(node)

    def pop(self):
        # write code here
        if self.stack:
            self.s_min.pop()
            return self.stack.pop()

    def top(self):
        # write code here
        if self.stack:
            return self.stack[-1]

    def min(self):
        # write code here
        if self.s_min:
            return  self.s_min[-1]

if __name__ == "__main__":

    solution1 = Solution()
    # a = solution1.printMatrix(m)
    # print(a)