# -*- coding:utf-8 -*-
import tree.tree_build as tree_con

"""递归实现树的中序遍历"""
def in_order(root,ret= []):
    if root is None:
        return
    in_order(root.left)
    ret.append(root.value)
    print(root.value, end="\t")
    in_order(root.right)
    return ret

"""非递归实现树的中序遍历"""   
def in_order_stack(root):
    ret, stack = [], []
    while stack or root:
        if root:
            stack.append(root)
            root = root.left
        else:
            node = stack.pop()
            print(node.value, end="\t")
            ret.append(node.value)
            root = node.right
    return ret

if __name__ == '__main__':
    tree = tree_con.main()
#    print(tree)
    print('achieved by recurve:', end="\t")
    l1 = in_order(tree.root)
    print('achieved by stack:', end="\t")    
    l2 = in_order_stack(tree.root)