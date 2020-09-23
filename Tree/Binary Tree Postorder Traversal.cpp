class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        stack<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            TreeNode* current=pendingNodes.top();
            pendingNodes.pop();
            if(current->left)
                pendingNodes.push(current->left);
            if(current->right)
                pendingNodes.push(current->right);
            ans.push_back(current->val);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
