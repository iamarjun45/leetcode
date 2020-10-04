class Solution {
    public:
    int ans=INT_MAX;
    void dfs(TreeNode* root,int level){
         if(root==NULL)
             return;
        if(root->left==NULL && root->right==NULL){
             ans=min(ans,level);
             return;
        }
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        dfs(root,1);
        return ans;   
    }
};
