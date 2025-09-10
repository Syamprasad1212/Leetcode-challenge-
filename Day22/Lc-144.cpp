class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        preorder(root,res);
        return res;
    }
    void preorder(TreeNode* node, vector<int>&res)
    {
        if(!node)return;
        res.push_back(node->val);
        preorder(node->left,res);
        preorder(node->right,res);
    }
};
