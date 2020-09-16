class Solution {
public:
    TreeNode *prev=NULL,*fir=NULL,*sec=NULL;
    void inorder(TreeNode* root){
        if(root==NULL)
        return;
        inorder(root->left);
        if(prev && !fir && prev->val>root->val)
            fir=prev;
        if(fir && prev && prev->val>root->val)
            sec=root;
        prev=root;   
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
       if(root==NULL)
       return;
       inorder(root);
       swap(fir->val,sec->val); 
    }
};
