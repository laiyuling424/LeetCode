//
// Created by 赖於领 on 2021/8/18.
//

#include <vector>
#include <iostream>
#include <queue>

using namespace std;


//二叉树的层序遍历


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
    vector<vector<int>> levelOrder(TreeNode *root) {

        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        queue<TreeNode> _queue;
        _queue.push(*root);
        TreeNode tempNode;
        int level_size;
        while (!_queue.empty()) {
            cout << "-------------" << endl;
            vector<int> temp;
            level_size = _queue.size();
            for (int i = 0; i < level_size; ++i) {
                tempNode = _queue.front();
                temp.push_back(tempNode.val);
//                cout << tempNode.val;
                if (tempNode.left) {
                    _queue.push(*tempNode.left);
                }
                if (tempNode.right) {
                    _queue.push(*tempNode.right);
                }
                _queue.pop();
            }
            result.push_back(temp);
            cout << "" << endl;
        }
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
//    solution->levelOrder(node1);
//    return 0;
//}