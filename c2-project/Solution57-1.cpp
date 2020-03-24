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
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int length = array.size();
        vector<int> res;
        if(length<=1)
            return res;
        int first = 0;
        int second = length-1;
        while(first<second){
            int temp = array[first] +array[second];
            if(temp ==sum){
                res.push_back(array[first]);
                res.push_back(array[second]);
                return res;
            }
            else if (temp <sum){
                first++;
            }
            else{
                second--;
            }
        }
        return res;
    }
};


//int main(){
//    vector<int> l = {1,2,4,7,11,15};
//
//    Solution solution;
//    int k = 15;
//    vector<int> n1;
//    n1 = solution.FindNumbersWithSum(l,k);
//    for (int i = 0; i < n1.size(); ++i) {
//        cout<< n1[i]<<endl;
//    }
//    system("PAUSE");
//    return 0;
//}

