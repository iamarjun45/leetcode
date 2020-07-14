class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Creating the graph between edges
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(make_pair(edges[i][1],succProb[i]));
            graph[edges[i][1]].push_back(make_pair(edges[i][0],succProb[i]));
        }
        // Distance array to store the distance of all the vertices from the start node
        vector<double> distance(n,0);
        // Visited Array
        vector<bool> visited(n,0);
        // Priority queue to prioritise the maximum distance vertex
        priority_queue<pair<double,int> > pq;
        // We should always start traversing from "start"
        pq.push({1.0,start});
        distance[start]=1.0;
        while(pq.size()!=0){
            int maxVertex=pq.top().second;
            pq.pop();
            // Already Visited
            if(visited[maxVertex])
                continue;
            // Mark it as visited
            visited[maxVertex]=true;
            for(auto x:graph[maxVertex]){
                // Distance is less. Please include the following edge and change value of distance
                if(distance[x.first]<distance[maxVertex]*x.second){
                    distance[x.first]=distance[maxVertex]*x.second;
                    pq.push({distance[x.first],x.first});
                }
            }
        }
        return distance[end];
    }
};
