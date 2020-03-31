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
    string LeftRotateString(string str, int n) {
        int length = str.size();
        if(length<=1 || n<=0 || n>=length)
            return str;
        Reverse(str, 0, n-1);
        Reverse(str, n, length-1);
        Reverse(str, 0, length-1);
        return str   ;
    }
    void Reverse(string &str,int s,int e){
        while(s<e){
            swap(str[s++],str[e--]);
        }
    }
};

//int main(){
//    Solution solution;
//    string k = "abcdefg";
//    string n1;
//    n1 = solution.LeftRotateString(k,2);
//    for (int i = 0; i < n1.size(); ++i) {
//        cout<< n1[i];
//    }
//    system("PAUSE");
//    return 0;
//}

