# -*- coding:utf-8 -*-

class Node(object):
    """节点类"""
    def __init__(self, value=None, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


class Tree(object):
    """二叉树类"""
    def __init__(self):
        """初始化树类的根节点和遍历队列"""
        self.root = Node()
        self.tree_queue = []  # 叶子结点的数据

    def add(self, value):
        """添加数据构造函数"""
        node = Node(value)
        if self.root.value is None:  # 树为空则进行节点的添加
            self.root = node
            self.tree_queue.append(node)
        else:
            cur_node = self.tree_queue[0]  # 获取当前的根节点
            if cur_node.left is None:  # 左子树为空则进行添加
                cur_node.left = node
                self.tree_queue.append(node)
            else:  # 有字数为空则加入
                cur_node.right = node
                self.tree_queue.append(node)
                self.tree_queue.pop(0)  # 当前节点分配完成，退出队列


def main():
    tree = Tree()
    tree.add(0)
    tree.add(1)
    tree.add(2)
    tree.add(None)
    tree.add(3)

    return tree


if __name__ == '__main__':
    tree = main()
    l = tree.tree_queue

    

    