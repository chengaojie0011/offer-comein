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
using namespace std;


class Solution{
public:
    int longestSubstringWithoutDuplication(const string& str){
        int maxlength = 0;
        int curlength = 0;
        int length = str.size();
        if(length==0)
            return maxlength;
        int* position = new int[26];
        for (int j = 0; j < 26; ++j) {
            position[j] = -1;
        }
        for (int i = 0; i < length; ++i) {
            int preindex = position[str[i]-'a'];
            if(preindex<0 ||i-preindex >curlength){
                curlength++;
            }
            else{
                if(curlength>maxlength)
                    maxlength = curlength;
                curlength =  i - preindex;
            }
            position[str[i]-'a'] = i;

        }
        if(curlength>maxlength){
            maxlength = curlength;
        }
        delete[]position;
        return maxlength;
    }
};

//int main(){
//    string l = "arabcacfr";
//    Solution solution;
//    int x = solution.longestSubstringWithoutDuplication(l);
//    cout<< x<<endl;
//    system("PAUSE");
//    return 0;
//}