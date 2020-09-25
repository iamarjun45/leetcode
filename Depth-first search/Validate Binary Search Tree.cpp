class Solution {
    bool isValidBST(TreeNode* root,long long left,long long right){
        if(root==NULL)
            return true;
        if(root->val<left || root->val>right)
            return false;
        return isValidBST(root->left,left,(long long)root->val-1) && isValidBST(root->right,(long long)root->val+1,right);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
};
