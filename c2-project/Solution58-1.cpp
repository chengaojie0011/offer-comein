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
    string ReverseSentence(string str) {
        string res;
        if(str.size()<=0)
            return res;
        Reverse(str,0,str.size()-1);
        int s = 0, e = 0,i = 0;
        while(i<str.size()){
            while(i<str.size() && str[i]==' ')
                i++;
            s= e = i;
            while(i<str.size() && str[i]!=' '){
                i++;
                e++;
            }
            Reverse(str,s,e-1);
        }
        return str;
    }
    void Reverse(string &str,int s,int e){
        while(s<e){
            swap(str[s++],str[e--]);
        }
    }
};

//int main(){
//    Solution solution;
//    string k = "I am a student.";
//    string n1;
//    n1 = solution.ReverseSentence(k);
//    for (int i = 0; i < n1.size(); ++i) {
//        cout<< n1[i];
//    }
//    system("PAUSE");
//    return 0;
//}

