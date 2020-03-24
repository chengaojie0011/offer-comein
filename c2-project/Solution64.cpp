//
// Created by 陈高杰 on 2020/3/22.
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
    int Sum_Solution(int n) {
        int a = n && (n+= Sum_Solution(n-1));
        return n;
    }
};

class Solution2 {
public:
    int Sum_Solution(int n) {
        bool a[n][n+1];
        return sizeof(a)>>1;
    }
};

class Solution {
public:
    int Sum_Solution(int n) {
        return (int) (pow(n,2)+n)>>1;
    }
};
//
//int main(){
//    Solution solution;
//    int a = 4;
//    int n1;
//    n1 = solution.Sum_Solution(a );
//    cout<< n1<<endl;
//    system("PAUSE");
//    return 0;
//}
