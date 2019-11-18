//
// Created by 陈高杰 on 2019-11-18.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

class Solution1 {
private:
    bool isEven(int x){
        if((x&1)==0){
            return true;
        }
        else{
            return false;
        }
    }
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        int temp = 0;
        for(int i=0;i<len;++i){
            for (int j = array.size()-1; j >i; --j){
                if(!isEven(array[j]) && isEven(array[j-1])){
                    swap(array[j], array[j-1]);
//                    temp = array[j];
//                    array[j] = array[j-1];
//                    array[j-1] = temp;
                }
            }
        }
    }
};

class Solution {
private:
    bool isEven(int x){
        if((x&1)==0){
            return true;
        }
        else{
            return false;
        }
    }
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        int temp = 0;
        vector<int> array_temp;
        vector<int>::iterator i = array.begin();
        while (i!= array.end()){
            if(isEven(*i)){
                array_temp.push_back(*i);
                i = array.erase(i);
            }
            else{
                i++;
            }
        }
        vector<int>::iterator itb = array_temp.begin();
        vector<int>::iterator ite = array_temp.end();
        while(itb !=ite){
            array.push_back(*itb);
            itb++;
        }


    }
};

int main()
{

    Solution solution;
    vector<int> array = {1,2,3,4,5,6,7,8};
    solution.reOrderArray(array);
//    cout <<arra<< endl;
    return 0;
}
