class Solution {
    TreeNode* createTree(TreeNode* root,int add){
        if(root==NULL)
            return NULL;
        TreeNode* newNode=new TreeNode(root->val+add);
        newNode->left=createTree(root->left,add);
        newNode->right=createTree(root->right,add);
        return newNode;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return vector<TreeNode*>();
        vector<TreeNode*> dp[n+1];
        dp[0].push_back(NULL);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                for(int k=0;k<dp[j-1].size();k++){
                    for(int l=0;l<dp[i-j].size();l++){
                        TreeNode* newNode=new TreeNode(j);
                        newNode->left=createTree(dp[j-1][k],0);
                        newNode->right=createTree(dp[i-j][l],j);
                        dp[i].push_back(newNode);
                    }
                }
            }
        }
        return dp[n];
    }
};
