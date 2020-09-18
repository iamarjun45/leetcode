class Solution {
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left)-height(root->right))<=1;
    }
};
