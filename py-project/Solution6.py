# -*- coding:utf-8 -*-
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution6_Minimum_memory:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        l = []
        while listNode!=None:
            l.append(listNode.val)
            listNode = listNode.next
        return l[::-1]

class Solution6_1:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        l = []
        node = listNode
        while node!=None:
            l.append(node.val)
            node = node.next
        return l[::-1]
    
class Solution6_2:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        l = []
        node = listNode
        while node!=None:
            l.append(node.val)
            node = node.next
        #reversed(l)都可以用，但l.reverse只有list可以用,并且是改变其自身
#        l.reverse()
#        return l
        return list(reversed(l))
    
####这个不行，sort是按数值排序
class Solution6_error:
    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        # write code here
        l = []
        node = listNode
        while node!=None:
            l.append(node.val)
            node = node.next

#        return sorted(l,reverse=True)
#        l.sort(reverse=True)
#        return l


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

    

    