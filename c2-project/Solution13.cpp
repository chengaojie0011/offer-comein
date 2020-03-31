//
// Created by 陈高杰 on 2019-11-08.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution{
private:
    int count = 0;
public:
    int movingCount(int k,int rows,int cols){
        bool* flags = new bool[rows*cols];
        memset(flags,0,rows*cols);
        movingCountCore(k,rows,cols,0,0,flags);
        delete[] flags;
        return count;
    }
    void movingCountCore(int k,int rows,int cols,int row, int col, bool* flags){
        int idx = row*cols+col;
        if(row<0||row>=rows||col<0||col>=cols||flags[idx]==1||check(row,col)>k)
            return;
        flags[idx]=1;
        count++;
        movingCountCore(k,rows,cols,row-1,col,flags);
        movingCountCore(k,rows,cols,row+1,col,flags);
        movingCountCore(k,rows,cols,row,col-1,flags);
        movingCountCore(k,rows,cols,row,col+1,flags);
        return;
    }

    int check(int row, int col){
        int sum = 0;
        while(row>0){
            sum +=row%10;
            row = row/10;
        }
        while(col>0){
            sum +=col%10;
            col = col/10;
        }
        return sum;
    }
};


//int main()
//{
////    vector<vector<int>> a(3,vector<int>(3,2));
////    vector<vector<bool>> waymap(3,vector<bool>(3,false));
//    Solution solution;
////    cout << waymap[0][2] << endl;
////    string a = "aaaaa1sq";
////    cout << a << endl;
//    cout << solution.movingCount(4,3,3) << endl;
//    return 0;
//}


