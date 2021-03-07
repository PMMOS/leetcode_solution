// lee938.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

int main()
{
    Solution s;
    TreeNode* node_3 = new TreeNode(3);
    TreeNode* node_7 = new TreeNode(7);
    TreeNode* node_18 = new TreeNode(18);
    TreeNode* node_5 = new TreeNode(5, node_3, node_7);
    TreeNode* node_15 = new TreeNode(15, nullptr, node_18);
    TreeNode* node_10 = new TreeNode(10, node_5, node_15);
    cout << s.rangeSumBST(node_10, 7, 15);
    return 0;
}
