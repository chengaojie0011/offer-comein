# -*- coding:utf-8 -*-
class QueueMax:
    def __init__(self):
        self.data = []
        self.data_max = []

    def push_back(self,num):
        self.data.append(num)
        while self.data_max and self.data_max[-1] <= num:
            self.data_max.pop()
        self.data_max.append(num)
        return

    def pop_front(self):
        if not self.data:
            raise Exception('Empty Queue Cannot Pop')
        if self.data[0] == self.data_max[0]:
            self.data_max.pop(0)
        return self.data.pop(0)

    def max(self):
        return self.data_max[0]

    # def printData(self):
    #     return self.data
    #
    # def printDataMax(self):
    #     return self.data_max


if __name__ == '__main__':
    k = [2,3,4,2,6,2,5,1]
    n = 3
    # x = list(k)x
    # print(''.join(x))
    solution1 = QueueMax()
    solution1.push_back(2)
    print(solution1.data)
    print(solution1.data_max)
    print(solution1.max())
    solution1.push_back(4)
    print(solution1.data)
    print(solution1.data_max)
    print(solution1.max())
    solution1.push_back(3)
    print(solution1.data)
    print(solution1.data_max)
    print(solution1.max())
    solution1.push_back(1)
    print(solution1.data)
    print(solution1.data_max)
    print(solution1.max())
    solution1.pop_front()
    print(solution1.data)
    print(solution1.data_max)
    print(solution1.max())
    solution1.pop_front()
    print(solution1.data)
    print(solution1.data_max)
    print(solution1.max())
    solution1.pop_front()
    print(solution1.data)
    print(solution1.data_max)
    print(solution1.max())
