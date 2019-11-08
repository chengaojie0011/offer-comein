//
// Created by 陈高杰 on 2019-11-08.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    int count = 0;
    int findWay(int threshold, int rows, int cols,int i,int j,vector<vector<bool>> &waymap){
        if(i<0 || i>=rows || j<0 || j>=cols){
            return 0;
        }
        int sumij = getSum(i)+getSum(j);
        if(sumij>threshold || waymap[i][j] == true){
            return 0;
        }
        count +=1;
        waymap[i][j] = true;
        findWay(threshold,rows,cols,i+1,j,waymap);
        findWay(threshold,rows,cols,i-1,j,waymap);
        findWay(threshold,rows,cols,i,j+1,waymap);
        findWay(threshold,rows,cols,i,j-1,waymap);
        return 0;
    }

    int getSum(int number){
        int sum = 0;
        while (number>0){
            sum = sum+number%10;
            number = number/10;
        }
        return sum;
    }

public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool>> waymap(rows,vector<bool>(cols,false));
        findWay(threshold,rows,cols,0,0,waymap);
        return count;
    }
};


int main()
{
//    vector<vector<int>> a(3,vector<int>(3,2));
//    vector<vector<bool>> waymap(3,vector<bool>(3,false));
    Solution solution;
//    cout << waymap[0][2] << endl;
//    string a = "aaaaa1sq";
//    cout << a << endl;
    cout << solution.movingCount(4,3,3) << endl;
    return 0;
}


