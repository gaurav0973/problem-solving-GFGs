class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<P; i++){
            int u = prerequisites[i].second;
            int v = prerequisites[i].first;
            adj[u].push_back(v);
        }
        vector<int> indegree(N, 0);
        for(int i=0; i<P; i++){
            int v = prerequisites[i].first;
            indegree[v]++;
        }
        
        queue<int> q;
        for(int i = 0; i < N; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        while(q.size()){
            int u = q.front();
            q.pop();
            count++;
            
            for(auto v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }
        return count == N;
    }
};