class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        root->next=NULL;
        root->left=connect(root->left);
        root->right=connect(root->right);
        Node* left=root->left;
        Node* right=root->right;
        while(left!=NULL && right!=NULL){
            left->next=right;
            left=(left->right ? left->right : left->left);
            right=(right->left ? right->left : right->right);
        }
        return root;
    }
};

