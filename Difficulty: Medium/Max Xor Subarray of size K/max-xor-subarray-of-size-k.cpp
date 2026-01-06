class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        
        int currXOR = 0;
        
        // XOR of first window
        for(int i = 0; i < k; i++) {
            currXOR ^= arr[i];
        }
        
        int maxXOR = currXOR;
        
        // Slide the window
        for(int i = k; i < n; i++) {
            currXOR ^= arr[i - k];  // remove left element
            currXOR ^= arr[i];      // add new right element
            
            maxXOR = max(maxXOR, currXOR);
        }
        
        return maxXOR;
    }
};
