class Solution {
public:
     int max_sum=INT_MIN;
    int max_gain(TreeNode* root){
        if(root==NULL)
            return 0;
        int left=max(max_gain(root->left),0);
        int right=max(max_gain(root->right),0);
        int new_price=root->val+left+right;
        max_sum=max(max_sum,new_price);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
};
