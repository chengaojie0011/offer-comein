# -*- coding:utf-8 -*-
class Solution4:
    # array 二维列表
    def Find(self, target, array):
        # write code here
        row = 0
        column = len(array[0])-1
        while row>=0 and row<len(array) and column>=0 and column<len(array[0]) :
            if target == array[row][column]:
#                print('row is',row)
#                print('column is',column)
                return True
            elif target < array[row][column]:
#                print(column)
                column -= 1
            else:
#                print(row)
                row += 1
        return False
    


if __name__ == "__main__": 
    data = [[ 1, 2, 8, 9],[2, 4, 9, 12],[4, 7, 10, 13],[6, 8, 11, 15]] 
    number = 7
    solution = Solution4()
    output = solution.Find(number,data)
    print("output of this topic is :",output)
    