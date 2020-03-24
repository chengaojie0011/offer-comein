//
// Created by 陈高杰 on 2020/2/17.
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
    int GetNumberOfK(vector<int> data ,int k) {
        int length = data.size();
        int count =0;
        if(data.empty() || length<=0)
            return 0;
        int first = GetFirstOfK(data ,k,0,length-1);
        int last = GetLastOfK(data ,k,0,length-1);
        if(first>-1 && last>-1)
            count  = last - first +1;
        return count;
    }
    int GetFirstOfK(vector<int> data ,int k, int start, int end) {
        if(start>end)
            return -1;
        int mid = (end+start)/2;
        if(data[mid]==k){
            if((mid>0 && data[mid-1] !=k) ||mid ==0){
                return mid;
            }
            else{
                end = mid-1;
            }
        }
        else if(data[mid]<k){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        return GetFirstOfK(data ,k,start,end);
    }
    int GetLastOfK(vector<int> data ,int k, int start, int end) {
        if(start>end)
            return -1;
        int mid = (end+start)/2;
        if(data[mid]==k){
            if( (mid<data.size()-1 && data[mid+1] !=k) ||mid ==data.size()-1){
                return mid;
            }
            else{
                start = mid+1;
            }
        }
        else if(data[mid]<k){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        return GetLastOfK(data ,k,start,end);
    }
};

//int main(){
////    vector<int> l = {1,2,3,3,3,3,4,5};
//    vector<int> l = {1,3,3,3,4,5};
//    Solution solution;
//    int k = 2;
//    int x = solution.GetNumberOfK(l,k);
//    cout<< x<<endl;
//    system("PAUSE");
//    return 0;
//}