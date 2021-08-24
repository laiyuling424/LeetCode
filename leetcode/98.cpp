//
// Created by 赖於领 on 2021/8/21.
//


#include <iostream>
#include <queue>
#include <stack>

using namespace std;

//验证二叉搜索树

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//这个思路有问题只考虑了父子结点的关系，没有考虑其他的
//中序遍历 和
//
// 官方解题 和我思路一样 考虑了左边结点小于上辈节点  右边结点大于上辈节点

//class Solution {
//public:
//    bool isValidBST(TreeNode *root) {
//        if (!root) {
//            return true;
//        }
//
//        if (root->right && root->left) {
//            if (root->left->val >= root->val) {
//                return false;
//            } else if (root->right->val <= root->val) {
//                return false;
//            } else {
//                return isValidBST(root->left) && isValidBST(root->right);
//            }
//        } else if (root->left) {
//            if (root->left->val >= root->val) {
//                return false;
//            } else {
//                return isValidBST(root->left);
//            }
//        } else if (root->right) {
//            if (root->right->val <= root->val) {
//                return false;
//            } else {
//                return isValidBST(root->right);
//            }
//        } else {
//            return true;
//        }
//    }
//};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> stack;
        long long inorder = (long long) INT_MIN - 1;

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
            if (root->val <= inorder) {
                return false;
            }
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};

//int main() {
//
//
//    Solution *solution = new Solution();
//    TreeNode *node5 = new TreeNode(7);
//    TreeNode *node4 = new TreeNode(3);
//    TreeNode *node3 = new TreeNode(6, node4, node5);
//    TreeNode *node2 = new TreeNode(4);
//    TreeNode *node1 = new TreeNode(5, node2, node3);
//    solution->isValidBST(node1);
//
//
//    return 0;
//}