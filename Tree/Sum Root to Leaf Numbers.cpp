class Solution {
    int ans=0;
    void sumNumbersHelper(TreeNode* root,int sum){
        if(root==NULL)
            return;
        sum=sum*10 + root->val;
        if(root->left==NULL && root->right==NULL){
            ans+=sum;
            return;
        }
        if(root->left)
            sumNumbersHelper(root->left,sum);
        if(root->right)
            sumNumbersHelper(root->right,sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        sumNumbersHelper(root,0);
        return ans;
    }
};
