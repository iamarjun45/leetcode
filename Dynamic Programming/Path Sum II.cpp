class Solution {
    vector<vector<int>> ans;
    void dfs(TreeNode* root,int sum,vector<int> curr){
        if(root==NULL)
            return;
        curr.push_back(root->val);
        sum-=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==0)
                ans.push_back(curr);
        }
        if(root->left)
            dfs(root->left,sum,curr);
        if(root->right)
            dfs(root->right,sum,curr);
        curr.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> curr;
        dfs(root,sum,curr);
        return ans;
    }
};
