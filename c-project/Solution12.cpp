//
// Created by 陈高杰 on 2019-11-07.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    bool a = false;
    bool pathfind(char* matrix, int rows, int cols, int i, int j, char* str,bool* isOk){
        if(*str=='\0'){
            a = true;
            return 0;
        }
        if(j!=0 && matrix[i*cols+j-1] == *str && isOk[i*cols+j-1] != true){
            isOk[i*cols+j-1] = true;
            cout<<i<<','<<j-1<<','<<*str<<endl;
            pathfind(matrix,rows,cols,i,j-1,str+1,isOk);
        }
        if(j!= cols-1 && matrix[i*cols+j+1] == *str && isOk[i*cols+j+1] != true){
            isOk[i*cols+j+1] = true;
            cout<<i<<','<<j+1<<','<<*str<<endl;
            pathfind(matrix,rows,cols,i,j+1,str+1,isOk);
        }
        if(i!=0 && matrix[(i-1)*cols+j] == *str && isOk[(i-1)*cols+j] != true){
            isOk[(i-1)*cols+j] = true;
            cout<<i-1<<','<<j<<','<<*str<<endl;
            pathfind(matrix,rows,cols,i-1,j,str+1,isOk);
        }
        if(i!=rows-1 && matrix[(i+1)*cols+j] == *str && isOk[(i+1)*cols+j] != true){
            isOk[(i+1)*cols+j] = true;
            cout<<i+1<<','<<j<<','<<*str<<endl;
            pathfind(matrix,rows,cols,i+1,j,str+1,isOk);
        }

        return false;
    }

public:
    bool hasPath(char* matrix, int rows, int cols, char* str){
        bool *isOk=new bool[rows*cols]();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(matrix[i*cols+j]==str[0]){
                    isOk[i*cols+j] = true;
                    cout<<i<<','<<j<<','<<*str<<endl;
                    pathfind(matrix,rows,cols,i,j,str+1,isOk);
                    //very importance!!!!!
                    isOk[i*cols+j] = false;
                    if(a==true){
                        return true;
                    }
                }
            }

        }
        return false;
    }


};


int main()
{
//    char matrix[] ="abtgcfcsjdea";
    char matrix[] ="ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
//    char* matrix = a;
//    char path[] ="bfcsgt";
    char path[] ="SGGFIECVAASABCEHJIGQEM";
//    char* matrix = a;
   Solution solution;
//    cout << path[1] << endl;
    cout << solution.hasPath(matrix,5,8,path) << endl;
    return 0;
}

