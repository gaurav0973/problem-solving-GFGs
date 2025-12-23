class Solution {
public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // Sort the array - O(n log n)
        sort(arr.begin(), arr.end());
        
        vector<int> result;
        result.reserve(queries.size()); // Pre-allocate memory for efficiency
        
        // Process each query - O(q log n)
        for (const auto &query : queries) {
            int a = query[0];
            int b = query[1];
            
            // Find first position where element >= a
            auto left = lower_bound(arr.begin(), arr.end(), a);
            
            // Find first position where element > b
            auto right = upper_bound(arr.begin(), arr.end(), b);
            
            // Count elements in range [a, b]
            int count = distance(left, right);
            result.push_back(count);
        }
        
        return result;
    }
};