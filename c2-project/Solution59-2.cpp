//
// Created by 陈高杰 on 2020/2/20.
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


// 送入大的值则吧之前比起小的都替换了
// 不然就加进去，因为之后可能会弹出最大值
class QueueMax {
public:
    deque<int> data;
    deque<int> data_max;
    int max(){
        return data_max[0];
    }
    void push_back(int num){
        data.push_back(num);
        while(!data_max.empty() && data_max[-1]<=num)
            data_max.pop_back();
        data_max.push_back(num);
        return;
    }
    int pop_front(){
        if(data[0]==data_max[0])
            data_max.pop_front();
        int temp = data.front();
        data.pop_front();
        return temp;
    }
};

//int main(){
//    QueueMax q;
//
////    for (int i = 0; i < n1.size(); ++i) {
////        cout<< n1[i];
////    }
//    system("PAUSE");
//    return 0;
//}
