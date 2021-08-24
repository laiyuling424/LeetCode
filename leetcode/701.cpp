//
// Created by 赖於领 on 2021/8/20.
//



//二叉搜索树中的插入操作
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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode *temp = root;
        while (temp) {

            if (temp->val > val) {
                if (temp->left) {
                    temp = temp->left;
                } else {
                    temp->left = new TreeNode(val);
                    break;
                }

            } else if (temp->val < val) {
                if (temp->right) {
                    temp = temp->right;
                } else {
                    temp->right = new TreeNode(val);
                    break;
                }
            }

        }
        return root;
    }
};

//int main() {
//
//
//    Solution *solution = new Solution();
//    TreeNode *node5 = new TreeNode(3);
//    TreeNode *node4 = new TreeNode(1);
//    TreeNode *node3 = new TreeNode(7);
//    TreeNode *node2 = new TreeNode(2, node4, node5);
//    TreeNode *node1 = new TreeNode(4, node2, node3);
//    solution->insertIntoBST(node1, 5);
//
//
//    return 0;
//}