//
// Created by 赖於领 on 2021/8/20.
//

#include <iostream>
#include <queue>

using namespace std;


//二叉搜索树中的搜索

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
    TreeNode *searchBST(TreeNode *root, int val) {
        if (!root) {
            return NULL;
        }

        queue<TreeNode *> node_queue;
        node_queue.push(root);
        TreeNode *temp;
        while (!node_queue.empty()) {
            temp = node_queue.front();
            if (temp->val == val) {
                return temp;
            } else {
                node_queue.pop();
                if (temp->left)
                node_queue.push(temp->left);
                if (temp->right)
                node_queue.push(temp->right);
            }
        }

        return NULL;
    }
};