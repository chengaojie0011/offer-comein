# -*- coding:utf-8 -*-

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        # write code here

if __name__ == "__main__": 
    
    listNode1 = ListNode(1)
    listNode2 = ListNode(6)
    listNode3 = ListNode(3)
    listNode4 = ListNode(4)    
    
    listNode1.next = listNode2
    listNode2.next = listNode3   
    listNode3.next = listNode4    

    node = listNode1
    while node!=None:
       print(node.val)
       node = node.next

    solution = Solution6_1()    
    ool = solution.printListFromTailToHead(listNode1)  

    

    