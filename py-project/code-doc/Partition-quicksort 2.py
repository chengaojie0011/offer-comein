# -*- coding:utf-8 -*-
import random

def Swap(data1,data2):
    temp = data1
    data1 = data2
    data2 = temp
    return data1,data2

def Partition(data,length,start,end):
    if data == None or length <=0 or start<0 or end >=length:
        return None
    p = random.randrange(start, end)
    # p = 4
    data[p], data[end] = Swap(data[p],data[end])
    small = start-1
    for i in range(start,end):
        if data[i]<data[end]:
            small+=1
            if small != i:
                data[small], data[i] = Swap(data[small], data[i])
    small +=1
    data[small], data[end] = Swap(data[small], data[end])
    return small

def QuickSort(lists,length,start,end):
    if start == end:
        return lists
    index  = Partition(lists,length,start,end)
    if index>start:
        lists= QuickSort(lists, length, start, index-1)
    if index<end:
        lists = QuickSort(lists, length, index+1, end)
    return lists


if __name__ == '__main__':
    l = [2,4,6,3,5]
    x = Partition(l, 5, 0, 4)
    print(x)
    y = QuickSort(l, 5, 0, 4)
    print(y)


