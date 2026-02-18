// User function Template for C++

class Solution {
  public:
    void dfs(unordered_map<int, vector<int>> &adj, int u, vector<int> &visited){
        visited[u] = 1;
        
        for(int &v: adj[u]){
            if(!visited[v]){
                dfs(adj, v, visited);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j] == 1)
                    graph[i].push_back(j);
            }
        }
        vector<int> visited(V,0);
        int cnt = 0;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                cnt++;
                dfs(graph, i, visited);
            }
        }  
        return cnt;
    }
};