# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # 返回二维列表，内部每个列表表示找到的路径
    def __init__(self):
        self.result = []
        # self.list1 = []

    def FindPathIn(self, root, path, currentNumber,expectNumber):
        currentNumber += root.val
        path.append(root)
        isleaf = root.left == None and root.right == None
        if currentNumber == expectNumber and isleaf:
            onePath = []
            for node in path:
                onePath.append(node.val)
            self.result.append(onePath)

        if currentNumber < expectNumber:
            if root.left:
                self.FindPathIn(root.left, path, currentNumber, expectNumber)
            if root.right:
                self.FindPathIn(root.right, path, currentNumber, expectNumber)
        path.pop()


    def FindPath(self, root, expectNumber):
        # write code here
        if not root:
            return []

        self.FindPathIn(root, [], 0,expectNumber)

        return self.result

if __name__ == '__main__':
    t1 = TreeNode(10)
    t2 = TreeNode(5)
    t3 = TreeNode(12)
    t4 = TreeNode(4)
    t5 = TreeNode(7)

    t1.left = t2
    t1.right = t3
    t2.left = t4
    t2.right = t5

    solution1 = Solution()
    a = solution1.FindPath(t1,22)
    print(a)