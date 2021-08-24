//
// Created by 赖於领 on 2021/8/21.
//


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class AVL_Tree {
private:
    int val;
    TreeNode *left;
    TreeNode *right;
private:
    TreeNode* L(TreeNode *node){

        TreeNode *right_node = node->right;
        if(right_node->left){
            node->right = right_node->left;
        }
        right_node->left = node;
        return right_node;

    }
    TreeNode* R(TreeNode *node){
        TreeNode *left_node = node->left;
        if(left_node->right){
            node->left = left_node->right;
        }
        left_node->right = node;
        return left_node;
    }
    void LL(TreeNode *node){

    };
    void RR(TreeNode *node){

    };
    void LR(TreeNode *node){

    }
    void RL(TreeNode *node){

    }

public:
    void insert(TreeNode *node);

    void erase(TreeNode *node);

    TreeNode find(int val);
};
