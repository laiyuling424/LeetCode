//
// Created by 赖於领 on 2021/8/18.
//

#include <vector>
#include <iostream>

using namespace std;


//二叉树的前序遍历


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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

    void preorderTraversal(TreeNode *root, vector<int> *result) {
        if (!root) {
            return;
        }
        cout << root->val << endl;
        result->push_back(root->val);
        preorderTraversal(root->left, result);
        preorderTraversal(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;

        preorderTraversal(root, &result);

        return result;
    }

    void levelOrder(TreeNode *root, vector<vector<int>> *result,int level) {
        if (!root) {
            return;
        }
        cout << root->val << endl;
        vector<int> temp_vector = result->at(level-1);
//        if ()


    }

    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;

        levelOrder(root, &result,1);

        return result;
    }
};

//int main() {
//    Solution *solution = new Solution();
//    TreeNode *node5 = new TreeNode(5);
//    TreeNode *node4 = new TreeNode(4);
//    TreeNode *node3 = new TreeNode(3);
//    TreeNode *node2 = new TreeNode(2, node4, node5);
//    TreeNode *node1 = new TreeNode(1, node2, node3);
//    solution->preorderTraversal(node1);
//    return 0;
//}