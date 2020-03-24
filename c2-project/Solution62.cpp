//
// Created by 陈高杰 on 2020/3/20.
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

class Solution1 {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1 || m<1)
            return -1;
        int last = 0;
        for (int i = 2; i <= n; ++i) {
            last = (last+m)%i;
        }
        return last;
    }
};

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1 || m<1)
            return -1;
        list<int> numbers;
        for (int i = 0; i < n; ++i) {
            numbers.push_back(i);
        }
        list<int>::iterator cur = numbers.begin();
        while(numbers.size()>1){
            for (int i = 0; i < m-1; ++i) {
                cur++;
                if(cur==numbers.end())
                    cur = numbers.begin();
            }
            cout<<"1:"<<(*cur)<<endl;
            cur++;
            list<int>::iterator next = cur;
//            cout<< *numbers.end();
            if(next==numbers.end())
                next = numbers.begin();
            cur--;
            numbers.erase(cur);
            cur = next;
            cout<<"2:"<<(*cur)<<endl;
        }
        return *cur;
    }
};

//int main(){
//    Solution solution;
//    int a = 5;
//    int b = 3;
//    int n1;
//    n1 = solution.LastRemaining_Solution(a,b);
////    for (int i = 0; i < n1.size(); ++i) {
////        cout<< n1[i];
////    }
//    cout<< n1;
//    system("PAUSE");
//    return 0;
//}