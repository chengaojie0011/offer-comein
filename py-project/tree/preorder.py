# -*- coding:utf-8 -*-
import tree.tree_build as tree_con

"""递归实现树的前序遍历"""
def pre_order(root,ret= []):
    if root is None:
        return
    ret.append(root.value)
    print(root.value, end="\t")
    pre_order(root.left)
    pre_order(root.right)
    return ret

"""非递归实现树的前序遍历"""   
"""输出顺序为左-根-右"""
"""压入栈顺序，为根出栈，右-左压入栈"""
def pre_order_stack(root):
    ret, stack = [], [root]
    while stack:
        node = stack.pop()
        if node:
            print(node.value, end="\t")
            ret.append(node.value)
            #注意压入栈的顺序,先压入右孩子，再压入左孩子
            stack.append(node.right)
            stack.append(node.left)
    return ret

def pre_order_stack2(root):
    ret, stack = [], []
    while root or stack:
        if root:            
            stack.append(root)
            print(root.value, end="\t")
            ret.append(root.value)
#            ret.insert(0, root.value)
            root = root.left
        else:
            node = stack.pop()
            root = node.right
    return ret

if __name__ == '__main__':
    tree = tree_con.main()
#    print(tree)
    print('achieved by recurve:', end="\t")
    l1 =pre_order(tree.root)
    print('achieved by stack:', end="\t")    
    l2 = pre_order_stack(tree.root)
    print('achieved by stack2:', end="\t")   
    l3 = pre_order_stack(tree.root)     