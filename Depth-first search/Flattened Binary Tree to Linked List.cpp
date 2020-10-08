class Solution {
public:
    void flatten(TreeNode* root) {
        // Base Case
        if(root==NULL) return;
        // Flatten Left
        flatten(root->left);
        // Flatten Right
        flatten(root->right);
        // Flattened Left Tree
        TreeNode *l=root->left;
        // Flattened Right Tree
        TreeNode *r=root->right;
        // Replace the right with flattened left tree
        root->right=l;
        TreeNode *temp=root;
        // Find the node where the left tree end
        while(temp->right)
            temp=temp->right;
        // Attach the flattened right tree to the leaf node of flattened left tree
        temp->right=r;
        // Make the left part empty
        root->left=NULL;
    }
};
