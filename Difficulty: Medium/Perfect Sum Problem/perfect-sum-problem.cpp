class Solution {
  public:
    unordered_map<string, int> f;
    int solve(vector<int> &arr, int idx, int k){
        if(k < 0)
            return 0;
        if(idx < 0)
            return (k == 0);
        
        string key=to_string(idx)+"_"+to_string(k);
        if(f.find(key) != f.end())
            return f[key];
        int notTake = solve(arr, idx - 1, k);
        int take = solve(arr, idx - 1, k - arr[idx]);

        return f[key] = take + notTake;
    }
    int perfectSum(vector<int>& arr, int k) {
        f.clear(); 
        return solve(arr, arr.size() - 1, k);
        
    }
};