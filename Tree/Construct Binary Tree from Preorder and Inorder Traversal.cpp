class Solution {
    TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder,int ps,int pe,int is,int ie){
        if(ps>pe || is>ie)
            return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int i=is;
        while(i<=ie){
            if(inorder[i]==preorder[ps])
                break;
            i++;
        }
        root->left=buildTree(preorder,inorder,ps+1,i-is+ps,is,i-1);
        root->right=buildTree(preorder,inorder,i-is+ps+1,pe,i+1,ie);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};


