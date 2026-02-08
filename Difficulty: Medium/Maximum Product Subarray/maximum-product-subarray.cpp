
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        int ans = -1e9;
        int n = arr.size();
        int prefix = 1;
        for(int i=0; i<n; i++){
            prefix = prefix * arr[i];
            ans = max(ans, prefix);
            if(prefix == 0)
                prefix = 1;
        }
        
        
        int suffix = 1;
        for(int i=n-1; i>=0; i--){
            suffix = suffix * arr[i];
            ans = max(ans, suffix);
            if(suffix == 0)
                suffix = 1;
        }
        
        
        return ans;
    }
};

