//
// Created by 陈高杰 on 2019-11-14.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

class Solution {
private:
    int getIndex1To9(char* number,int n,int index){
        if(index==n-1){
            printNumber(number);
            return 0;
        }
        for (int i = 0; i < 10; ++i) {
            number[index+1] = i+'0';
            getIndex1To9(number,n,index+1);
        }
        return 0;
    }
    int printNumber(char* number){
        bool begin = false;
//        char* s = "0123456789";
//        sizeof(s);     //结果 4    ＝＝＝》s是指向字符串常量的字符指针
//        sizeof(*s);    //结果 1    ＝＝＝》*s是第一个字符
//        strlen(s);     //结果 10   ＝＝＝》有10个字符，strlen是个函数内部实现是用一个循环计算到\0为止之前
//        cout<<sizeof(number)/sizeof(char *)<<endl;
//        cout<<strlen(number)<<endl;
        for (int i = 0; i < strlen(number); ++i) {
            if(begin==false && number[i]!='0'){
                begin = true;
            }
            if(begin){
//                int out =static_cast<int>(number[i]);
                cout<<number[i];
//                cout<<out<<endl;

            }
        }
        cout<<"\t"<<endl;
        return 0;
    }
public:
    int print1ToMax(int n){
        if(n<=0){
            return 0;
        }
        char* number = new char[n+1];
//        number[n] ='\0';
        for (int i = 0; i < 10; ++i) {
            number[0] = i + '0';
            getIndex1To9(number,n,0);
        }
        delete[] number;
        return 0;
    }


};


//int main()
//{
//    Solution solution;
//    cout << solution.print1ToMax(1) << endl;
//    return 0;
//}




