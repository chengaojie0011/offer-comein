//
// Created by 陈高杰 on 2019-11-15.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str == nullptr || pattern == nullptr){
            return false;
        }
        else if(*str =='\0' && *pattern =='\0'){
            return true;
        }
        else if(*str !='\0' && *pattern =='\0'){
            return false;
        }
        else if(*str =='\0' && *pattern !='\0'){
            if(pattern[1]=='*')
                return match(str,pattern+2);
            return false;
        }
        else{
            if(pattern[1]=='*'){
                if(pattern[0]!='.' && str[0]!=pattern[0]){
                    return match(str,pattern+2);
                }
                else{
                    if(match(str,pattern+2)||match(str+1,pattern+2)||match(str+1,pattern)){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
            else{
                if(str[0] == pattern[0] || pattern[0]=='.'){
                    return match(str+1,pattern+1);
                }
                else{
                    return false;
                };
            }
        }
        return false;
    }
};

int main()
{

    Solution solution;
//    char* str = new char[10]();
    char s[] = "aaa";
//    for (int i = 0; i < 10; ++i) {
////        str[i]='o';
//        cout << str[i]<< endl;
//
//    }
//    cout << strlen(s)<< endl;
//    cout << *(s+3)<< endl;
    char p[] = "ab*c*a";

    cout << solution.match(s,p)<< endl;
    return 0;
}






