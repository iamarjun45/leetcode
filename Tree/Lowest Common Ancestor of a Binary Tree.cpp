class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return root;
        if(root->val==p->val || root->val==q->val)
            return root;
        TreeNode* leftAns=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns=lowestCommonAncestor(root->right,p,q);
        if(leftAns && rightAns)
            return root;
        else if(leftAns)
            return leftAns;
        else
            return rightAns;
    }
};


