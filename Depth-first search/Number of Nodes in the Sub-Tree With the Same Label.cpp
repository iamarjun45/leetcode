class Solution {
	vector<vector<int>> graph;
	string label;
	vector<bool> visited;
	vector<int> ans;
    vector<int> dfs(int start){
    	// Mark me as visited
        visited[start]=true;
        // Store the frequency of me and my subtree
        vector<int> freq(26,0);
        // Add me to freq
        freq[label[start]-'a']++;
        for(auto x:graph[start]){
        	// If not visited,
            if(!visited[x]){
            	// Traverse
                vector<int> small=dfs(x);
                // Add to frequency
                for(int i=0;i<26;i++){
                    freq[i]=freq[i]+small[i];
                }
            }
        }
        // Now answer for that node would be total frequency of its label
        ans[start]=freq[label[start]-'a'];
        return freq;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    	// Initializing Graph
        graph=vector<vector<int>>(n);
        // Creating undirected graph from edges
        for(auto x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        // Initializing ans vector
        ans=vector<int>(n,0);
        // Initializing visited vector
        visited=vector<bool>(n,0);
        label=labels;
        // small will contain the frequency of every character in the tree
        vector<int> small=dfs(0);
        return ans;
    }
};
