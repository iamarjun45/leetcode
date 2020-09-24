class Solution {
    int countleft(TreeNode* root){
        int count=0;
        while(root){
            root=root->left;
            count++;
        }
        return count;
    }
    int countright(TreeNode* root){
        int count=0;
        while(root){
            root=root->right;
            count++;
        }
        return count;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int countLeft=countleft(root);
        int countRight=countright(root);
        if(countLeft==countRight)
            return (1<<countLeft)-1;
        else
            return 1+countNodes(root->left)+countNodes(root->right);
    }
};
