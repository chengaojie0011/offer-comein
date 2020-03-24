//
// Created by 陈高杰 on 2020/2/13.
//
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
void num2str(int a){
    //1
    string res;
    stringstream ss;
    ss << a;
    ss >> res;//或者 res = ss.str();
    cout<<res<<endl;
    //2
    string res2 = to_string(a);
    cout<<res2<<endl;

};
//int main(){
//    int a = 123;
//    num2str(a);
//    return 0;
//}
