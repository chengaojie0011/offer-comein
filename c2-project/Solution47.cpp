//
// Created by 陈高杰 on 2020/2/14.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <sstream>
#include <iostream>
using namespace std;


 class Solution{
 public:
     int getMaxValueofMatrix(vector<vector<int>> matrix){
         int max_value = 0;
         if(matrix.empty() || matrix.size() <=0 || matrix[0].size() <=0)
             return 0;
         int rows = matrix.size();
         int cols = matrix[0].size();
         int **max_values = new int*[rows];
         for (int i = 0; i < rows; ++i) {
             max_values[i] = new int[cols];
         }
         for (int i = 0; i < rows; ++i) {
             for (int j = 0; j < cols; ++j) {
                 int left = 0;
                 int up = 0;
                 if(i>0)
                     up = max_values[i-1][j];
                 if(j>0)
                     left = max_values[i][j-1];
                 max_values[i][j] = max(left,up)+ matrix[i][j];
             }
         }
         max_value = max_values[rows-1][cols-1];
         for (int k = 0; k < cols; ++k) {
             delete[] max_values[k];
         }
         delete[] max_values;
         return max_value;
     }
};

// int main(){
//     vector<vector<int>> matrix = {{1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5}};
//     for (int i = 0; i < matrix.size(); ++i) {
//         for (int j = 0; j < matrix[0].size(); ++j) {
//             cout << matrix[i][j]<< ' ';
//         }
//         cout << endl;
//     }
//     Solution solution;
//     int x = solution.getMaxValueofMatrix(matrix);
//     cout << x<< endl;
//     system("PAUSE");
//     return 0;
// }