//
// Created by 赖於领 on 2021/8/18.
//




//对称二叉树

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
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left && right) {
            return (left->val == right->val) && isSymmetric(left->left, right->right) &&
                   isSymmetric(left->right, right->left);
        }

        if (!left && !right) {
            return true;
        }
        return false;
    }

    bool isSymmetric(TreeNode *root) {
        return isSymmetric(root, root);
    }
};
