
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        if(n==0)
            return ans;
        
        // sort by start time
        auto lambda = [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        };
        sort(arr.begin(),arr.end(), lambda);
        
        int prevStart = arr[0][0];
        int prevEnd = arr[0][1];
        for(int i=1; i<n; i++){
            int currStart = arr[i][0];
            int currEnd = arr[i][1];
            // overlapping
            if(currStart <= prevEnd){
                prevStart = min(prevStart, currStart);
                prevEnd = max(prevEnd, currEnd);
            }
            else{
                ans.push_back({prevStart, prevEnd});
                prevStart = currStart;
                prevEnd = currEnd;
            }
        }
        ans.push_back({prevStart, prevEnd});
        return ans;
    }
};

