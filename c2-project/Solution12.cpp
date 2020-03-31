//
// Created by 陈高杰 on 2019-11-07.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    /*
      matrix矩阵中所有点作为起点的方法，然后依据这个点进行向四个方向的递归；
      在递归中，不满足题目的会自动出栈回到上一个状态；
    */
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==NULL||rows<1||cols<1||str==NULL) return false;
        bool *flag=new bool[rows*cols];
        memset(flag,false,rows*cols);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(haha(matrix,rows,cols,i, j,str,0,flag))
                {
                    return true;
                }
            }
        }
        delete[] flag;
        return false;
    }
    /*参数说明*/
    bool haha(char* matrix,int rows,int cols,int i,int j,char* str,int k,bool* flag)
    {
        //因为是一维数组存放二维的值，index值就是相当于二维数组的（i，j）在一维数组的下标
        int index = i * cols + j;
        //flag[index]==true,说明被访问过了，那么也返回true;
        if(i<0 || i>=rows || j<0 || j>=cols || matrix[index]!=str[k] || flag[index]==true)
            return false;
        //字符串已经查找结束，说明找到该路径了
        if(str[k+1]=='\0') return true;
        //向四个方向进行递归查找,向左，向右，向上，向下查找
        flag[index] = true;//标记访问过
        if(  haha(matrix, rows, cols, i - 1, j,     str, k + 1, flag)
             ||haha(matrix, rows, cols, i + 1, j,     str, k + 1, flag)
             ||haha(matrix, rows, cols, i,     j - 1, str, k + 1, flag)
             ||haha(matrix, rows, cols, i,     j + 1, str, k + 1, flag))
        {
            return true;
        }
        flag[index] = false;
        return false;
    }
};



//int main()
//{
//    char matrix[] ="abtgcfcsjdea";
////    char matrix[] ="ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
////    char* matrix = a;
//    char path[] ="bfce";
////    char path[] ="SGGFIECVAASABCEHJIGQEM";
////    char* matrix = a;
//   Solution solution;
////    cout << path[1] << endl;
//    cout << solution.hasPath(matrix,3,4,path) << endl;
//    return 0;
//}

