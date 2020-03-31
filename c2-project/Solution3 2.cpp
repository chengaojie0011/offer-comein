#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Solution3 {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    /*找出数组中重复的数字*/
    bool duplicate(int numbers[], int length, int* duplication) {
        if (numbers == nullptr || length == 0){
            return false;
        }
        for (int i = 0; i < length; i++){
            if (numbers[i] < 0 || numbers[i] >= length){
                return false;
            }
        }
        for (int i = 0; i < length; i++){
            while (numbers[i] != i){
                if (numbers[i] == numbers[numbers[i]]){
                    *duplication = numbers[i];
                    cout << *duplication << endl;
                    return true;
                }
                //int temp = numbers[i];
                //numbers[i] = numbers[temp];
                //numbers[temp] = temp;
                int temp = numbers[numbers[i]];
                numbers[numbers[i]] = numbers[i];
                numbers[i] = temp;

            }

        }
        return false;
    }
    /*不修改数组找出重复的数字*/
    int getDuplicate(int numbers[], int length, int* duplication) {
        if (numbers == nullptr || length == 0){
            return -1;
        }
        for (int i = 0; i < length; i++){
            if (numbers[i] < 0 || numbers[i] >= length){
                return -1;
            }
        }
        int start = 1;
        int end = length-1;
        while(start<=end){
            //相当于除2
            int middle = ((end-start)>>1)+start;
            int counts = getCount(numbers,length,start,middle);
            if(start == end){
                if(counts >1){
                    return start;
                }
                else{
                    return -1;
//                    break;
                }

            }
            if(counts>(middle-start+1)){
                end = middle;
            }
            else{
                start = middle+1;
            }
        }
        return -1;
    }

    int getCount(const int *number,int length,int start,int end){
        int count = 0;
        for(int i=0;i<=length-1;i++){
            if(number[i]>=start&&number[i]<=end){
                ++count;
            }
        }
        return count;
    }
};

int  cout_myname(int a){
	cout << a << endl;
    return 0;
}

//int main()
//{
//    int data[] = {2,3,1,0,2,5,3};
//    int data_len = sizeof(data) / sizeof(data[0]);
//    Solution3 solution;
//    int *data_sort= (data+1);
//    bool output;
//    output = solution.duplicate(data, data_len, data_sort);
//    int* data2 = data;
//    cout << "output of this topic is :"<<output << endl;
//    int a1 = 1994;
//    cout_myname(a1);
//    system("PAUSE");
//    return 0;
//}