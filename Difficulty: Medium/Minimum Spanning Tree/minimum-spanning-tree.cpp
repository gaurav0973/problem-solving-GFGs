class Solution {
public:
    typedef pair<int,int> P;
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<vector<P>> adj(V);
        for(auto &temp : edges){
            int u = temp[0];
            int v = temp[1];
            int w = temp[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        
        vector<bool> inMST(V, false);
        int sum = 0;
        
        while(!pq.empty()){
            auto tmp = pq.top();
            pq.pop();
            
            int wt = tmp.first;
            int node = tmp.second;
            
            if(inMST[node])
                continue;
                
            sum += wt;
            inMST[node] = true;
            
            for(auto &it : adj[node]){
                int v = it.first;
                int w = it.second;
                
                if(!inMST[v]){
                    pq.push({w, v});
                }
            }
        }
        
        return sum;
    }
};