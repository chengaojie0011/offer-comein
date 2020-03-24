//
// Created by 陈高杰 on 2019-11-06.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    int minInOrder(vector<int> rotateArray,int left,int right) {
        for (int i = left; i <=right; ++i) {
            if(rotateArray[i]>rotateArray[i+1]){
                return rotateArray[i+1];
            }
        }
        return 0;

    }
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
        if(length<=0){
            return 0;
        }
        int left = 0;
        int right = length-1;
        int mid = 0;
        while(rotateArray[left]>=rotateArray[right]){
            if((right-left)==1){
                mid = right;
                break;
            }
            mid = left+(right-left)/2;
            if(rotateArray[mid] == rotateArray[right] && rotateArray[mid]==rotateArray[left]){
                return minInOrder(rotateArray,left,right);
            }
            if(rotateArray[left]<=rotateArray[mid]){
                left = mid;
            }
            else if(rotateArray[right]>=rotateArray[mid]){
                right = mid;
            }
        }
        return rotateArray[mid];
    }
};

//int main()
//{
//
//    vector <int> vec1 = {3,4,5,1,2};
//    vector <int> vec2 = {1,1,1,0,1};
//    vector <int> vec3 = {1,0,1,1,1};
//    Solution solution;
//    cout << solution.minNumberInRotateArray(vec3) << endl;
//    return 0;
//}
