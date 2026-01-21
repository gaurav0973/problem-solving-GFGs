class Solution {
  public:
    vector<string> findPermutation(string &s) {
        int n = s.size();
        sort(s.begin(), s.end());
        vector<string> ans;
        vector<bool> visited(n,false);
        string str = "";
        solve(0, str, ans,n, s, visited);
        return ans;
    }
    
    void solve(int idx, string &str, vector<string> &ans, int n, string &s, vector<bool> &visited){
        if(idx == n){
            ans.push_back(str);
            return;
        }
        
        for(int i=0; i<n; i++){
            
            // visited
            if(visited[i])
                continue;
            
            // duplicate
            if(i>0 && s[i] == s[i-1] && !visited[i-1])
                continue;
            
            visited[i] = true;
            str.push_back(s[i]);
            
            solve(idx+1, str, ans,n, s, visited);
            
            visited[i] = false;
            str.pop_back();
        }
    }
};
