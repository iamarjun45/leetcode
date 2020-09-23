class BSTIterator {
    vector<int> inorder_array;
    int curr;
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        inorder_array.push_back(root->val);
        inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
        curr=0;
    }
    
    int next() {
        int ans=inorder_array[curr++];
        return ans;
    }
    
    bool hasNext() {
        if(curr==inorder_array.size())
            return false;
        return true;
    }
};

