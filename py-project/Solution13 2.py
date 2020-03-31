# -*- coding:utf-8 -*-
class Solution:
    def movingCount(self, threshold, rows, cols):
        # write code here
        self.count = 0
        way_map =  [[0 for i in range(cols)] for j in range(rows)]
        self.findway(threshold,rows,cols,0,0,way_map)
        return self.count

    def findway(self,threshold,rows,cols,i,j,way_map):
        if i < 0 or j < 0 or i >= rows or j >= cols:
            return
        list_i = list(map(int,str(i)))
        list_j = list(map(int,str(j)))
        sumij = sum(list_i)+sum(list_j)
        if sumij>threshold or way_map[i][j] == 1:
            return
        way_map[i][j] = 1
        self.count +=1
        self.findway(threshold,rows,cols,i+1,j,way_map)
        self.findway(threshold,rows,cols,i-1,j,way_map)
        self.findway(threshold,rows,cols,i,j+1,way_map)
        self.findway(threshold,rows,cols,i,j-1,way_map)
        return

if __name__ == "__main__":
    # matrix1 = [1 for i in range(1600)]
    matrix1 = range(400)
    solution1 = Solution()
    a = solution1.movingCount(4,3,3)
    print(a)