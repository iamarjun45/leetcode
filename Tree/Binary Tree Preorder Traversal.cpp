class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* topmost=s.top();
            s.pop();
            ans.push_back(topmost->val);
            if(topmost->right)
                s.push(topmost->right);
            if(topmost->left)
                s.push(topmost->left);
        }
        return ans;
    }
};
