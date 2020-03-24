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
    int GetNumberSameAsIndex(vector<int> data) {
        int length = data.size();
        if(data.empty() || length <=0)
            return -1;
        int left = 0;
        int right =length-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(data[mid] == mid){
                return mid;
            }
            else if(data[mid] > mid){
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
//    vector<int> l = {-3,-1,1,3,5};
//    Solution solution;
//    int k = 2;
//    int x = solution.GetNumberSameAsIndex(l);
//    cout<< x<<endl;
//    system("PAUSE");
//    return 0;
//}