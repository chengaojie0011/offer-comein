//
// Created by 陈高杰 on 2020/3/23.
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
#include <list>

using namespace std;

enum Status {
    valid = 0, invalid
};

int g_status = invalid;

class Solution {
public:
    int StrToInt(string str) {
        int len = str.size(), s= 1;
        if(str.empty()){
            g_status = valid;
            return 0;
        }
        if(str[0] == '-') s = -1;
        long int res = 0;
        for (int i = (str[0]=='+'||str[0]=='-')?1:0; i <len; ++i) {
            if(str[i]<'0'||str[i]>'9') {
                g_status = valid;
                return 0;
            }
            res = res*10 + str[i]-'0';
            //左移一位*2，<<1+<<3=*（2+8）=*10
//            res = (res << 1) + (res << 3) + (str[i] & 0xf);
        }

        if(res*s >= -2147483648 && res*s <= 2147483647){ //int [-2^31,2^31-1]
            return res*s;
        }else{
            g_status = valid;
            return 0;
        }
    }
};


//int main(){
//    Solution solution;
//    string l = "-2147483649";
//    int n = 0;
//    n = solution.StrToInt(l);
//    cout<<n<<endl;
//    system("PAUSE");
//    return 0 ;
//}