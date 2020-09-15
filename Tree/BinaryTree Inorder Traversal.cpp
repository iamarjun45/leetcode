class Solution {
    void inorderTraversalHelper(TreeNode* root,vector<int>& ans){
        if(root==NULL)
            return;
        inorderTraversalHelper(root->left,ans);
        ans.push_back(root->val);
        inorderTraversalHelper(root->right,ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderTraversalHelper(root,ans);
        return ans;
    }
};
