//
// Created by 陈高杰 on 2020/3/25.
//
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>
#include <string>
#include <complex>
//#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    long long getMin(vector<vector<int> > matrix,int n){
        long long res;
        vector<int> dp_min(3,0);
        //magtrix的第i列
        for (int i = 1; i < n; ++i) {
            vector<int> dp(3,0);
            for (int j = 0; j < 3; ++j) {            //bn的三个
//                cout<<matrix[j][i]<<endl;
//                cout<<matrix[0][i-1]<<endl;
//                cout<<abs(matrix[j][i]-matrix[0][i-1])<<endl;
                dp[j] = abs(matrix[j][i]-matrix[0][i-1])+dp_min[0];
//                cout<<dp[j]<<endl;
                for (int k = 0; k < 3; ++k) {                //bn-1的三个数
                    int temp = abs(matrix[j][i]-matrix[k][i-1])+dp_min[k];
                    if(temp<dp[j])
                        dp[j] = temp;
                }
            }
            dp_min = move(dp);
        }
//        for (int l = 0; l < 3; ++l) {
//            cout<<dp_min[l]<<endl;
//        }
        res = *(min_element(dp_min.begin(),dp_min.end()));
        return res;
    }
};

int main() {
    int n;
    cin>> n;
    vector<vector<int> > matrix(3,vector<int> (n,0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>matrix[i][j];
        }
    }
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cout<<matrix[i][j];
//        }
//        cout<<endl;
//    }
    Solution solution;
    long long res = solution.getMin(matrix,n);

    cout<<res<<endl;
    return 0;

}
