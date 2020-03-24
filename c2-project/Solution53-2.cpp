//
// Created by 陈高杰 on 2020/2/17.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <sstream>
#include <map>
using namespace std;

class Solution {
public:
    int GetMissingNumber(vector<int> data) {
        int length = data.size();
        if(data.empty() || length <=0)
            return -1;
        int left = 0;
        int right =length-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(data[mid]!= mid){
                if(data[mid-1]==mid-1 || mid == 0){
                    return mid;
                }
                else
                    right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return -1;
    }
};

//int main(){
////    vector<int> l = {1,2,3,3,3,3,4,5};
//    vector<int> l = {0,1,2,3,4,5,6,7,8,9,10,11,12,14,15,16};
//    Solution solution;
//    int k = 2;
//    int x = solution.GetMissingNumber(l);
//    cout<< x<<endl;
//    system("PAUSE");
//    return 0;
//}