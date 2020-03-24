//
// Created by 陈高杰 on 2020/2/11.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<=0){
            return 0;
        }
        int num = 0;
        for (int i = 1; i <= n ; i *=10) {
            int div = i*10;
            int k = n%div;
            int c = 0;
            if(k>2*i-1){
                c = i;
            }
            else if (k<i){
                c = 0;
            }
            else{
                c = k-i+1;
            }
            num += (n/div)*i+c;
        }
        return num;
    }
};
//
//int main(){
//    int l = 12;
//    Solution solution;
//    int x = solution.NumberOf1Between1AndN_Solution(l);
//    cout << x<< endl;
//    system("PAUSE");
//    return 0;
//
//}
