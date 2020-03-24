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

class Solution {
public:
    int InversePairCore(vector<int> &data,int* &copy,int start, int end) {
        if(start == end){
            copy[start]=data[start];
            return 0;
        }
        int length = (end-start)/2;
        int left = InversePairCore(data,copy,start,start+length)%1000000007;;
        int right = InversePairCore(data,copy,start+length+1,end)%1000000007;;
        int p1 = start+length;
        int p2 = end;
        int copyindex = end;
        int count = 0;
        while(p1>=start && p2>=start+length+1){
            if(data[p1]>data[p2]){
                copy[copyindex--] = data[p1--];
                count+= p2-start-length;
                if(count>=1000000007)//数值过大求余
                    count%=1000000007;
            }
            else{
                copy[copyindex--] = data[p2--];
            }
        }
        for (; p1 >= start; --p1) {
            copy[copyindex--] = data[p1];
        }
        for (; p2 >= start+length+1; --p2) {
            copy[copyindex--] = data[p2];
        }
        for (int i = start; i <= end; ++i) {
            data[i] = copy[i];
        }
        return (left+right+count)%1000000007;

    }
    int InversePairs(vector<int> data) {
        int length = data.size();
        if(data.empty() || length<=0){
            return 0;
        }
        int count = 0;
        int* copy = new int[length];
        for (int i = 0; i < length; ++i) {
            copy[i] = data[i];
        }
        count = InversePairCore(data,copy,0,length-1);
        delete[] copy;
//        return count;
        return count;
    }
};

//int main(){
//    vector<int> l = {7,5,6,4};
//    Solution solution;
//    int x = solution.InversePairs(l);
//    cout<< x<<endl;
//    system("PAUSE");
//    return 0;
//}
