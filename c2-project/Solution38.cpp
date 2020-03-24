//
// Created by 陈高杰 on 2020/2/8.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if(str.empty()){
            return res;
        }
        PermutationCore(str,res,0);
        sort(res.begin(),res.end());
        return  res;
    }
    void PermutationCore(string str,vector<string> &result,int begin){
        if(begin == str.size()-1){
//            result.push_back(str);
            if(find(result.begin(),result.end(),str) == result.end())
            {
                // 如果result中不存在str，才添加；避免aa和aa重复添加的情况
                result.push_back(str);
            }

        }
        else{
            for(int i=begin;i<str.size();++i)
            {
                swap(str[i],str[begin]);
                PermutationCore(str,result,begin+1);
                swap(str[i],str[begin]); // 复位，用以恢复之前字符串顺序，达到第一位依次跟其他位交换的目的
            }
        }
    }
    void swap(char &fir,char &sec)
    {
        char temp = fir;
        fir = sec;
        sec = temp;
    }
};

//int main()
//{
//    string s = "aa";
//    Solution solution;
//    vector<string>  output1;
//    output1 = solution.Permutation(s);
////    vector<string>  output1 = {"abc","bca"};
//    for (int i = 0; i < output1.size(); ++i) {
//        for (int j = 0; j < output1[i].size(); ++j) {
//            cout << output1[i][j] ;
//        }
//        cout << " "<< endl;
//    }
//    system("PAUSE");
//    return 0;
//}
