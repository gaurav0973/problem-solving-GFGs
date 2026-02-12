class Solution {
public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();
        
        // Binary search range
        long long left = *min_element(arr.begin(), arr.end());
        long long right = *max_element(arr.begin(), arr.end()) + k;
        long long ans = left;
        
        // Helper function to check if we can achieve minimum height 'target'
        auto canAchieve = [&](long long target) -> bool {
            // prefix sum array to track total increments at each position
            vector<long long> heights(arr.begin(), arr.end());
            vector<long long> diff(n + 1, 0);
            long long operations = 0;
            long long currentIncrement = 0;
            
            for (int i = 0; i < n; i++) {
                // Remove expired increments
                if (i >= w) {
                    currentIncrement -= diff[i - w];
                }
                
                // Current height after previous increments
                long long currentHeight = heights[i] + currentIncrement;
                
                // If current height is less than target, we need to water here
                if (currentHeight < target) {
                    long long needed = target - currentHeight;
                    operations += needed;
                    
                    // If operations exceed k, impossible
                    if (operations > k) return false;
                    
                    // Add increment at current position
                    diff[i] += needed;
                    currentIncrement += needed;
                }
            }
            
            return operations <= k;
        };
        
        // Binary search
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            if (canAchieve(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};