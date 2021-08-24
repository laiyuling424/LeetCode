//
// Created by 赖於领 on 2021/8/18.
//


#include <iostream>
#include <queue>

using namespace std;

//路径总和

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

//    bool hasPathSum(TreeNode *root, int targetSum) {
//
//        if (!root) {
//            return false;
//        }
//
//        queue<TreeNode> node_queue;
//        queue<int> value_queue;
//
//        node_queue.push(*root);
//        value_queue.push(root->val);
//
//        int temp_sum;
//        TreeNode temp_node;
//        while (!node_queue.empty()) {
//
//            temp_node = node_queue.front();
//            temp_sum = value_queue.front();
//
//            if (temp_node.left == nullptr && temp_node.right == nullptr) {
//                if (temp_sum == targetSum) {
//                    return true;
//                }
//                continue;
//            }
//
//            if (temp_node.left) {
//                node_queue.push(*temp_node.left);
//                value_queue.push(temp_node.left->val);
//            }
//
//
//            if (temp_node.right) {
//                node_queue.push(*temp_node.right);
//                value_queue.push(temp_node.right->val);
//            }
//
//            value_queue.pop();
//            node_queue.pop();
//
//        }
//
//        return false;
//    }

    bool hasPathSum(TreeNode *root, int targetSum) {

        if (!root) {
            return false;
        }

        queue<TreeNode> node_queue;
        queue<int> value_queue;

        node_queue.push(*root);
        value_queue.push(root->val);

        int temp_sum;
        TreeNode temp_node;
        while (!node_queue.empty()) {

            temp_node = node_queue.front();
            temp_sum = value_queue.front();

            //要写在前面 写在最下面有可能会执行不到
            value_queue.pop();
            node_queue.pop();

            if (temp_node.left == nullptr && temp_node.right == nullptr) {
                if (temp_sum == targetSum) {
                    return true;
                }
                continue;
            }

            if (temp_node.left) {
                node_queue.push(*temp_node.left);
                value_queue.push(temp_node.left->val + temp_sum);
            }


            if (temp_node.right) {
                node_queue.push(*temp_node.right);
                value_queue.push(temp_node.right->val + temp_sum);
            }



        }

        return false;
    }

};