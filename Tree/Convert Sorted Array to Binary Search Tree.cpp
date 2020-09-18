class Solution {
    TreeNode* sortedArrayToBST(vector<int>& nums,int si,int ei){
        if(si>ei)
            return NULL;
        int mid=(si+ei)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=sortedArrayToBST(nums,si,mid-1);
        root->right=sortedArrayToBST(nums,mid+1,ei);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
};
