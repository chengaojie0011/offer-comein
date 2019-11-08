# -*- coding:utf-8 -*-
class Solution:
    def hasPath(self, matrix, rows, cols, path):
        # write code here
        for i in range(rows):
            for j in range(cols):
                if matrix[i*cols+j] == path[0]:
                    self.b = False
                    print(i, ',', j, ',', path[0])
                    self.pathfind(matrix,rows,cols,i,j,path[1:],[(i,j)])
                    if self.b:
                        return True
        return False

    def pathfind(self,matrix,rows,cols,i,j,path,visted):
        if not path:
            self.b = True
            return
        if j != 0 and matrix[i*cols+j-1] == path[0] and (i, j - 1) not in visted:
            print(i,',',j,',',path[0])
            visted.append((i, j - 1))
            self.pathfind(matrix,rows,cols,i,j-1,path[1:],visted)
        if j != cols-1 and matrix[i*cols+j+1] == path[0] and (i, j + 1) not in visted:
            print(i,',',j,',',path[0])
            visted.append((i, j + 1))
            self.pathfind(matrix,rows,cols,i,j+1,path[1:],visted)
        if i != 0 and matrix[(i-1)*cols+j] == path[0] and (i-1, j) not in visted:
            print(i,',',j,',',path[0])
            visted.append((i - 1, j))
            self.pathfind(matrix,rows,cols,i-1,j,path[1:],visted)
        if i != rows-1 and matrix[(i+1)*cols+j] == path[0] and (i+1, j) not in visted:
            print(i,',',j,',',path[0])
            visted.append((i +1, j))
            self.pathfind(matrix,rows,cols,i+1,j,path[1:],visted)



if __name__ == "__main__":
    # 'A','B','C','E','H','J','I','G','S','F','C','S','L','O','P','Q','A','D','E','E','M','N','O','E','A','D','I','D','E','J','F','M','V','C','E','I','F','G','G','S'
    matrix1 = ['a','b','t','g','c','f','c','s','j','d','e','a']

    matrix2 = ['A','B','C','E','H','J','I','G',
               'S','F','C','S','L','O','P','Q',
               'A','D','E','E','M','N','O','E',
               'A','D','I','D','E','J','F','M',
               'V','C','E','I','F','G','G','S']
    solution1 = Solution()
    path1 = ['b','f','c','e']
    # 'S','G','G','F','I','E','C','V','A','A','S','A','B','C','E','H','J','I','G','Q','E','M'
    path2 = ['S','G','G','F','I',
             'E','C','V','A','A',
             'S','A','B','C','E',
             'H','J','I','G','Q',
             'E','M']
    # a = solution1.hasPath(matrix1,3,4,path1)
    a = solution1.hasPath(matrix2,5,8,path2)
    print(a)
