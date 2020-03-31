//
// Created by 陈高杰 on 2020/2/13.
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
    int GetTranslationCountDetail(const string& number){
        int count_all = 0;
        int length = number.size();
//        cout << length<< endl;
        int* counts = new int[length];
        for (int i = length-1; i >=0; --i) {
            int count = 0;
            if(i == length-1)
                count = 1;
            else
                count = counts[i+1];
            if(i<length-1){
                int digit1 = number[i]-'0';
                int digit2 = number[i+1]-'0';
                int converted = digit1*10 +digit2;
                if(converted>=10 && converted<=25) {
                    if (i < length - 2)
                        count += counts[i + 2];
                    else
                        count += 1;
                }
            }
            counts[i] = count;
        }
        count_all = counts[0];
        delete[] counts;
        return count_all;
    }
public:
    int GetTranslationCount(int number){
        if(number<0)
            return 0;
        string str_number  = to_string(number);
        return GetTranslationCountDetail(str_number);
    }
};

//int main(){
//    int num = 12258;
//    Solution solution;
//    int x = solution.GetTranslationCount(num);
//    cout << x<< endl;
//    system("PAUSE");
//    return 0;
//
//}