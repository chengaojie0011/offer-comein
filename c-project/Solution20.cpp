//
// Created by 陈高杰 on 2019-11-16.
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
    bool scanInt(char** str){
        if(**str == '+' || **str =='-' ){
            ++(*str);
        }
        return scanUnsignedInt(str);
    }

    bool scanUnsignedInt(char** str){
        int i = 0;
//        char* before = *str;
        while(**str!='\0' && **str>='0' && **str<='9'){
            ++i;
            ++(*str);
        }
        return i >0;

    }
public:
    bool isNumeric(char* string)
    {
        if(string== nullptr){
            return false;
        }
        bool flag = scanInt(&string);

        if(*string=='.'){
            ++string;
            //注意这里顺序也有关系flag在前就不进行后面的了
            flag =  scanUnsignedInt(&string)||flag;
        }

        if(*string=='E' || *string=='e'){
            ++string;
            flag = flag && scanInt(&string);

        }
        return flag && *string=='\0';
    }

};

int main()
{

    Solution solution;
//    char* str = new char[10]();
    char a[] = "123.45e+6";
    char* s = a;
//    for (int i = 0; i < 10; ++i) {
////        str[i]='o';
//        cout << str[i]<< endl;
//
//    }
//    cout << strlen(s)<< endl;
//    cout << *(s+3)<< endl;
//    char** s2 = &s;
    cout << s[0]<< endl;
    cout << solution.isNumeric(s)<< endl;
    cout << s[0]<< endl;
    return 0;
}
