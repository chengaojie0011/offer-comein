//
// Created by 陈高杰 on 2020/2/8.
//
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    char* Serialize(TreeNode *root) {
        if(root == nullptr)
            return nullptr;
        string str;
        Serialize(root, str);
        char *ret = new char[str.length() + 1];
        int i;
        for(i = 0; i < str.length(); i++){
            ret[i] = str[i];
        }
        ret[i] = '\0';
        return ret;
    }
    void Serialize(TreeNode *root, string& str){
        if(root == nullptr){
            str += '#';
            str += ',';
            return;
        }
        string r = to_string(root->val);
        str += r;
        str += ',';
        Serialize(root->left, str);
        Serialize(root->right, str);
    }

    TreeNode* Deserialize(char *str) {
        if(str == nullptr)
            return nullptr;
        TreeNode *ret = Deserialize(&str);
        return ret;
    }

    TreeNode* Deserialize(char **str){//由于递归时，会不断的向后读取字符串
        if(**str == '#'){  //所以一定要用**str,
            ++(*str);         //以保证得到递归后指针str指向未被读取的字符
            ++(*str);
            return nullptr;
        }

        int num = 0;
        while(**str != '\0' && **str != ','){
            num = num*10 + ((**str) - '0');
            ++(*str);
        }
//        while(num) {
//            // 整数转字符串: +'0'
//            temp[i++] = num % 10 + '0';
//            num = num / 10;
//        }

        TreeNode *root = new TreeNode(num);
        if(**str == '\0' || *str == nullptr)
            return root;
        else
            (*str)++;
//            (*str)++;
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        return root;
    }
};
//
//int main()
//{
//    TreeNode TreeNode1 = TreeNode(1);
//    TreeNode TreeNode2 = TreeNode(2);
//    TreeNode TreeNode3 = TreeNode(3);
//    TreeNode TreeNode4 = TreeNode(4);
//    TreeNode TreeNode5 = TreeNode(5);
//    TreeNode TreeNode6 = TreeNode(6);
//
//    TreeNode1.left = &TreeNode2;
//    TreeNode1.right = &TreeNode3;
//    TreeNode2.left = &TreeNode4;
////    TreeNode2.right = &TreeNode5;
//    TreeNode3.left = &TreeNode5;
//    TreeNode3.right = &TreeNode6;
//
//    Solution solution;
//    char* output1;
//    TreeNode*  output;
//    output1 = solution.Serialize(&TreeNode1);
//    char* pnode1 = output1;
//    int i= 0;
////    cout << pnode1[2]  << endl;
//    while(i<strlen(pnode1)){
//        cout << pnode1[i] ; //<< endl;
//        i++;
//    }
////    TreeNode* pnode = output;
////    TreeNode* pnode = &TreeNode11;
////    while(pnode != nullptr){
////        cout << pnode->val << endl;
////        pnode = pnode->right;
////    }
//
//    system("PAUSE");
//    return 0;
//}