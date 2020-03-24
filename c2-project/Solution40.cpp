//
// Created by 陈高杰 on 2020/2/9.
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
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(k>input.size() || input.empty()|| k<=0){
            return res;
        }
        //升序队列
//        priority_queue <int,vector<int>,greater<int> > q;
        //降序队列(大顶堆)
        priority_queue <int,vector<int>,less<int> >q;
        for (int i = 0; i < input.size(); ++i) {
            int temp = input[i];
//            cout<<temp;
            if(q.size()>=k){
                int q_min = q.top();
                if(temp < q_min){
                    q.pop();
                    q.push(temp);
                }
            }
            else{
                q.push(temp);
            }
        }
        while (!q.empty())
        {
            int x= q.top();
//            cout << x;
            res.push_back(x);
            q.pop();
        }
        return res;
    }
};

//int main()
//{
//    vector<int> s = {4,5,1,6,2,7,3,8};
//    Solution solution;
//    vector<int>  output1;
//    output1 = solution.GetLeastNumbers_Solution(s,4);
////    cout << output1<< endl;
////    vector<int>  output1 = {1,2,3,4};
//    for (int i = 0; i < output1.size(); ++i) {
//        cout << output1[i] ;
//        cout << " "<< endl;
//    }
//    system("PAUSE");
//    return 0;
//}