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

class Solution1 {
public:
    int FindNumsAppearOnceOtherthrice(vector<int> data) {
        int length = data.size();
        if(data.empty() || length<=0)
            return -1;
        map<char, int> mp;
        for (int i = 0; i < length; ++i) {
            mp[data[i]]++;
        }
        vector<int> nums;
        for (int i = 0; i < length; ++i) {
            if(mp[data[i]]==1){
                nums.push_back(data[i]);
            }
        }
        int num1 = nums[0];
        return num1;
    }
};

class Solution {
public:
    int FindNumsAppearOnceOtherthrice(vector<int> data) {
        int length = data.size();
        if(data.empty() || length<=0)
            return -1;
        int bitSum[32] = {0};
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j <32; ++j) {
                int x = data[i]>>j;
                if(x&1)
                    bitSum[31-j] +=1;
            }
        }
//        for (int i = 0; i < length; ++i) {
//            int bitMask = 1;
//            for (int j = 31; j >=0; --j) {
//                int bit = data[i]&bitMask;
//                if(bit!=0)
//                    bitSum[j] +=1;
//                bitMask = bitMask<<1;
//            }
//        }
        int res = 0;
        for (int k = 0; k < 32; ++k) {
            res = res<<1;
            res += bitSum[k]%3;
        }
        return res;
    }
};

//int main(){
//    vector<int> l = {2,7,5,2,2,5,5};
//
//    Solution solution;
//    int k = 3;
//    int n1;
//    n1 = solution.FindNumsAppearOnceOtherthrice(l);
//    cout<< n1<<endl;
//    system("PAUSE");
//    return 0;
//}

