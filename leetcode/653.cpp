//
// Created by 赖於领 on 2021/8/21.
//

#include <set>
#include <iostream>

using namespace std;


//两数之和 IV - 输入 BST
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
    bool findTarget(TreeNode *root, int k, set<int> *_set) {
        if (!root) {
            return false;
        }
        if (_set->find(k - root->val) != _set->end()) {
            return true;
        }
        _set->insert(root->val);
        return findTarget(root->left, k, _set) || findTarget(root->right, k, _set);
    }

    bool findTarget(TreeNode *root, int k) {
        set<int> _set;
        return findTarget(root, k, &_set);
    }
};

//int main() {
//
////    set<int> _set;
////    _set.insert(1);
////    _set.insert(2);
////    _set.insert(3);
////    _set.insert(4);
////    _set.insert(5);
////
////    cout << *_set.find(90) << endl;
//    Solution *solution = new Solution();
//    TreeNode *node7 = new TreeNode(7);
//    TreeNode *node5 = new TreeNode(4);
//    TreeNode *node4 = new TreeNode(2);
//    TreeNode *node3 = new TreeNode(6, NULL, node7);
//    TreeNode *node2 = new TreeNode(3, node4, node5);
//    TreeNode *node1 = new TreeNode(5, node2, node3);
//    cout << solution->findTarget(node1, 28) << endl;
//
//    return 0;
//}