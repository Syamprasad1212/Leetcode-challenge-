class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth=0;
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
            {
                int sz=q.size();
                for(int i=0;i<sz;i++)
                    {
                        TreeNode*node=q.front();
                        q.pop();
                        if(node->left)
                        {
                            q.push(node->left);
                        }
                        if(node->right)
                        {
                            q.push(node->right);
                        }
                    }
                depth++;
            }
        return depth;
    }
};
