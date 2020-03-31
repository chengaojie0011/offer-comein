# -*- coding:utf-8 -*-

## 两个栈实现队列
class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def push(self, node):
        # write code here
        self.stack1.append(node)
    def pop(self):
        # return xx
        if len(self.stack2)==0:
            while len(self.stack1) >1:
                temp = self.stack1.pop()
                self.stack2.append(temp)
            return self.stack1.pop()
        else:
            return self.stack2.pop()

## 两个队列实现栈
class Solution2:
    def __init__(self):
        self.queue1 = []
        self.queue2 = []

    def push(self, node):
        # write code here
        self.queue1.append(node)
    def pop(self):
        # return xx
        if len(self.queue1) ==0:
            while len(self.queue2) >1:
                temp = self.queue2.pop()
                self.queue1.append(temp)
            return self.queue2.pop()
        if len(self.queue2) ==0:
            while len(self.queue1) >1:
                temp = self.queue1.pop()
                self.queue2.append(temp)
            return self.queue1.pop()

        return None


if __name__ == "__main__":
    stack11 = [1,2,3]
    stack22 = []
    if stack22:
        print(11)
    else:
        print(0)
