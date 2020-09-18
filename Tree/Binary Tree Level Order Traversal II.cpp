class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        vector<int> small;
        while(pendingNodes.size()!=0){
            TreeNode* front=pendingNodes.front();
            pendingNodes.pop();
            if(front==NULL){
                ans.push_back(small);
                small=vector<int>();
                if(pendingNodes.size()==0)
                    break;
                pendingNodes.push(NULL);
            }else{
                small.push_back(front->val);
                if(front->left)
                    pendingNodes.push(front->left);
                if(front->right)
                    pendingNodes.push(front->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
