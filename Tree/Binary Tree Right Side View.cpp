class Solution {
public:
    vector<int> rightSideView(TreeNode* root){
        vector<int> ans;
        if(!root)
            return ans;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            int size=pendingNodes.size();
            while(size--){
                TreeNode* curr=pendingNodes.front();
                pendingNodes.pop();
                if(curr->left)
                    pendingNodes.push(curr->left);
                if(curr->right)
                    pendingNodes.push(curr->right);
                if(size==0)
                    ans.push_back(curr->val);
            }
        }
        return ans;
    }
};
