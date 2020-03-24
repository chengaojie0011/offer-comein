//
// Created by 陈高杰 on 2020/2/15.
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
    int FirstNotRepeatingChar(string str) {
        if(str.size()<=0|| str.empty())
            return -1;
        map<char, int> mp;
        for(int i = 0; i < str.size(); ++i)
            mp[str[i]]++;
        for(int i = 0; i < str.size(); ++i)
            if(mp[str[i]]==1)
                return i;
        return -1;
    }
};



//int main(){
//    string l = "abaccdeff";
//    Solution solution;
//    int x = solution.FirstNotRepeatingChar(l);
//    cout<< x<<endl;
//    system("PAUSE");
//    return 0;
//}