#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <sstream>
#include <map>
#include <list>
#include "cmake-build-debug/main.h"

using namespace std;

int main()
{
    TreeNode t1 = TreeNode(10);
    TreeNode t2 = TreeNode(5);
    TreeNode t3 = TreeNode(12);
    TreeNode t4 = TreeNode(4);
    TreeNode t5 = TreeNode(7);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
//    cout << t1.right->val << endl;
//    Solution solution;
//    vector<vector<int> > output;
//    output = solution.FindPath(&t1,22);
//    cout << "output:" << output<< endl;
    system("PAUSE");
    return 0;
}