# -*- coding:utf-8 -*-

class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        # write code here
        mlist = []
        if matrix == None:
            return mlist
        col = len(matrix[0])
        row = len(matrix)
        start = 0
        while col>2*start and row>2*start:
            maxx = col - start -1
            maxy = row - start -1
            for i in range(start,maxx+1):
                print(start,i)
                mlist.append(matrix[start][i])

            if start < maxy:
                for i in range(start+1,maxy+1):
                    mlist.append(matrix[i][maxx])

            if start < maxx and start < maxy:
                for i in range(start,maxx):
                    j = maxx-1+start-i
                    mlist.append(matrix[maxy][j])

            if start < maxx and start < maxy-1:
                for i in range(start+1,maxy):
                    j = maxy+start-i
                    if start == 1:
                        print(i)
                    mlist.append(matrix[j][start])
            start +=1
        return mlist


if __name__ == "__main__":
    # m =[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    m = [[1],[2],[3],[4],[5]]
    # m = [[1]]
    print(len(m))
    print(len(m[0]))
    solution1 = Solution()
    a = solution1.printMatrix(m)
    print(a)