# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # 返回从上到下每个节点值列表，例：[1,2,3]
    def PrintFromTopToBottom(self, root):
        # write code here
        if root is None:
            return []
        res = []
        queue = [root]
        while queue:
            node = queue.pop(0)
            res.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return res

# 题目二：从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行
class Solution2:
    # 返回二维列表[[1,2],[4,5]]
    def Print(self, pRoot):
        # write code here
        if pRoot is None:
            return []
        result = []
        queue = [pRoot]

        while queue:
            next_q = []
            res = []
            for node in queue:
                res.append(node.val)
                if node.left:
                    next_q.append(node.left)
                if node.right:
                    next_q.append(node.right)
            queue = next_q
            result.append(res)
        return result

class Solution3:
    def Print(self, pRoot):
        # write code here
        if pRoot is None:
            return []
        result = []
        stack1 = [pRoot]
        stack2 = []
        while stack1 or stack2:
            res = []
            while stack1:
                node = stack1[-1]
                res.append(node.val)
                if node.left:
                    stack2.append(node.left)
                if node.right:
                    stack2.append(node.right)
                stack1.pop(-1)
            if res:
                result.append(res)
            res = []
            while stack2:
                node = stack2[-1]
                res.append(node.val)
                if node.right:
                    stack1.append(node.right)
                if node.left:
                    stack1.append(node.left)
                stack2.pop(-1)
            if res:
                result.append(res)
        return result


if __name__ == '__main__':
    print('11')