
class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        if (m == 0 || a.size() < m) 
            return 0;
        
        sort(a.begin(), a.end());
        
        int minDiff = INT_MAX;
        int n = a.size();
        
        for (int i = 0; i + m - 1 < n; i++) {
            int diff = a[i + m - 1] - a[i];
            if (diff < minDiff) {
                minDiff = diff;
            }
        }
        
        return minDiff;
    }
};