//
// Created by 陈高杰 on 2020/3/24.
//

#ifndef C2_PROJECT_MAIN_H
#define C2_PROJECT_MAIN_H

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

using namespace std;

enum Status1 {
    valid1 = 0, invalid1
};

int g_status1 = invalid1;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x):
            val(x), next(NULL) {
    }
};
#endif //C2_PROJECT_MAIN_H
