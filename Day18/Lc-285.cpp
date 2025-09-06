class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ = nullptr;
        while (root) {
            if (p->val < root->val) {
                succ = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return succ;
    }
};
