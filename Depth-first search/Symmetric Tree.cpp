class Solution {
    bool isSymmetric(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL)
            return true;
        if(root1==NULL || root2==NULL || root1->val!=root2->val)
            return false;
        return isSymmetric(root1->right,root2->left) && isSymmetric(root1->left,root2->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
       return isSymmetric(root,root);
    }
};
