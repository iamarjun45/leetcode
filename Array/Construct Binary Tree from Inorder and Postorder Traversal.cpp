class Solution {
    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder,int is,int ie,int ps,int pe){
        if(is>ie || ps>pe)
            return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int i=is;
        while(i<=ie){
            if(inorder[i]==postorder[pe])
                break;
            i++;
        }
        root->left=buildTree(inorder,postorder,is,i-1,ps,i-1-is+ps);
        root->right=buildTree(inorder,postorder,i+1,ie,i-is+ps,pe-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};
