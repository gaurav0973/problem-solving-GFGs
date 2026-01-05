class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int l=0;
        int r = k-1;
        int sum = 0;
        for(int i=0; i<=r; i++){
            sum+=arr[i];
        }
        int ans = INT_MIN;
        while(r<n){
            ans = max(ans, sum);
            sum = sum - arr[l] + arr[r+1];
            l++;
            r++;
        }
        return ans;
        
    }
};