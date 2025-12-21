class Solution {
public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        
        for (auto& q : queries) {
            int l = q[0], r = q[1], x = q[2];
            
            // Find first occurrence of x in the whole array
            int firstX = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            
            // Find last occurrence of x in the whole array
            int lastX = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
            
            // If x is not present in array at all
            if (firstX >= arr.size() || arr[firstX] != x) {
                result.push_back(0);
                continue;
            }
            
            // Overlap of [firstX, lastX] with [l, r]
            int start = max(firstX, l);
            int end = min(lastX, r);
            
            if (start <= end) {
                result.push_back(end - start + 1);
            } else {
                result.push_back(0);
            }
        }
        
        return result;
    }
};