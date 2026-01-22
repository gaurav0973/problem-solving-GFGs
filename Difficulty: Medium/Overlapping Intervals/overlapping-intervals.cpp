class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        auto lambda = [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        };
        sort(arr.begin(),arr.end(), lambda);
        int s1 = arr[0][0];
        int e1 = arr[0][1];
        vector<vector<int>> ans;
        for(int i=1; i<n; i++){
            int s2 = arr[i][0];
            int e2 = arr[i][1];
            if(e1 >= s2){
                s1 = s1;
                e1 = max(e1, e2);
                continue;
            }
            ans.push_back({s1, e1});
            s1 = s2;
            e1 = e2;
        }
        ans.push_back({s1, e1});
        return ans;
    }
};