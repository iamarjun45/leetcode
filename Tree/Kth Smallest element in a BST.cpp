class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> pendingNodes;
        while(true){
            while(root!=NULL){
                pendingNodes.push(root);
                root=root->left;
            }
            root=pendingNodes.top();
            pendingNodes.pop();
            if(!(--k))
                return root->val;
            root=root->right;
        }
    }
};


