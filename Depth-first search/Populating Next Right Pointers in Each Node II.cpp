class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        queue<Node*> pendingNodes;
        pendingNodes.push(root);
        Node *current=NULL;
        while(!pendingNodes.empty()){
            Node *prev=NULL;
            int size=pendingNodes.size();
            while(size--){
                current=pendingNodes.front();
                pendingNodes.pop();
                if(prev)
                    prev->next=current;
                prev=current;
                if(current->left)
                    pendingNodes.push(current->left);
                if(current->right)
                    pendingNodes.push(current->right);
            }
        }
        return root;
    }
};
