//
// Created by 陈高杰 on 2020/1/30.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> mlist;
        int col = matrix[0].size();
        int row = matrix.size();
        if(matrix.empty() || col == 0 || row ==0)
            return mlist;
        int start = 0;
        while(col>start*2 && row >start*2){
            int max_x = col-start-1;
            int max_y = row-start-1;
            for (int i = start; i <= max_x; ++i) {
                mlist.push_back(matrix[start][i]);
            }
            if(start<max_y){
                for (int i = start+1; i <= max_y; ++i) {
                    mlist.push_back(matrix[i][max_x]);
                }
            }
            if(start<max_x && start<max_y){
                for (int i = max_x-1; i >=start; --i) {
                    mlist.push_back(matrix[max_y][i]);
                }
            }
            if(start < max_x && start < max_y-1){
                for (int i = max_y-1; i >=start+1; --i) {
                    mlist.push_back(matrix[i][start]);
                }
            }
            start++;
        }

        return  mlist;
    }
};

//int main()
//{
////    vector<vector<int>> data = { { 1, 2, 3, 4}, { 5, 6, 7, 8}, { 9, 10, 11, 12}, { 13, 14, 15, 16}};
//    vector<vector<int>> data = {{1},{2},{3},{4},{5}};
//    cout << "listnode over" << endl;
//    Solution solution;
//    vector<int> output;
//    output = solution.printMatrix(data);
//    int col = data[0].size();
//    int row = data.size();
//    cout << "col:" << col << endl;
//    cout << "row:" << row << endl;
////    output = {1,2,3,4,5};
//    for (int i = 0; i < col *row; ++i) {
//        cout << output[i] << endl;
//    }
//
//    system("PAUSE");
//    return 0;
//}

