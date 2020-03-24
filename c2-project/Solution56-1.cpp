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


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

//异或的性质
//两个数字异或的结果a^b是将 a 和 b 的二进制每一位进行运算，得出的数字。 运算的逻辑是
//如果同一位的数字相同则为 0，不同则为 1
//异或的规律
//任何数和本身异或则为0
//任何数和 0 异或是本身

class Solution1 {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int length = data.size();
        if(data.empty() || length<2)
            return;
        int xor_res = 0;
        for (int i = 0; i < length; ++i) {
            xor_res ^= data[i];
        }
        int index = FirstOneIndex(xor_res);
        *num1 = * num2 = 0;
        for (int j = 0; j < length; ++j) {
            if(IsBitOne(data[j],index))
                *num1 ^=  data[j];
            else
                *num2 ^=  data[j];
        }
        return;
    }
    int FirstOneIndex(int num){
        int index = 0;
        while((num&1)==0 && index<8* sizeof(int)){
            num = num>>1;
            index++;
        }
        return index;
    }
    bool IsBitOne(int num,int index){
        num = num >> index;
        return (num&1);
    }
};


class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int length = data.size();
        if(data.empty() || length<2)
            return;
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
        *num1 = nums[0];
        *num2 = nums[1];
        return;
    }
};

//int main(){
//    vector<int> l = {2,4,3,6,3,2,5,5};
//
//    Solution solution;
//    int k = 3;
//    int n1 = -1;
//    int n2 = -1;
//    solution.FindNumsAppearOnce(l,&n1,&n2);
//    cout<< n1<<endl;
//    cout<< n2<<endl;
//    system("PAUSE");
//    return 0;
//}