class Solution {
  public:
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& visited, vector<int>& recStack) {
        visited[node] = 1;
        recStack[node] = 1;
        
        for(auto &it : adj[node]){
            if(visited[it] && recStack[it]){
                return true;
            }else{
                if(dfs(adj, it, visited, recStack))
                    return true;
            }
        }
        
        recStack[node] = 0; // Remove from recursion stack after exploring
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto &e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v); // directed graph
        }

        vector<int> visited(V, 0), recStack(V, 0);

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                if(dfs(adj, i, visited, recStack)) return true;
            }
        }
        return false;
    }
};
