class Solution {
public:
    bool hasPathSumHelper(TreeNode* root, int sum) {
        if(root->left==NULL && root->right==NULL){
            if(sum==root->val)
                return true;
            else
                return false;
        }
        bool ans=false;
        if(root->left)
            ans|=hasPathSumHelper(root->left,sum - root->val);
        if(root->right)
            ans|=hasPathSumHelper(root->right,sum - root->val);
        return ans;
    }
    bool hasPathSum(TreeNode* root,int sum){
        if(root==NULL)
            return false;
        return hasPathSumHelper(root,sum);
    }
};
