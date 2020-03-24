//
// Created by 陈高杰 on 2020/2/12.
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

class Solution {
private:
    static int compare(const string& str1, const string& str2){
        string x1 = str1 + str2;
        string x2 = str2 + str1;
        return x1<x2;
    }
public:
    string PrintMinNumber(vector<int> numbers) {
        string res;
        if(numbers.empty())
            return res;
        vector<string> strs;
        for (int i = 0; i < numbers.size(); ++i) {
            string x;
            stringstream ss;
            ss << numbers[i];
            ss >> x;//或者 res = ss.str();
            strs.push_back(x);
        }
        sort(strs.begin(),strs.end(),compare);
        for (int i = 0; i < strs.size(); ++i) {
            res +=strs[i];
        }
        return res;
    }
};

class Solution2 {
private:
    static int compare(int a, int b){
        string A="";
        string B="";
        A+=to_string(a);
        A+=to_string(b);
        B+=to_string(b);
        B+=to_string(a);
        return A<B;
    }
public:
    string PrintMinNumber(vector<int> numbers) {
        string res;
        if(numbers.empty())
            return res;
        vector<int> strs;
        strs.assign(numbers.begin(), numbers.end());
        sort(strs.begin(),strs.end(),compare);
        for (int i = 0; i < strs.size(); ++i) {
            res +=to_string(strs[i]);
        }
        return res;
    }
};

//int main(){
//    vector<int> l = {3,32,321};
//    Solution2 solution;
//    string x = solution.PrintMinNumber(l);
//    for (int i = 0; i < x.size(); ++i) {
//        cout << x[i] ;
////        cout << " "<< endl;
//    }
////    cout << x<< endl;
//    system("PAUSE");
//    return 0;
//
//}