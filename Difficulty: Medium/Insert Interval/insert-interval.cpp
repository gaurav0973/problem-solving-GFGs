class Solution {
  public:
    vector<vector<int>> mergeInterval(vector<vector<int>> &intervals){
        vector<vector<int>> ans;
        int n = intervals.size();
        int s1 = intervals[0][0];
        int e1 = intervals[0][1];
        for(int i=1; i<n; i++){
            int s2 = intervals[i][0];
            int e2 = intervals[i][1];
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
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,vector<int> &newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        bool inserted = false;
        for(int i=0; i<n; i++){
            int startTime = intervals[i][0];
            if(!inserted && startTime >= newInterval[0]){
                ans.push_back(newInterval);
                inserted = true;
            }
            ans.push_back(intervals[i]);
        }
        if(!inserted){
            ans.push_back(newInterval);
        }
        
        return mergeInterval(ans);
        
    }
};