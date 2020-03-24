//
// Created by 陈高杰 on 2020/2/16.
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

class Solution
{
private:
    string s;
    map<char,int> mp;
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        s = s+ch;
        mp[ch]++;
//        for (int i = 0; i < s.size(); ++i) {
//            cout<< s[i];
//        }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            if(mp[s[i]]==1)
                return s[i];
        }
        return '#';
    }

};

//int main(){
//    string l = "abaccdeff";
//    Solution solution;
//    for (int i = 0; i < l.size(); ++i) {
//        solution.Insert(l[i]);
//        cout<<endl;
//    }
//    char x = solution.FirstAppearingOnce();
//    cout<< x<<endl;
//    system("PAUSE");
//    return 0;
//}