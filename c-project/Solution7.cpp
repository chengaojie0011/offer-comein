#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {

      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution2 {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int n = pre.size();
        int m = vin.size();
        if(n!=m || n == 0)
            return NULL;
        return construct(pre, vin, 0, n-1, 0, m-1);
    }

    TreeNode* construct(vector<int>& pre, vector<int>& vin, int l1, int r1, int l2, int r2)
    {
        TreeNode* root = new TreeNode(pre[l1]);
        if(r1 == l1)
        {
            return root;
        }
        int val = pre[l1];
        int index;
        for(index = l2; index <= r2; index ++)
        {
            if(vin[index] == val)
                break;
        }
        int left_tree_len  = index - l2;
        int right_tree_len = r2 - index;
        if(left_tree_len > 0)
            root->left = construct(pre, vin, l1+1, l1+left_tree_len, l2, index-1);
        if(right_tree_len >0 )
            root->right = construct(pre, vin, l1+1+left_tree_len, r1, index+1, r2);
        return root;
    }
};
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int pre_size = pre.size();
        int vin_size = vin.size();
        if(pre_size == 0 || pre_size != vin_size || vin_size ==0){
            return nullptr;
        }
        return construct(pre,vin,0,pre_size-1,0,vin_size-1);
    }
    TreeNode* construct(vector<int> pre, vector<int> vin, int l1,int r1, int l2, int r2) {
        TreeNode* root = new TreeNode(pre[l1]);
        if(l1==r1){
            return root;
        }
        int root_value = pre[l1];
        int index=0;
        for (int i = l2; i <= r2; ++i) {
            if(vin[i]==root_value) {
                index = i;
                break;
            }
        }
        int left_tree_size = index-l2;
        int right_tree_size = r2-index;
        if(left_tree_size>0)
            root->left = construct(pre,vin,l1+1,l1+left_tree_size,l2,index-1);

        if(right_tree_size>0)
            root->right = construct(pre,vin,l1+left_tree_size+1,r1,index+1,r2);
        return root;
    }
};

 int main()
 {
    vector <int> pre = {1,2,4,7,3,5,6,8};
    vector <int> vin = {4,7,2,1,5,3,8,6};
    cout << pre[0] << endl;
    Solution solution;
    TreeNode* tree;
    tree = solution.reConstructBinaryTree(pre,vin);


 	return 0;
 }




