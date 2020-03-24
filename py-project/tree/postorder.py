# -*- coding:utf-8 -*-
import tree.tree_build as tree_con

"""递归实现树的后序遍历"""
def post_order(root,ret= []):
    if root is None:
        return
    post_order(root.left)
    post_order(root.right)
    ret.append(root.value)
    print(root.value, end="\t")
    return ret

"""非递归实现树的后序遍历"""  
"""后序为左-右-根，倒过来就是根-右-左""" 
def post_order_stack(root):
    ret, stack = [], []
    while root or stack:
        if root:            
            stack.append(root)
            print(root.value, end="\t")
            ret.append(root.value)
#            ret.insert(0, root.value)
            root = root.right
        else:
            node = stack.pop()
            root = node.left
    return ret[::-1]


if __name__ == '__main__':
    tree = tree_con.main()
#    print(tree)
    print('achieved by recurve:', end="\t")
    l1 = post_order(tree.root)
    print('achieved by stack:', end="\t")    
    l2 = post_order_stack(tree.root)