class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return dfs(root->left,root->right);
            }
    bool dfs(TreeNode* left, TreeNode* right) {
        if(!left&&!right)
        {
            return true;
        }
        if(!left||!right) return false;
        if(left->val!=right->val)
        {
            return false;
        }
        return dfs(left->left,right->right)&&dfs(left->right,right->left);
    }
};
