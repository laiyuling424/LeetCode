//
// Created by 赖於领 on 2021/8/24.
//

#include <set>
#include <iostream>
#include <vector>

using namespace std;

//二叉搜索树的最近公共祖先

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//class Solution {
//public:
//    void lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *parent) {
//        if (!root) {
//            return;
//        }
//
//
//        if (root->val == p->val && q->val == 0) {
//            parent = root;
//            return;
//        } else if (root->val == p->val) {
//            //向上
//            p->val = 0;
//        }
//
//        if (root->val == q->val && p->val == 0) {
//            parent = root;
//            return;
//        } else if (root->val == q->val) {
//            //向上
//            q->val = 0;
//        }
//
//        if (parent) {
//            return;
//        }
//
//        lowestCommonAncestor(root->left, p, q, parent);
//        lowestCommonAncestor(root->right, p, q, parent);
//    }
//
//
//    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
//        TreeNode *parent;
//        lowestCommonAncestor(root, p, q, parent);
//        return parent;
//    }
//};


class Solution {
public:
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
        vector<TreeNode*> path;
        TreeNode* node = root;
        while (node != target) {
            path.push_back(node);
            if (target->val < node->val) {
                node = node->left;
            }
            else {
                node = node->right;
            }
        }
        path.push_back(node);
        return path;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p = getPath(root, p);
        vector<TreeNode*> path_q = getPath(root, q);
        TreeNode* ancestor;
        for (int i = 0; i < path_p.size() && i < path_q.size(); ++i) {
            if (path_p[i] == path_q[i]) {
                ancestor = path_p[i];
            }
            else {
                break;
            }
        }
        return ancestor;
    }
};


//int main() {
//
//    // [6,2,8,0,4,7,9,null,null,3,5]
//    Solution *solution = new Solution();
//    TreeNode *node10 = new TreeNode(6);
//    TreeNode *node9 = new TreeNode(3);
//    TreeNode *node8 = new TreeNode(10);
//    TreeNode *node7 = new TreeNode(8);
//    TreeNode *node5 = new TreeNode(4, node9, node10);
//    TreeNode *node4 = new TreeNode(0);
//    TreeNode *node3 = new TreeNode(9, node7, node8);
//    TreeNode *node2 = new TreeNode(2, node4, node5);
//    TreeNode *node1 = new TreeNode(7, node2, node3);
//
//    TreeNode *node11 = new TreeNode(5);
//    cout << solution->lowestCommonAncestor(node1, node9,node11)->val << endl;
//
//    return 0;
//}